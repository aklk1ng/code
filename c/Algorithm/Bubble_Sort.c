#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

// O(n * n)
void Bubble_Sort(ElementType arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

void Bubble_Sort_v2(ElementType arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int flag = 0;
    for (int j = 1; j < size - i; j++) {
      if (arr[j - 1] > arr[j]) {
        int tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
        flag = 1;
      }
    }
    // the array is sorted
    if (!flag) {
      return;
    }
  }
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
  // Bubble_Sort(arr, size);
  Bubble_Sort_v2(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
