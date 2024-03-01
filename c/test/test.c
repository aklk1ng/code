#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_EXCHANGES 1000000

int f() {
  int pipe1[2], pipe2[2];
  char buf;
  struct timeval start, end;
  double elapsed_time;

  // Create two pipes
  if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {
    perror("pipe");
    return 1;
  }

  // Fork a child process
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {    // Child process
    close(pipe1[1]); // Close write end of pipe1
    close(pipe2[0]); // Close read end of pipe2

    for (int i = 0; i < NUM_EXCHANGES; ++i) {
      read(pipe1[0], &buf, 1);  // Read from pipe1
      write(pipe2[1], &buf, 1); // Write to pipe2
    }

    close(pipe1[0]);
    close(pipe2[1]);
  } else {           // Parent process
    close(pipe1[0]); // Close read end of pipe1
    close(pipe2[1]); // Close write end of pipe2

    gettimeofday(&start, NULL);

    for (int i = 0; i < NUM_EXCHANGES; ++i) {
      write(pipe1[1], &buf, 1); // Write to pipe1
      read(pipe2[0], &buf, 1);  // Read from pipe2
    }

    gettimeofday(&end, NULL);

    close(pipe1[1]);
    close(pipe2[0]);

    elapsed_time =
        (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Performance: %.2f exchanges per second\n",
           NUM_EXCHANGES / elapsed_time);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  f();
  int pid = fork();
  int p1[2], p2[2];
  pipe(p1);
  pipe(p2);
  char buf;
  if (pid == 0) {
    close(p1[1]);
    close(p2[0]);

    read(p1[0], &buf, 1);
    write(p2[1], &buf, 1);

    close(p1[0]);
    close(p2[1]);
  } else {
    close(p1[0]);
    close(p2[1]);

    write(p1[1], &buf, 1);
    read(p2[0], &buf, 1);

    close(p1[1]);
    close(p2[0]);
  }
  return 0;
}
