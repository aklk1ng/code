#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElementType;

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void Selection_Sort(ElementType arr[], int size) {
  int i, j;
  for (i = 0; i < size - 1; i++) {
    int min = i;
    for (j = i + 1; j < size; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    if (min != i) {
      arr[i] ^= arr[min];
      arr[min] ^= arr[i];
      arr[i] ^= arr[min];
    }
  }
}

void test() {
  srand((unsigned)time(NULL));
  int size = 10;
  ElementType arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  Selection_Sort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
