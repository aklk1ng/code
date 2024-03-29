#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1) {
    perror("socket");
    exit(0);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(9999);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
  int ret = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    perror("connect");
    exit(0);
  }

  while (1) {
    char recvbuf[1024];
    fgets(recvbuf, sizeof(recvbuf), stdin);
    write(fd, recvbuf, strlen(recvbuf) + 1);
    read(fd, recvbuf, sizeof(recvbuf));
    printf("recv buf: %s\n", recvbuf);
    sleep(1);
  }

  close(fd);
  return 0;
}
