// #include <stdio.h>
// int main(void) //void--无或空的意思
// {
//     // int i = 0;
//     // int arr[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9  };
//     // while (i <= 5)              //循环打印
//     // {
//     // printf("%d\n", arr[i]);
//     // i++;
//     // }
//     int a = -1;
//     int b = a >> 1;
//     printf("%d", b);
//     return 0;
// }

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// int main()
// {
//     int ret=rand();
//     srand((unsigned int)time(NULL));
//     printf("%d\n",ret);
// }

// #include<stdio.h>
// char* MySort(char* arr,int size)
// {
//     int i=0;
//     int j=0;
//     for(i=0;i<size-2;i++){
//         for(j=i+1;j<size-1;j++){
//             if(arr[i]>arr[j]){
//                 char tmp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=tmp;
//             }
//         }
//     }
//     return arr;
// }
// int main()
// {
//     char* str;
//     char arr[]={0};
//     scanf("%s",arr);
//     int size=sizeof(arr)/sizeof(arr[0]);
//     str=MySort(arr,size);
//     while(*str){
//         printf("%s", *str);
//     }
// }

// 模拟实现strcat函数
//  #include<stdio.h>
//  char* Mystrcat(char* arr,char* arr2)
//  {
//      char* dest=arr;
//      while(*arr)
//      {
//          arr++;
//      }
//      while(*arr++=*arr2++){
//          ;
//      }
//      return dest;
//  }
//  int main()
//  {
//      int i=0;
//      char arr[20]="adc";
//      char arr2[]="xcf";
//      char* str=Mystrcat(arr,arr2);
//      for(i=0;i<6;i++){
//          printf("%c ", *(str+i));
//      }
//  }

// 模拟实现strcmp函数
//  #include<stdio.h>
//  int Mystrcmp(char* arr,char* arr2)
//  {
//      while(*arr==*arr2){
//          arr++;
//          arr2++;
//      }
//      return *arr-*arr2;
//  }
//  int main()
//  {
//      char arr[]={0};
//      char arr2[]={0};
//      scanf("%s",arr);
//      scanf("%s",arr2);
//      int ret=Mystrcmp(arr,arr2);
//      if(ret>0){
//          printf(">\n");
//      }
//      else if(ret<0){
//          printf("<\n");
//      }
//      else{
//          printf("=\n");
//      }
//      return 0;
//  }

// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// int main()
// {
//     int choice=1;
//     int goal=0;
//     srand((unsigned int)time(NULL));
//     goal=rand()%100+1;
//     // while(choice){
//     //     printf("请输入数字(0退出):>");
//     //     scanf("%d\n", &choice);
//     //     if(choice==goal){
//     //         printf("猜对了!\n");
//     //     }
//     //     else if(choice>goal){
//     //         printf("猜大了!\n");
//     //     }
//     //     else{
//     //         printf("猜小了!\n");
//     //     }
//     //}
//     do{
//         printf("请输入数字:>");
//         scanf("%d\n", &choice);
//         if(choice<goal){
//             printf("猜小了!\n");
//         }
//         else{
//             printf("猜大了!\n");
//         }
//     }while(choice!=goal);
//     printf("猜对了!\n");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game() {
  int goal = rand() % 100 + 1;
  int choice = 0;
  while (1) {
    printf("请输入数字:>");
    scanf("%d", &choice);
    if (choice < goal)
      printf("猜小了!\n");
    else if (choice > goal)
      printf("猜大了!\n");
    else {
      printf("猜对了!\n");
      break;
    }
  }
}
int main() {
  int input;
  srand((unsigned int)time(NULL));
  do {
    printf("请输入1开始游戏,0退出游戏:>");
    scanf("%d", &input);
    switch (input) {
    case 1:
      game();
      break;
    case 0:
      printf("See you soon!\n");
      break;
    default:
      printf("请重新输入数字!\n");
      break;
    }
  } while (input);
  return 0;
}
