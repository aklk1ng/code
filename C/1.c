#include <stdio.h>
int MAX(int a, int b)
{
    // if (a > b)
    // return a;
    // else
    // return b;
    return (a>b ? a : b);
}
int main (void)
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    int m = MAX(x, y);
    printf("%d\n", m);
    return 0;
}
