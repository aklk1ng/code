// 二分查找数字代码
#include <stdio.h>
int main() {
  int k = 7;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int left = 0;
  int sz = sizeof(arr) / sizeof(arr[0]); // 数组元素的个数(数组总大小除以第一个元素的大小)
  int right = sz - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] < k) {
      left = mid + 1;
    } else if (arr[mid] > k) {
      right = mid - 1;
    } else {
      printf("OK!目标数字下标为:%d\n", mid);
      break;
    }
  }
  if (left > right) {
    printf("Default!\n");
  }

  return 0;
}
