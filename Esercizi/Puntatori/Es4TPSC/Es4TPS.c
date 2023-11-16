#include <stdio.h>
#include <stdlib.h>

#define DIM_ARRAY 10

int CalcolaSomma(int dim_array, int array[]){

    int i = 0;
    int somma = 0;

    for (i = 0; (array + i) < (array + dim_array); i++){

        somma = *(array + i) + somma;

    }

    return somma;

}

int main(){

    int somma = 0;
    int array[DIM_ARRAY] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


    somma = CalcolaSomma(DIM_ARRAY, array);

    printf ("somma = %d", somma);


    return 0;

}