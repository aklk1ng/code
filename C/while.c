// #include <stdio.h>
// int main (void)
// {
//   int line;
//   while (line<30000)
//   {
//     printf("coding:%d!\n", line);
//     line++;
//   }
//   if (line == 30000)
//    {
//     printf("offer!\n");
//    }   
//   return 0;
// }
// #include <stdio.h>
// int main ()
// {
//   int ch = 0;
//   while ((ch = getchar()) != EOF)
//   {
//   putchar(ch);
//   }
//   return 0;
//}
#include <stdio.h>
int main ()
{
  int password[40] = {0};
    printf("Please enter your password:\n");
    scanf("%s", password);
    printf("Please confirm your choice:(Y/N)\n");
    int abc = 0;
    while ((abc = getchar()) != '\n')
        {
          ;
        }
    int ch = getchar();
    if (ch == 'Y')
        {
         printf("OK!\n");
        }
    else
        {
          printf("Sorry!\n");
        } 
  return 0;
}