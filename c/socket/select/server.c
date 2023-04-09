#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // create listen file descriptor
  int lfd = socket(AF_INET, SOCK_STREAM, 0);

  // bind
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(10000);
  addr.sin_addr.s_addr = INADDR_ANY;
  int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    perror("bind");
    return -1;
  }

  // begin to listen
  listen(lfd, 128);

  int maxfd = lfd;

  fd_set rdset;
  fd_set rdtmp;
  FD_ZERO(&rdset);

  FD_SET(lfd, &rdset);

  while (1) {
    rdtmp = rdset;
    int num = select(maxfd + 1, &rdtmp, NULL, NULL, NULL);
    if (FD_ISSET(lfd, &rdtmp)) {
      struct sockaddr_in cliaddr;
      unsigned int clilen = sizeof(cliaddr);
      int cfd = accept(lfd, (struct sockaddr *)&cliaddr, &clilen);
      FD_SET(cfd, &rdset);

      maxfd = cfd > maxfd ? cfd : maxfd;
    }

    for (int i = 0; i < maxfd + 1; i++) {
      if (i != lfd && FD_ISSET(i, &rdtmp)) {
        char buf[10] = {0};
        int len = read(i, buf, sizeof(buf));
        if (len == 0) {
          printf("The client closed the connection..\n");
          FD_CLR(i, &rdset);
          close(i);
        } else if (len > 0) {
          write(i, buf, strlen(buf) + 1);
        } else {
          perror("read");
        }
      }
    }
  }
  return 0;
}
