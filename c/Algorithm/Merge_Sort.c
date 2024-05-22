#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

// O(n)
void Merge(ElementType a[], ElementType t[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            t[k++] = a[j++];
        } else {
            t[k++] = a[i++];
        }
    }

    // copy the rest elements
    while (i <= mid) {
        t[k++] = a[i++];
    }
    while (j <= r) {
        t[k++] = a[j++];
    }

    // copy whole tmp array to source array
    for (k = 0, i = l; i <= r; i++, k++) {
        a[i] = t[k];
    }
}

// O(n * log(n))
void Msort(ElementType a[], ElementType t[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        Msort(a, t, l, mid);
        Msort(a, t, mid + 1, r);
        Merge(a, t, l, mid, r);
    }
}

void MergeSort(ElementType a[], int size) {
    if (size <= 1) {
        return;
    }
    ElementType *tmp = (ElementType *)malloc(size * sizeof(ElementType));
    if (!tmp) {
        printf("malloc failed!\n");
        exit(-1);
    }
    Msort(a, tmp, 0, size - 1);
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
