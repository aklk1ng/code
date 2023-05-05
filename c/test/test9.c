// 打印100到200之间的素数
#include <math.h>
#include <stdio.h>
int main() {
  int i = 0;
  int count = 0;
  for (i = 101; i <= 200; i += 2) {
    // 判断素数  只能被1和它本身整除
    // 2->i-1之间的数字去试除i
    int j = 0;
    int flag = 1;
    for (j = 2; j <= sqrt(i); j++) { // sqrt - 开平方函数 - 头文件为math.h
      if (i % j == 0) {
        flag = 0; // 不是素数
        break;
      }
    }
    if (flag == 1) {
      count++;
      printf("%d ", i); // 素数
    }
  }
  printf("\n%d\n", count);
  return 0;
}
