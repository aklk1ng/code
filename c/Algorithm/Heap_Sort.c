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

#if 0
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
#endif /* 0 */

#if 1
// github: https://TheAlgorithms/C-Plus-Plus
void heapify(ElementType arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }
  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    arr[i] = arr[i] ^= arr[largest];
    arr[largest] = arr[i] ^= arr[largest];
    arr[i] = arr[i] ^= arr[largest];
    heapify(arr, n, largest);
  }
}

void heapSort(ElementType arr[], int size) {
  for (int i = size - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }

  for (int i = size - 1; i >= 0; i--) {
    arr[0] = arr[0] ^= arr[i];
    arr[i] = arr[0] ^= arr[i];
    arr[0] = arr[0] ^= arr[i];
    heapify(arr, i, 0);
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

#endif /* 1 */
