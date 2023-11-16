#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100
#define LIM_MIN 1
#define LIM_MAX 20

int askSize(int min, int max, char message[]) {
    int n;

    do {
        printf(message);
        scanf("%d", &n);
    } while (n < min || n > max);
    return n;
}

void loadRandomArrayWithPrint(int arr[], int size) {
    
    for (int k = 0; k < size; k++) {
        arr[k] = LIM_MIN + rand() % (LIM_MAX + 1 - LIM_MIN);
        // To verify the sorting, print the random array
        printf("[%d]: %d ", k, arr[k]);
        printf("\n");
    }
}

void swap(int *a, int *b) {

    int temp = *a;

    *a = *b;

    *b = temp;
}

void bubbleSort(int arr[], int n) {

    int k, upper, swapIndex; 

    upper = n - 1;

    while (upper > 0) {

        swapIndex = 0;

        for (k = 0; k < upper; k++) {

            if (arr[k] > arr[k + 1]){

                swap(&arr[k], &arr[k + 1]);

                swapIndex = k;

            }

        }

        upper = swapIndex;
    }
}

void printArray(int arr[], int size) {

    for (int k = 0; k < size; k++) {

        printf("[%d]: %d ", k, arr[k]);

        printf("\n");

    }

    printf("\n");
}

int main() {
    
    int arr[DIM];

    int size = askSize(LIM_MIN, DIM, "Enter the maximum number of elements to load into the array: ");


    srand(time(NULL));


    printf("Random Array:\n");

    loadRandomArrayWithPrint(arr, size);


    bubbleSort(arr, size); // Sort the array

    
    printf("Sorted Array:\n");

    printArray(arr, size);

    return 0;
}