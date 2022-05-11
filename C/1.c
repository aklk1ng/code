// #include <stdio.h>
// int MAX(int a, int b)
// {
//     // if (a > b)
//     // return a;
//     // else
//     // return b;
//     return (a>b ? a : b);
// }
// int main (void)
// {
//     int x = 0;
//     int y = 0;
//     scanf("%d %d", &x, &y);
//     int m = MAX(x, y);
//     printf("%d\n", m);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int a=1;
//     char* p = (char*)&a;
//     if (*p==1)
//     {
//         printf("xiaoduan\n");
//     }
//     else
//     {
//         printf("daduan\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char ch;
//     scanf("%c", &ch);
//     while (ch != 'g')
//     {
//         printf("%c", ch);
//         scanf("%c", &ch);
//     }
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     char ch;
//     scanf("%c", &ch);
//     do
//     {
//         scanf("%c", &ch);
//         printf("%c", ch);
//     } while (ch != 'g');
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char ch;
//     scanf("%c", &ch);
//     for (ch = '$';ch != 'g';scanf("%c", &ch))
//     {
//         printf("%c", ch);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int k;
//     for (k=1,printf("%d: hi\n", k);printf("k = %d\n", k),
//     k*k<26;k+=2,printf("Now k is %d\n", k))
//     {
//         printf("k is %d in the loop\n", k);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     char arr[]="abcdefghijklmnopqrstuvwxyz";
//     for (i = 0;i<24;i++)
//     {
//         printf("%c ", arr[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int j =0;
//     for (i=1;i<=5;i++)
//     {
//         for (j=1;j<=i;j++)
//         {
//             printf("$");
//         }
//         printf("\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     char m = 'F';
//     int i = 0;
//     int j = 0;
//     for (i=0;i<6;i++)
//     {
//         for (j=0;j<=i;j++)
//         {
//             printf("%c", m-j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char m = 'A';
//     int i = 0;
//     int j = 0;
//     int n = 0;
//     for (i=0;i<6;i++)
//     {
//         for (j = 0;j<=i;j++)
//         {
//             printf("%c", m+n+j);
//         }
//         n++;
//         printf("\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     char ch;
//     while ((ch = getchar()) != '#')
//     {
//         if (ch == '\n')
//             continue;
//         printf("Step 1\n");
//         if (ch == 'c')
//             continue;
//         else if (ch == 'b')
//         break;
//         else if (ch == 'h')
//         goto laststep;
//         printf("Step 2\n");
//         laststep: printf("Step 3\n");
//     }
//     printf("Done\n");
//     return 0;
// }


// #include <stdio.h>
// int main()
// {
//     char ch;
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     while ((ch = getchar()) != '#')
//     {
//         if (ch == ' ')
//         a++;     //统计空格字符
//         else if (ch == '\n')
//         b++;     //统计换行符
//         else
//         c++;     //统计其他字符
//     }
//     printf("%d\n%d\n%d\n", a,b,c);
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char ch;
//     int count;
//     while ((ch = getchar()) != '#')
//     {
//         printf("%c-%d  ", ch,ch);
//         count++;
//         if (count%8==0)
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int n;
//     int evencount = 0;
//     int oldcount = 0;
//     float oldsum = 0;
//     float evensum = 0;
//     while (1)
//     {
//         scanf("%d", &n);
//         if (n == 0)
//         {
//             break;
//         }
//         else if (n%2==0)
//         {
//             evencount++;
//             evensum += n;
//         }
//         else
//         {
//             oldcount++;
//             oldsum += n;
//         }
//     }
//     printf("偶数个数:%d\n", evencount);
//     printf("奇数个数:%d\n", oldcount);
//     printf("%.2f\n%.2f\n", evensum,oldsum);
//     printf("%.2f   %.2f", evensum/(oldcount+evencount), oldsum/(oldcount+evencount));
// }


// #include <stdio.h>
// int main()
// {
//     //判断一个数是否为素数
//     int n = 0;
//     int goal;
//     test: scanf("%d", &goal);
//     if (goal > 0)
//     {
//     for (n=2;n<=goal;n++)
//     {
//         if (goal % n == 0)
//         {
//             printf("%d\n", goal);
//             printf("不是素数\n");
//             break;
//         }
//         else
//         {
//             printf("%d", goal);
//             printf("是素数\n");
//         }
//      }
//     }
//     else{
//         printf("请重新输入:");
//         goto test;
//     }
//     return 0;
// }


//指针的运算
// #include <stdio.h>
// int main()
// {
//     int data[2]={100,200};
//     int moredata[2]={300,400};
//     int *p1,*p2,*p3;
//     p1=p2=data;
//     p3=moredata;
//     printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1,*p2,*p3);
//     printf("*p++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++,*++p2,(*p3)++);
//     printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1,*p2,*p3);
//     return 0;
// }

// #include<stdio.h>
// char* pr(char* str)
// {
//     char* pc;
//     pc=str;
//     while(*pc)
//         putchar(*pc++);
//     do{
//         putchar(*pc--);
//     }while(pc-str);
//     return (pc);
// }
// int main()
// {
//     char* x=pr("ho ho ho!");
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     char str1[]="gawsie";
//     char str2[]="bletonism";
//     char* ps;
//     int i=0;
//     for(ps=str1;*ps!='\0';ps++){
//         if(*ps=='a'||*ps=='e'){
//             putchar(*ps);
//         }
//         else{
//             (*ps)--;
//         }
//         putchar(*ps);
//     }
//     putchar('\n');
//     while (str2[i]!='\0'){
//         printf("%c", i%3?str2[i]:'*');
//         ++i;
//     }
//     return 0;
// }


//c primer plus字符串函数的练习
// #include<stdio.h>
// #include<string.h>
// void menu()
// {
//     printf("*****************************\n");
//     printf("*  1.print  2.print_ASCII  **\n");
//     printf("*  3.print_lh  4.print_fstlh \n");
//     printf("**         0.quit    ********\n");
//     printf("*****************************\n");
//     printf("*****************************\n");
// }
// void Print(char* str)
// {
//     while(*str!='\0'){
//         printf("%c", *str);
//         str++;
//     }
// }
// void Print_ASCII(char* str,int n)
// {
//     int i=0;
//     int j=0;
//     for(i=0;i<n;i++){
//         for(j=i;j<=n-1;j++){
//             if(*str>*(str+1)){
//                 char* tmp=str;
//                 *str=*(str+1);
//                 *(str+1)=*tmp;
//             }
//         }
//         puts(*(str+i));
//     }
// }
// int main()
// {
//     int choice = 0;
//     do{
//         menu();
//         char str[]={0};
//         int count = 0;
//         printf("请输入字符串:>");
//         while (scanf("%s", str)==1&&count<=10){
//             if (*str==EOF){
//                 break;
//             }
//             else{
//                 count++;
//             }
//         }
//         printf("请输入数字功能:>");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//         Print(str);
//             break;
//         case 2:
//         Print_ASCII(str,count);
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
//         default:
//         printf("请重新输入数字:>");
//             break;
//         }
//     }while(choice);
//     return 0;
// }

#include<stdio.h>
int main()
{
    int arr1[]={1,2,3};
    int arr2[][3]={1,2,3,4,5,6};
    int *p=NULL;
    p=arr1;
    printf("%p ", p);
    p=&arr1;
    printf("%p ", p);
    p=&arr2;
    printf("%p ", p);
    p=arr2;
    printf("%p ", p);
    return 0;
}