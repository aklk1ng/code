#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

// find the position to split the array
// on the right half is not smaller the pivot
// on the left half is smaller the pivot
int partition(ElementType arr[], int low, int high) {
  int pivot = arr[low];
  while (low < high) {
    while (low < high && arr[high] >= pivot) {
      high--;
    }
    arr[low] = arr[high];
    while (low < high && arr[low] < pivot) {
      low++;
    }
    arr[high] = arr[low];
  }
  arr[low] = pivot;

  return low;
}

// O(n * log(n)) ~ O(n * n)
void QuickSort(ElementType arr[], int low, int high) {
  if (low >= high) {
    return;
  }
  int pos = partition(arr, low, high);
  QuickSort(arr, low, pos - 1);
  QuickSort(arr, pos + 1, high);
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
