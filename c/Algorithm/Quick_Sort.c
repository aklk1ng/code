#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

// return the position to split the array
// on the right half is not smaller the pivot
// on the left half is smaller the pivot
int partition(ElementType a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] < pivot) {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = pivot;

    return low;
}

// O(n * log(n)) ~ O(n * n)
void QuickSort(ElementType a[], int low, int high) {
    if (low >= high) {
        return;
    }
    int pos = partition(a, low, high);
    QuickSort(a, low, pos - 1);
    QuickSort(a, pos + 1, high);
}

void Print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test() {
    srand((unsigned)time(NULL));
    int size = 10;
    ElementType arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    Print(arr, size);
    QuickSort(arr, 0, size - 1);
    Print(arr, size);
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
