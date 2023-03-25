#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

/**
 * @brief merge two array
 *
 * @param arr acutal array
 * @param Tmparr tmparr
 * @param lpos start of left half
 * @param rpos start of right half
 * @param rend end of right half also the end of array
 */
void Merge(ElementType arr[], ElementType Tmparr[], int lpos, int rpos, int rend) {
  int i, lend, size, Tmppos;
  lend = rpos - 1;
  size = rend - lpos + 1;
  while (lpos <= lend && rpos <= rend) {
    if (arr[lpos] <= arr[rpos]) {
      Tmparr[Tmppos++] = arr[lpos++];
    } else {
      Tmparr[Tmppos++] = arr[rpos++];
    }
  }

  // copy rest of first half
  while (lpos <= lend) {
    Tmparr[Tmppos++] = arr[lpos++];
  }
  // copy rest of second half
  while (rpos <= rend) {
    Tmparr[Tmppos++] = arr[rpos++];
  }

  for (i = 0; i < size; i++, rend--) {
    arr[rend] = Tmparr[rend];
  }
}

void Msort(ElementType arr[], ElementType Tmparr[], int left, int right) {
  int mid;
  if (left < right) {
    mid = left + (right - left) / 2;
    Msort(arr, Tmparr, left, mid);
    Msort(arr, Tmparr, mid + 1, right);
    Merge(arr, Tmparr, left, mid + 1, right);
  }
}

void MergeSort(ElementType arr[], int size) {
  if (size == 1) {
    return;
  }
  ElementType *Tmparr = (ElementType *)malloc(size * sizeof(ElementType));
  if (Tmparr == NULL) {
    printf("malloc failed!\n");
    exit(-1);
  }
  Msort(arr, Tmparr, 0, size - 1);
}

void Print(ElementType arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
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
  return 0;
}
