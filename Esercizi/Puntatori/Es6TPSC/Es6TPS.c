#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_STRINGA 100

typedef struct {
    char* nome;
    char* cognome;
    int data_nascita;
} Persone;

void UploadStruct(Persone v[], int dim, int dim_string) {
    FILE *file = fopen("Data.txt", "r");
    char String[dim_string];
    char Div[] = " ";
    char Div1[] = "/";
    int k = 0;

    if (file == NULL) {
        printf("Ci sono stati problemi, verificare il file chiamato 'Data.txt'\n");
    } else {
        while (k < dim && fgets(String, dim_string, file) != NULL) {
            (v + k)->nome = strdup(strtok(String, Div));
            (v + k)->cognome = strdup(strtok(NULL, Div));
            (v + k)->data_nascita = atoi(strtok(NULL, Div1)) + atoi(strtok(NULL, Div1)) * 100 + atoi(strtok(NULL, Div1)) * 10000;
            k++;
        }
        
        fclose(file);
    }
}

void StampaRecord(Persone v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Nome: %s\n", (v + i)->nome);
        printf("Cognome: %s\n", (v + i)->cognome);
        printf("Data di nascita: %d\n", (v + i)->data_nascita);
        printf("\n");
    }
}

void StampaRecordDecrescente(Persone v[], int n) {
    int i, j;
    int max_index;

    for (i = 0; i < n - 1; i++) {
        max_index = i;
        for (j = i + 1; j < n; j++) {
            if ((v + j)->data_nascita > (v + max_index)->data_nascita) {
                max_index = j;
            }
        }

        // Scambia l'elemento corrente con l'elemento massimo trovato
        if (max_index != i) {
            Persone temp = v[i];
            v[i] = v[max_index];
            v[max_index] = temp;
        }
    }

    // Stampa gli elementi ordinati
    for (i = 0; i < n; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Nome: %s\n", (v + i)->nome);
        printf("Cognome: %s\n", (v + i)->cognome);
        printf("Data di nascita: %d\n", (v + i)->data_nascita);
        printf("\n");
    }
}

int contaPersone(char nomeFile[]) {
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

int main() {
    char* file_name = (char*) malloc(100 * sizeof(char));

    file_name = "Data.txt";

    int dim = contaPersone(file_name) + 1;
    printf("Numero di persone nel file: %d\n", dim);

    Persone* gruppo = (Persone*) malloc(dim * sizeof(Persone));

    UploadStruct(gruppo, dim, DIM_STRINGA);
    //StampaRecord(gruppo, dim);

    StampaRecordDecrescente(gruppo, dim);

    // Libera la memoria allocata dinamicamente
    for (int i = 0; i < dim; i++) {
        free(gruppo[i].nome);
        free(gruppo[i].cognome);
    }

    return 0;
}
