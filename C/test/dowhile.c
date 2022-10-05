#include <stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    int a = 1;
    int sum = 0;
    for (n = 1; n < 11; n++)
    {
    a *= n;
    sum += a;
    }
    printf("%d\n", sum);
    return 0;
}