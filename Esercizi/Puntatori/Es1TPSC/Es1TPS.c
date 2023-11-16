#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_RIGA 100
#define NUM_RIGHE 20000

typedef struct {
    int num;
    char* titolo;
    char* Genere;
    int anno;
    char* disponibilita;
} Film;

int main() {
    int num_film = 0;
    char nome_file[] = "./listaFilm.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int k = 0;
    char div[] = ",";

    fp = fopen(nome_file, "r");
    if (fp == NULL){
        printf("il file %s non esiste\n", nome_file);
        exit(1);
    }

    while(fgets(riga, DIM_RIGA, fp)){

        campo = strtok(riga, div);
        array_film[k].num = atoi(campo);

        campo = strtok(NULL, div);
        array_film[k].titolo = strdup(campo);

        campo = strtok(NULL, div);
        array_film[k].Genere = strdup(campo);

        campo = strtok(NULL, div);
        array_film[k].anno = atoi(campo);

        campo = strtok(NULL, div);
        array_film[k].disponibilita = strdup(campo);
        

        k++;

    }

    for (int i = 0; i < k; i++) {
        printf("number: %d\n", array_film[i].num);
        printf("Name: %s\n", array_film[i].titolo);
        printf("Type: %s\n", array_film[i].Genere);
        printf("Year: %d\n", array_film[i].anno);
        printf("State: %s\n", array_film[i].disponibilita);
        printf("\n");
    }

    return 0;
}
