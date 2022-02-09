#include <stdio.h>
int main()
{
    char a[] = {0};
    char b[] = {0};
    printf("请输入姓: ");
    scanf("%s", a);
    printf("请输入名: ");
    scanf("%s", b);
    printf("%s,%s\n", b, a);
    return 0;
}