#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void Insertion_Sort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int tmp = arr[i];
    int j = i;
    for (; j > 0 && arr[j - 1] > tmp; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = tmp;
  }
}

void Insertion_Sort_v2(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int tmp = arr[i];

    // use binary search to find the position for swap
    int l = 0, r = i - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (arr[mid] > tmp) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    for (int j = i; j > l; j--) {
      arr[j] = arr[j - 1];
    }
    arr[l] = tmp;
  }
}

void test() {
  srand((unsigned)time(NULL));
  int size = 20;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  printf("------------------------------\n");
  // Insertion_Sort(arr, size);
  Insertion_Sort_v2(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
