#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<pthread.h>
//信息结构体
struct SockInfo {
    struct sockaddr_in addr;
    int fd;
};
struct SockInfo infos[512];
void* working(void* arg);

int main (int argc, char *argv[])
{
    //1.创建监听的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    //2.绑定本地的IP port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = INADDR_ANY;// 0 = 0,0,0,0 该宏定义自动读取本地网卡IP地址
    int ret = bind(fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    //3.设置监听
    ret = listen(fd, 128);
    if (ret == -1) {
        perror("listen");
        return -1;
    }
    //初始化结构体
    int max = sizeof(infos)/sizeof(infos[0]);
    for (int i = 0; i < max; i++) {
        bzero(&infos[i], sizeof(infos[i]));
        infos[i].fd = -1;
    }
    //4.阻塞并等待客户端的连接
    int addrlen = sizeof(struct sockaddr_in);
    while (1) {
        struct SockInfo* pinfo;
        for (int i = 0; i < max; i++) {
            if (infos[i].fd == -1) {
                pinfo = &infos[i];
                break;
            }
        }
        int cfd = accept(fd, (struct sockaddr*)&pinfo->addr, &addrlen);
        pinfo->fd = cfd;
        if (cfd == -1) {
            perror("accept");
            break;
        }
        //创建出一个子线程
        pthread_t tid;
        pthread_create(&tid, NULL, working, pinfo);
        pthread_detach(tid);
    }
    
    close(fd);
}
void* working(void* arg)
{
    struct SockInfo* pinfo = (struct SockInfo*)arg;
    int cfd = pinfo->fd;
    //连接建立成功，打印客户端的IP和端口信息
    char ip[32];
    printf("the client's IP: %s. port: %d\n", inet_ntop(AF_INET, &pinfo->addr.sin_addr, ip, sizeof(ip)), ntohs(pinfo->addr.sin_port));
    //5.通信
    while (1) {
        //接收数据 
        char buff[1024];
        int len = recv(cfd, buff, sizeof(buff), 0);
        if (len > 0) {
            printf("client say: %s\n", buff);
            send(cfd, buff, len, 0);
        }
        else if (len == 0) {
            printf("the client disconnect...\n");
            break;
        }
        else {
            perror("recv");
            break;
        }
    }
    //关闭文件描述符
    close(pinfo->fd);
    close(cfd);
    return 0;
}
