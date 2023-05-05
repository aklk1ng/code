#include <stdio.h>

void test(int num) {
  int i;
  for (i = 2; i <= num - 1; i++) {
    if (num % i == 0)
      break;
  }
  if (i == num) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}
int main(int argc, char *argv[]) {
  int num = 0;
  scanf("%d", &num);
  test(num);
  return 0;
}
