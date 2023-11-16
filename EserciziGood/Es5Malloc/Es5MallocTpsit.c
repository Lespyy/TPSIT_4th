#include <stdio.h>
#include <stdlib.h>

int askSize(int min, int max, char message[]) {
    int n;

    do {
        printf(message);
        scanf("%d", &n);
    } while (n < min || n > max);
    return n;
}

void loadArray(int* arr, int size) {
    printf("Enter %d integer values:\n", size);

    for (int *p = arr; p < arr + size; p++) {
        scanf("%d", p);
    }
}

void printArray(int* arr, int size) {
    printf("Entered values:\n");
    for (int *p = arr; p < arr + size; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

int main() {
    int size;
    int* arr;

    size = askSize(1, 100, "Enter the size of the array: ");
    arr = (int*)malloc(size * sizeof(int));

    if (arr != NULL) {
        loadArray(arr, size);
        printArray(arr, size);
        free(arr); // Free dynamically allocated memory
    }

    return 0;
}
