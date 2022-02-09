//猜数字游戏
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
void menu()
{
    printf("******************\n");
    printf("*****1.play  *****\n");
    printf("*****0.exit  *****\n");
    printf("******************\n");
}
void game()
{   //猜数字游戏的实现
    //1.生成随机数
    //rand函数返回一个0——32767的数字，但数字不够随机
    //利用时间戳——时间转换成随机数
    //使用固定值并不能使得产生的随机数更改，需要一个随机的给定值
    int ret = rand()%100 + 1;//%100则余数为0——99，再加1则余数为0——100
    //2.猜数字
    int guess = 0;
    while (1)
    {
        printf("猜数字:> ");
        scanf("%d", &guess);
        if (guess < ret)
        {
            printf("猜小了\n");
        }
        else if (guess > ret)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("恭喜你，猜对了:\n");
            break;
        }
    }
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));//NULL为返回空值
    do
    {
       menu();//打印菜单
       printf("请选择:>");
       scanf("%d", &input);
       switch (input)
       {
           case 1:
            game();
            break;
           case 0:
            printf("退出游戏\n");
            break;
           default:
            printf("选择错误重新选择\n");
            break;
       }
    } while (input);
    return 0;
}