//���ֲ������ִ���
#include <stdio.h>
int main()
{
    int k = 7;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int left = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�صĸ���(�����ܴ�С���Ե�һ��Ԫ�صĴ�С)
    int right = sz-1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < k) 
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            printf("OK!Ŀ�������±�Ϊ:%d\n", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("Default!\n");
    }
    
    return 0;


}
