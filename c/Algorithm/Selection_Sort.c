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

// O(n * n)
void Selection_Sort(ElementType arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        // find the smallest element in the array after the i
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
}

void test() {
    srand((unsigned)time(NULL));
    int size = 10;
    ElementType arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    Print(arr, size);
    Selection_Sort(arr, size);
    Print(arr, size);
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
