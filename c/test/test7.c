// 求两数最大公约数
#include <stdio.h>
int main() {
  int m = 0;
  int n = 0;
  scanf("%d %d", &m, &n);
  int t = 0;
  // if (m > n)
  // {
  //     max = n;
  // }
  // else
  // {
  //     max = m;
  // }
  // while (1)
  // {
  //     if (m % max == 0 && n % max == 0)
  //     {
  //         printf("最大公约数为:%d\n", max);
  //         break;
  //     }
  //     max--;
  // }

  // 辗转相除法求最大公约数
  // 最小公倍数 = m*n/最大公约数
  while ((t = m % n)) {
    m = n;
    n = t;
  }
  printf("%d\n", n);
  return 0;
}
