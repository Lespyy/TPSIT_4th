#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMARR 100

typedef struct {
    int Num;
    char Name[DIMARR];
    char Type[DIMARR];
    int Year;
    char State[DIMARR];
} Film;

void UploadStruct(Film v[], int *k) {
    FILE *file = fopen("listafilm.csv", "r");
    int DimString = DIMARR * 6;
    char String[DimString];
    char Div[] = ",";
    
    if (file == NULL) {
        printf("Ci sono stati problemi, verificare il file chiamato 'listafilm.csv'\n");
    } else {
        while ((*k) < DIMARR && fgets(String, DimString, file) != NULL) {

            (v + *k)->Num = atoi(strtok(String, Div));
            strncpy(*(v + *k)->Name, strtok(NULL, Div), DIMARR);
            strncpy(*(v + *k)->Type, strtok(NULL, Div), DIMARR);
            (v + *k)->Year = atoi(strtok(NULL, Div));
            strncpy(*(v + *k)->State, strtok(NULL, Div), DIMARR);
            
            (*k)++;
        }
        fclose(file);
    }
}

void StampaRecord(Film v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n%d\n", i);
        printf("Number: %d\n", (v + i)->Num);
        printf("Name: %s\n", *(v + i)->Name);
        printf("Type: %s\n", *(v + i)->Type);
        printf("Year: %d\n", (v + i)->Year);
        printf("State: %s\n", *(v + i)->State);
        printf("\n");
    }
}

void PrintFilmYear(Film v[], int n, int Year){
    int i = 0;
    for (i = 0; i < n; i++){
        if (v[i].Year == Year){
            printf("Number: %d\n", (v + i)->Num);
            printf("Name: %s\n", *(v + i)->Name);
            printf("Type: %s\n", *(v + i)->Type);
            printf("Year: %d\n", (v + i)->Year);
            printf("State: %s\n", *(v + i)->State);
            printf("\n");

        }
    }
}

int main() {
    int NumFilm = 0, year = 0;
    Film Archive[DIMARR];

    UploadStruct(Archive, &NumFilm);

    StampaRecord(Archive, NumFilm);

    printf ("Tell me a year: ");
    scanf("%d", &year);

    PrintFilmYear(Archive, NumFilm, year);


    return 0;
}
