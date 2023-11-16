#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int AddVett(int vett[], int dim){
    int somma = 0;

    int k = 0;

    for(k = 0; k < dim; k++){

        somma += *(vett + k); //somma = somma + vett[k];

    }

    return somma;
}

int main() {

    int vett[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int somma = 0;

    somma = AddVett(vett, DIM);

    printf("Somma: %d", somma);

    return 0;

}