//将数字按照大小顺序排列
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    //调整
    if (a < b)
    {
        int ret = a;
        a = b;
        b = ret;
    }
    if (a < c)
    {
        int ret = a;
        a = c;
        c = ret;
    }
    if (b < c)
    {
        int ret = b;
        b = c;
        c = ret;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}