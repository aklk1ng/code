#include <arpa/inet.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/poll.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd == -1) {
    perror("socket");
    exit(0);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(9999);
  addr.sin_addr.s_addr = INADDR_ANY;
  int ret = bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
  if (ret == -1) {
    perror("bind");
    exit(0);
  }

  ret = listen(lfd, 100);
  if (ret == -1) {
    perror("listen");
    exit(0);
  }

  struct pollfd fds[1024];
  for (int i = 0; i < 1024; i++) {
    fds[i].fd = -1;
    fds[i].events = POLLIN;
  }
  fds[0].fd = lfd;

  int maxfd = 0;
  while (1) {
    ret = poll(fds, maxfd + 1, -1);
    if (ret == -1) {
      perror("select");
      exit(0);
    }

    if (fds[0].revents & POLLIN) {
      struct sockaddr_in sockcli;
      unsigned int len = sizeof(sockcli);

      int connfd = accept(lfd, (struct sockaddr *)&sockcli, &len);

      int i;
      for (i = 0; i < 1024; i++) {
        if (fds[i].fd == -1) {
          fds[i].fd = connfd;
          break;
        }
      }
      maxfd = i > maxfd ? i : maxfd;
    }

    for (int i = 1; i <= maxfd; i++) {
      if (fds[i].revents & POLLIN) {
        char buf[128];
        int ret = read(fds[i].fd, buf, sizeof(buf));
        if (ret == -1) {
          perror("read");
          exit(0);
        } else if (ret == 0) {
          printf("The client closed the connection...\n");
          close(fds[i].fd);
          fds[i].fd = -1;
        } else {
          printf("Client: %s\n", buf);
          write(fds[i].fd, buf, strlen(buf) + 1);
        }
      }
    }
  }
  close(lfd);
  return 0;
}
