#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main() {
  char arr1[] = "Welcome To LOL!!!";
  char arr2[] = "*****************";
  int left = 0;
  int right = strlen(arr1) - 1;

  while (left <= right) {
    arr2[left] = arr1[left];
    arr2[right] = arr1[right];
    printf("%s\n", arr2);
    Sleep(1000);   // 睡眠一秒
    system("cls"); // 清空屏幕
    left++;
    right--;
  }
  printf("%s\n", arr2);
  return 0;
}
