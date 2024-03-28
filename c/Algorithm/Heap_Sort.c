#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

void Print(int a[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void heapify(int a[], int k, int size) {
  int pivot = a[k];
  // the array starts from 0
  for (int i = 2 * k + 1; i < size; i = 2 * i + 1) {
    // move the i to the bigger child index
    if (i < size - 1 && a[i] < a[i + 1]) {
      i++;
    }

    if (a[i] <= pivot) { // the parent value is bigger than childs
      break;
    } else {
      a[k] = a[i];
      k = i;
    }
  }
  // move the smallest node to the last position
  a[k] = pivot;
}

// adjust all non-leaf node
void BuildMaxHeap(int a[], int size) {
  // adjust all non-leaf node
  for (int i = size / 2; i >= 0; i--) {
    heapify(a, i, size);
  }
}

// O(n * log(n))
void heapSort(ElementType a[], int size) {
  // O(n)
  BuildMaxHeap(a, size);

  // O(n * log(n))
  for (int i = size - 1; i > 0; i--) {
    ElementType tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;

    // adjust the heap
    heapify(a, 0, i);
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
  heapSort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
