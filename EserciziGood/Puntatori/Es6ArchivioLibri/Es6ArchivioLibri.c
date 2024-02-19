#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

typedef struct {
    char* title;
    char* author;
    int publication_year;
} Book;

void loadBooks(Book* array, int size, int max_char) {
    FILE* file = fopen("BookList.csv", "r");
    char line[max_char];
    char* token;

    int k = 0;

    if (file == NULL) {
        printf("There were issues, please check the file named 'BookList.csv'\n");
    } else {
        while (k < size && fgets(line, max_char, file) != NULL) {
            // Remove the newline character at the end of the line
            line[strcspn(line, "\n")] = '\0';

            // Use comma as the separator
            token = strtok(line, ",");

            if (token != NULL) {
                (array + k)->title = strdup(token);
            }

            token = strtok(NULL, ",");
            if (token != NULL) {
                (array + k)->author = strdup(token);
            }

            token = strtok(NULL, ",");
            if (token != NULL) {
                (array + k)->publication_year = atoi(token);
            }

            k++;
        }

        fclose(file);
    }
}

void printBooks(Book* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", (array + i)->title);
        printf("Author: %s\n", (array + i)->author);
        printf("Publication Year: %d\n", (array + i)->publication_year);
        printf("\n");
    }
}

void printBooksByYear(Book* array, int n, int year) {
    for (int i = 0; i < n; i++) {
        if ((array + i)->publication_year == year) {
            printf("\nBook %d:\n", i + 1);
            printf("Title: %s\n", (array + i)->title);
            printf("Author: %s\n", (array + i)->author);
            printf("Publication Year: %d\n", (array + i)->publication_year);
            printf("\n");
        }
    }
}

void bubbleSortByYear(Book* array, int n) {
    int i, j;
    int max_index;

    for (i = 0; i < n - 1; i++) {
        max_index = i;
        for (j = i + 1; j < n; j++) {
            if ((array + j)->publication_year < (array + max_index)->publication_year) {
                max_index = j;
            }
        }

        // Swap the current element with the found minimum element
        if (max_index != i) {
            Book temp = array[i];
            array[i] = array[max_index];
            array[max_index] = temp;
        }
    }

    // Print the elements sorted by publication year
    for (i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", (array + i)->title);
        printf("Author: %s\n", (array + i)->author);
        printf("Publication Year: %d\n", (array + i)->publication_year);
        printf("\n");
    }
}

int countBooks(char fileName[]) {
    int c;
    int count = 0;

    FILE* fp;
    fp = fopen(fileName, "r");

    if (fp != NULL) {
        while ((c = fgetc(fp)) != EOF) {
            if (c == '\n') {
                count++;
            }
        }
        fclose(fp);
    }
    return count + 1;
}

int main() {
    char* file_name = "BookList.csv";

    int size = countBooks(file_name);
    printf("Number of books in the file: %d\n", size);

    Book* library = (Book*)malloc(size * sizeof(Book));

    loadBooks(library, size, MAX_CHAR);

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Display all books\n");
        printf("2. Display books from a specific year\n");
        printf("3. Display books sorted by year\n");
        printf("4. Exit\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Book Library ---\n");
                printBooks(library, size);
                break;
            case 2:
                {
                    int search_year;
                    printf("\nEnter the publication year to search for: ");
                    scanf("%d", &search_year);

                    printf("\n--- Books published in the year %d ---\n", search_year);
                    printBooksByYear(library, size, search_year);
                    break;
                }
            case 3:
                printf("\n--- Books sorted by publication year ---\n");
                bubbleSortByYear(library, size);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);

    // Free dynamically allocated memory
    for (int i = 0; i < size; i++) {
        free(library[i].title);
        free(library[i].author);
    }

    free(library);

    return 0;
}
