#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100
#define LIM_MIN 1
#define LIM_MAX 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]: %d\n", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[DIM];
    int size;

    do {
        printf("Enter the number of elements to load into the array (between %d and %d): ", LIM_MIN, DIM);
        scanf("%d", &size);
    } while (size < LIM_MIN || size > DIM);

    srand(time(NULL));

    printf("\nRandom Array:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = LIM_MIN + rand() % (LIM_MAX - LIM_MIN + 1);
        printf("[%d]: %d\n", i, arr[i]);
    }

    selectionSort(arr, size);

    printf("\nSorted Array:\n");
    printArray(arr, size);

    return 0;
}
