#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

void QuickSort(ElementType arr[], int low, int high) {
  if (low >= high) {
    return;
  } 
  int l = low, r = high;
  int pivot = arr[l];
  while (l < r) {
    while (l < r && arr[r] >= pivot) {
      r--;
    }
    if (l < r) {
      arr[l++] = arr[r];
    }
    while (l < r && arr[l] <= pivot) {
      l++;
    }
    if (l < r) {
      arr[r--] = arr[l];
    }
  }

  arr[l] = pivot;
  QuickSort(arr, low, high - 1);
  QuickSort(arr, low + 1, high);
}

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void test() {
  srand((unsigned)time(NULL));
  int size = 10;
  ElementType arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  QuickSort(arr, 0, size - 1);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
