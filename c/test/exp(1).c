#include <stdio.h>
int main(void) {
  int a = 3;
  int b = 0;
  int max;
  // if (a > b)
  //    printf("%d", a);
  // else
  max = a > b ? a : b; // 与上述语句等效
  printf("%d", max);   // exp1 ? exp2 : exp3（条件操作符/三目操作符）
                     // exp成立择计算exp2的结果，反之计算exp3的结果 等同于选择语句
  return 0;
}
