#include <stdio.h>

int main(int argc, char *argv[]) {
  extern char **environ;
  for (char **env = environ; *env; env++) {
    printf("%s\n", *env);
  }
  return 0;
}
