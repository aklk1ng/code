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

void heapify(int arr[], int k, int size) {
  int pivot = arr[k];
  // the array starts from 0
  for (int i = 2 * k + 1; i < size; i *= 2) {
    // move the i to the bigger child index
    if (i < size - 1 && arr[i] < arr[i + 1]) {
      i++;
    }

    if (arr[i] <= pivot) { // the parent value is bigger than childs
      break;
    } else {
      arr[k] = arr[i];
      k = i;
    }
  }
  // move the smallest node to the last position
  arr[k] = pivot;
}

void BuildMaxHeap(int arr[], int size) {
  // adjust all non-leaf node
  for (int i = size / 2; i >= 0; i--) {
    heapify(arr, i, size);
  }
}

// O(n * log(n))
void heapSort(ElementType arr[], int size) {
  // O(n)
  BuildMaxHeap(arr, size);

  // O(n * log(n))
  for (int i = size - 1; i > 0; i--) {
    ElementType tmp = arr[0];
    arr[0] = arr[i];
    arr[i] = tmp;

    // adjust the heap
    heapify(arr, 0, i);
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
