#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

#define LeftChild(i) (2 * (i) + 1)

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void PercDown(ElementType arr[], int i, int size) {
  int Child;
  ElementType tmp;
  for (tmp = arr[i]; LeftChild(i) < size; i = Child) {
    Child = LeftChild(i);
    if (Child != size - 1 && arr[Child + 1] > arr[Child]) {
      Child++;
    }
    if (tmp < arr[Child]) {
      arr[i] = arr[Child];
    } else {
      break;
    }
  }
  arr[i] = tmp;
}

void Heap_Sort(ElementType arr[], int size) {
  int i;
  ElementType tmp;
  for (i = size / 2; i >= 0; i--) {
    PercDown(arr, 0, size);
  }
  for (i = size - 1; i > 0; i--) {
    tmp = arr[0];
    arr[0] = arr[i];
    arr[i] = tmp;
    PercDown(arr, 0, i);
  }
}

void test() {
  srand((unsigned)time(NULL));
  int size = 10;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  printf("---------------------------------------------------\n");
  Heap_Sort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
