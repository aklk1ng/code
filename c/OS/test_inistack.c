#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  int count = argc;
  for (int i = 0; i < count; i++) {
    if (argv[i]) {
      printf("  argv:%2s\n", argv[i]);
    }
  }
  argv++;
  printf("  envp:%2s\n", *argv);
  return 0;
}
