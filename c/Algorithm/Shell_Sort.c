#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// O(n ^ (0.5e)) ~ O(n * n)
void Shellsort(int arr[], int size) {
  for (int d = size / 2; d > 0; d /= 2) {
    // start with the second element in all groups
    for (int i = d; i < size; i++) {
      int tmp = arr[i];
      int j = i;
      for (; j >= d && arr[j - d] > tmp; j -= d) {
        arr[j] = arr[j - d];
      }
      arr[j] = tmp;
    }
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
  printf("------------------\n");
  Shellsort(arr, size);
  Print(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
