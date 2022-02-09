#include <stdio.h>
//#define name "NAME"
//#define cash "XXX.XX"
int main(void)
{ 
  char name[40] = "NAME";
  char cash[] = "xxx.xx";   
  printf("The %s family just may be $%.2f dollars richer!\n", name, cash);
  getchar();
  return 0;
}
