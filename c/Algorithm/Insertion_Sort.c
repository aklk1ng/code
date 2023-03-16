#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void Insertion_Sort(int arr[], int size) {
  int j, p;
  int tmp;
  for (p = 0; p < size; p++) {
    tmp = arr[p];
    for (j = p; j > 0 && arr[j - 1] > tmp; j--)
      arr[j] = arr[j - 1];
    arr[j] = tmp;
  }
  Print(arr, size);
}


void test() {
  srand((unsigned)time(NULL));
  int size = 10000;
  int arr[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10000;
  }
  Print(arr, size);
  printf("------------------------------\n");
  Insertion_Sort(arr, size);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
