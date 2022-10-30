#include <stdio.h>
void test()
{
    static int a = 1; //static修饰局部变量，使得局部变量不在直接销毁（本质是改变了局部变量的生命周期），变量
    a++;              // 由栈区移动到了静态区
    printf("%d ", a);
}
int main ()
{
int i =0;
  while (i < 10)
  {
     test();
     i++;
  } 
return 0;
}