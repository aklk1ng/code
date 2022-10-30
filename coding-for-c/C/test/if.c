// #include <stdio.h>
// int main(void)
// {
//     int choice = 0;
//     printf("Wouldyou want to join us?(1/else)\n");
//     scanf("%d", &choice);
//     if (choice == 1)
//       printf("OK!Welcome!\n");
//     else
//       printf("Thanks!\n");  
//     return 0;
// }


// #include <stdio.h>
// int main ()
// {
//   int age = 50;
//   if(age<18)
//   printf("1\n");
//   else if (age>=18 && age<=26) // && 表示并且关系
//   printf("2");
//   else                     //else与最近的if匹配
//   printf("3");

//   return 0;
// }
#include <stdio.h>
int main ()
{
  int i = 0;
  while (i <= 100)
  {
    printf("%d\n", i);
    i+=2;
  }
  return 0;
}