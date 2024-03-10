#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exercise() {
  int p1[2], p2[2];
  pipe(p1);
  pipe(p2);
  char buf;
  if (fork() == 0) { // Child process
    // Close unused ends of the pipes
    close(p1[1]);
    close(p2[0]);

    // Read from p1 and write to p2
    while (read(p1[0], &buf, 1) > 0) {
      write(p2[1], &buf, 1);
    }

    // Close remaining ends of the pipes
    close(p1[0]);
    close(p2[1]);
  } else { // Parent process
    // Close unused ends of the pipes
    close(p1[0]);
    close(p2[1]);

    // Write to p1 and read from p2
    for (char c = 'A'; c <= 'Z'; ++c) {
      write(p1[1], &c, 1);
      if (read(p2[0], &buf, 1) > 0) {
        printf("Received: %c\n", buf);
      }
    }

    // Close remaining ends of the pipes
    close(p1[1]);
    close(p2[0]);
  }
}

void f() {
  int p[2];
  pipe(p);
  char *buf = malloc(sizeof(char) * 20);
  if (fork() == 0) {
    close(0);
    // stdin(0) <------------> p[1]
    dup(p[0]);
    close(p[0]);
    close(p[1]);

    read(0, buf, 12);
    printf("%s\n", buf);
  } else {
    write(p[1], "hello world\n", 12);

    close(p[0]);
    close(p[1]);
  }
}

int main(int argc, char *argv[]) {
  exercise();
  return 0;
}
