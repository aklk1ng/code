#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char input[20] = {0};
  system("shutdown -s -t 60");
  while (1) {
    printf("电脑一分钟后关机\n");
    scanf("%s", input);
    if (strcmp(input, "haha") == 0) {
      system("shutdown -a");
      break;
    }
  }

  return 0;
}
