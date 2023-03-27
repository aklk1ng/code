#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

void Bubble_Sort(ElementType arr[], int size) {
  int i, j;
  for (i = 0; i < size - 1; i++) {
    for (j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
      }
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
  Bubble_Sort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
