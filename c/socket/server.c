#include "threadpool.h"
#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
// the information structure
struct SockInfo {
    struct sockaddr_in addr;
    int fd;
};
typedef struct poolInfo {
    ThreadPool *p;
    int fd;
} PoolInfo;
void working(void *arg);
void accptConn(void *arg);

int main(int argc, char *argv[]) {
    // 1.create a listening socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    // 2.bind local IP port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr =
        INADDR_ANY; // 0 = 0,0,0,0 this macro automatically read the IP address
                    // of the local network card
    int ret = bind(fd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    // 3.set monitor
    ret = listen(fd, 128);
    if (ret == -1) {
        perror("listen");
        return -1;
    }
    // create the thread pool
    ThreadPool *pool = ThreadPoolCreate(3, 8, 100);
    PoolInfo *info = (PoolInfo *)malloc(sizeof(PoolInfo));
    info->p = pool;
    info->fd = fd;
    ThreadPoolAdd(pool, accptConn, info);
    ThreadExit(NULL);
    return 0;
}
void accptConn(void *arg) {
    PoolInfo *poolInfo = (PoolInfo *)arg;
    // 4. block and wait for client connection
    int addrlen = sizeof(struct sockaddr_in);
    while (1) {
        struct SockInfo *pinfo;
        pinfo = (struct SockInfo *)malloc(sizeof(struct SockInfo));
        pinfo->fd =
            accept(poolInfo->fd, (struct sockaddr *)&pinfo->addr, &addrlen);
        if (pinfo->fd == -1) {
            perror("accept");
            break;
        }
        // add communication tasks
        ThreadPoolAdd(poolInfo->p, working, pinfo);
    }

    close(poolInfo->fd);
}
void working(void *arg) {
    struct SockInfo *pinfo = (struct SockInfo *)arg;
    // connecting successfully, print the client IP and port information
    char ip[32];
    printf("the client's IP: %s. port: %d\n",
           inet_ntop(AF_INET, &pinfo->addr.sin_addr, ip, sizeof(ip)),
           ntohs(pinfo->addr.sin_port));
    // 5. communicate
    while (1) {
        // receive data
        char buf[1024];
        int len = recv(pinfo->fd, buf, sizeof(buf), 0);
        if (len > 0) {
            printf("client say: %s\n", buf);
            send(pinfo->fd, buf, len, 0);
        } else if (len == 0) {
            printf("the client disconnect...\n");
            break;
        } else {
            perror("recv");
            break;
        }
    }
    // close file descriptor
    close(pinfo->fd);
}
