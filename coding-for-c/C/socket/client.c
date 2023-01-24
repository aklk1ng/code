#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
int main (int argc, char *argv[])
{
    //1. create the listening socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return -1;
    }
    //2. connect server IP port
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    inet_pton(AF_INET, "192.168.251.82", &saddr.sin_addr.s_addr);
    int ret = connect(fd, (struct sockaddr*)&saddr, sizeof(saddr));
    if (ret == -1) {
        perror("connect");
        return -1;
    }
    //3. communicate
    int number = 0; 
    while (1) {
        // send data 
        char buf[1024];
        sprintf(buf, "hello world, %d ...\n",number);
        number++;
        send(fd, buf, strlen(buf)+1, 0);

        // receive data
        memset(buf, 0, sizeof(buf));
        int len = recv(fd, buf, sizeof(buf), 0);
        if (len > 0) {
            printf("server say: %s\n", buf);
        } else if (len == 0) {
            printf("the server disconnect...\n");
            break;
        } else {
            perror("recv");
            break;
        }
        sleep(1);
    }
    // close file descriptor
    close(fd);
    return 0;
}
