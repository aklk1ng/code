#include <stdio.h>
int main(void) {
  int a = 1;
  int b = 3;
  int c = 5;
  //       a=4        c=14       b=5
  int d =
      (a = b + 1, c = a + 10,
       b = a + 1); // exp1，exp2，exp3，....逗号表达式从括号内从左往右以此计算，以最后的表达式为结果
  printf("%d", d);
  return 0;
}
