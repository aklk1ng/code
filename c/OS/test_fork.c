#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  if ((pid = fork()) == 0) {
    printf("the fork function's result in fork thread:%d\n", pid);
    printf("the fork thread:%d\n", getpid());
  } else {
    printf("the main thread:%d\n", getpid());
  }
  return 0;
}
