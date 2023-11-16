#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DIM_STRINGA 100
#define DA_PAGARE 2200
#define PAGARE_SINGOLO 100

typedef struct {
    char* data;
    char* cognome;
    int pagato;
} Persone;

typedef struct{
    char* cognome;
    int pagato;
}Me;



int contaPersone(char nomeFile[]) {
    int c;
    int cont = 0;

    FILE *file;
    file = fopen(nomeFile, "r");

    if (file != NULL) {
        while ((c = fgetc(file)) != EOF) {
            if (c == ';') {
                
                cont++;

                printf("ho trovato una riga %d",cont);
            }
        }
        fclose(file);
    }
    return 22; // non capisco perché non vada quindi per verificare ho fatto così
}

void UploadStruct(Persone v[], int dim, int dim_string) {
    FILE *file = fopen("4AROB_GITA.csv", "r");
    char String[dim_string];
    char Div[] = ";";
    int k = 0;

    int somma = 0;

    if (file == NULL) {
        printf("Ci sono stati problemi, verificare il file chiamato 'Data.txt'\n");
    } else {
        while (k < dim && fgets(String, dim_string, file) != NULL) {
            (v + k)->data = strdup(strtok(String, Div));
            (v + k)->cognome = strdup(strtok(NULL, Div));
            (v + k)->pagato = atoi(strtok(NULL, Div));
            somma += (v + k)->pagato;


            k++;
        }

        if (somma < DA_PAGARE){

            printf("mancano %d euro \n", DA_PAGARE - somma);
            
            for (k = 0; k < dim; k++){

                if ((v + k)->pagato < PAGARE_SINGOLO){

                    printf("%s deve ancora pagare %d euro\n", (v + k)->cognome, PAGARE_SINGOLO - (v + k)->pagato);

                }else{
                    printf("%s ha già pagato tutto\n", (v + k)->cognome);
                }

            }

        }else{

            printf("tutti hanno pagato tutto");

        }



        fclose(file);
    }
}

void FindMe(Persone v[], Me me[], int dim, int dim_string) {
    FILE *file = fopen("4AROB_GITA.csv", "r");
    char String[dim_string];
    char Div[] = ";";
    int k = 0;

    int somma = 0;
            
    for (k = 0; k < dim; k++){

        if (strcmp((v + k)->cognome, (me + 0)->cognome) == 0){

            k = dim;

            (me)->pagato += (v + k)->pagato;

            

        }

    }

    if ((me)->pagato < PAGARE_SINGOLO){
                
        printf("%s deve ancora pagare %d euro\n", (me)->cognome, PAGARE_SINGOLO - (me)->pagato);  

    }else{

        printf("%s ha pagato il suo");
        
    }


}




void StampaRecord(Persone v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Data: %s\n", (v + i)->data);
        printf("Cognome: %s\n", (v + i)->cognome);
        printf("Pagamento: %d\n", (v + i)->pagato);
        printf("\n");
    }
}

int main() {

    char* file_name = (char*) malloc(100 * sizeof(char));

    file_name = "Data.txt";

    int dim = contaPersone(file_name);
    printf("Numero di persone nel file: %d\n", dim);

    Persone* gruppo = (Persone*) malloc(DIM_STRINGA * sizeof(Persone));
    Me* me = (Me*) malloc(DIM_STRINGA * sizeof(Me));

    UploadStruct(gruppo, dim, DIM_STRINGA);

    (me)->cognome = "Ansaldi";
    (me)->pagato = 0;

    printf("entro in findme\n");

    FindMe(gruppo, me, dim, DIM_STRINGA);

    printf("\nesco da findme\n");

    //StampaRecord(gruppo, dim);

    // Libera la memoria allocata dinamicamente
    for (int i = 0; i < dim; i++) {
        free(gruppo[i].data);
        free(gruppo[i].cognome);
    }

    return 0;
}