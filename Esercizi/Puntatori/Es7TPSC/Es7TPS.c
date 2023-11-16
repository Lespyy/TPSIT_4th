#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define STRL 101
#define LUNG_RIGA 200
#define NOME_FILE "listaLibri.csv" // Aggiunto il nome corretto del file

typedef struct {
    char *title;   // char title[STRL];
    char *author;
    int year;
} Libro;

int contaLibri(char nomeFile[]) {
    int c;
    int cont = 0;

    FILE *fp;
    fp = fopen(nomeFile, "r");

    if (fp != NULL) {
        while ((c = fgetc(fp)) != EOF) {
            if (c == '\n') {
                cont++;
            }
        }
        fclose(fp);
    }
    return cont;
}

int chiediDim(int min, int max, char mess[]) {
    int n;

    do {
        printf(mess);
        scanf("%d", &n);
    } while (n < min || n > max);
    return n;
}

void caricaFile(Libro *archivio, char *fileName, char *campo, char *riga, int dim) {
    FILE *fp;
    fp = fopen(fileName, "r");
    int k = 0;

    if (fp == NULL) {
        printf("Il file %s non esiste o e' vuoto!\n", fileName);
        exit(1);
    }

    for (Libro *p = archivio; p < archivio + dim; p++) {
        fgets(riga, LUNG_RIGA, fp);
        campo = strtok(riga, ",");

        campo = strtok(NULL, ",");
        p->title = strdup(campo);

        campo = strtok(NULL, ",");
        p->author = strdup(campo);

        campo = strtok(NULL, ",");
        p->year = atoi(campo);

        k++;
    }
    fclose(fp);
}

void stampaLibro(Libro *archivio, int dim) {
    for (Libro *k = archivio; k < archivio + dim; k++) {
        printf("\n%s %s %d", k->title, k->author, k->year);
    }
}

void stampaLibriData(Libro *archivio, int dim, int data) {
    for (Libro *cont = archivio; cont < archivio + dim; cont++) {
        if (data == cont->year) {
            printf("\n%s %s %d", cont->title, cont->author, cont->year);
        }
    }
}

void swap(Libro *a, Libro *b) {
    Libro temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort3(Libro archivio[], int dim) {
    int sup, sca;
    sup = dim - 1;
    while (sup > 0) {
        sca = 0;
        for (Libro *p = archivio; p < archivio + sup; p++) {
            if (p->year < (p + 1)->year) {
                swap(p, p + 1);
                sca = p - archivio;
            }
        }
        sup = sca;
    }
}

int main() {
    char fileName[] = "listaLibri.csv";
    int dim;
    int data;

    dim = contaLibri(fileName);

    Libro *archivio;
    archivio = (Libro *)malloc(dim * sizeof(Libro));

    char riga[LUNG_RIGA];
    char *campo = NULL; // Inizializzata a NULL per evitare problemi di garbage value

    caricaFile(archivio, fileName, campo, riga, dim);

    stampaLibro(archivio, dim);

    printf("\nInserisci un anno: ");
    scanf("%d", &data); // Corretto il passaggio dell'indirizzo di memoria di 'data'

    stampaLibriData(archivio, dim, data);

    bubbleSort3(archivio, dim);
    printf("\nLibri ordinati per anno di pubblicazione:");
    stampaLibro(archivio, dim);

    // Libera la memoria allocata dinamicamente per i campi title e author
    for (int i = 0; i < dim; i++) {
        free(archivio[i].title);
        free(archivio[i].author);
    }

    free(archivio);

    return 0;
}
