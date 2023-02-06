#include <stdio.h>
#include <string.h>
int main()
{
    char password[20] = {0};
    int i = 0;
    for (i = 0; i <3; i++)
    { 
        printf("请输入密码: ");
        scanf("%d", password);
        if (strcmp(password, "123") == 0)//字符串的比较！！！！strcmp头文件为string.h
        {
            printf("密码正确\n");
            break;
        }
        else
        {
            printf("密码错误,请重新输入!\n");
            
        }
    }
    if (i == 3)
    {
        printf("三次密码输入错误，退出程序!\n");
    }
    return 0;
}