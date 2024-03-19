#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

// O(n)
void Merge(ElementType arr[], ElementType t[], int lpos, int rpos, int rend) {
  int i = lpos, j = rpos, k = 0;
  while (i < rpos && j <= rend) {
    if (arr[i] > arr[j]) {
      t[k++] = arr[j++];
    } else {
      t[k++] = arr[i++];
    }
  }
  while (i < rpos) {
    t[k++] = arr[i++];
  }
  while (j <= rend) {
    t[k++] = arr[j++];
  }

  // copy whole tmp array to source array
  for (k = 0, i = lpos; i <= rend; i++, k++) {
    arr[i] = t[k];
  }
}

// O(n * log(n))
void Msort(ElementType arr[], ElementType t[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    Msort(arr, t, l, mid);
    Msort(arr, t, mid + 1, r);
    Merge(arr, t, l, mid + 1, r);
  }
}

void MergeSort(ElementType arr[], int size) {
  if (size <= 1) {
    return;
  }
  ElementType *tmp = (ElementType *)malloc(size * sizeof(ElementType));
  if (!tmp) {
    printf("malloc failed!\n");
    exit(-1);
  }
  Msort(arr, tmp, 0, size - 1);
}

void Print(ElementType arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void test() {
  srand((unsigned)time(NULL));
  int size = 15;
  ElementType arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  printf("---------------\n");
  MergeSort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
