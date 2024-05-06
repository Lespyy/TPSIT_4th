#include <stdio.h>
#include <stdlib.h>

int main (){

    /*
    int* puntatore; //questa è una variabile di puntatori a interi

    //ogni variabile ha un indirizzo e un valore

    // e tramite * posso prendere il valore se all'interno della variabile c'è un indirizzo

    // e tramite & prendo l'indirizzo della variabile
    
    int variabile; // questa è una variabile
     

    puntatore = &variabile;

    *puntatore = 5;

    printf("%d", variabile);

    */

    //corretto

    /*

    int* Vettore; // Vettore è un puntatore a interi

    int dim = 5;

    Vettore = malloc(sizeof(int) * dim); //crea una area di memoria di grandezza int * dim il cui valore è l'indirizzo di una area di memoria pari a 5 interi

    for (int k = 0; k < dim; k++){

        *(Vettore + k) = k + 1; //il valore della cella puntata da vettore+k assegna k + 1

        printf("%d - %p\n", *(Vettore + k), (Vettore + k));//stampa come intero il valore della cella puntata da k affiancato il valore della cella puntata da Ve... che è l'ndirizzo della cella;

    }

    */

    //corretto

    int*** PuntDiPuntDiPuntDivar;
    
    int** PuntDiPuntDiVar; // è una cella he punta a una cella che punta a una altra cella

    int* PuntDiVar;

    int Var;

    PuntDiPuntDiPuntDivar = &PuntDiPuntDiVar;

    PuntDiPuntDiVar = &PuntDiVar; // a PuntdiPunt assegno il valore di Punt che sarà un indirizzo dii una altra cella

    PuntDiVar = &Var; //a Punt di punt assegno l'indirizzo della variabile

    Var = 5;

    printf("Var == %d \t\t\t\t %p \t\t\t %p \n", Var, &Var, &Var);

    printf("PuntDiVar == %d \t\t\t\t %p \t\t\t %p \n", *PuntDiVar, PuntDiVar, &PuntDiVar);

    printf("PuntiDiPuntDiVar == %d \t\t\t %p \t\t\t %p \n", **PuntDiPuntDiVar, PuntDiPuntDiVar, &PuntDiPuntDiVar);

    printf("PuntDiPuntiDiPuntDiVar == %d \t\t %p \t\t\t %p \n", ***PuntDiPuntDiPuntDivar, PuntDiPuntDiPuntDivar, &PuntDiPuntDiPuntDivar);


    //Un puntatore ha un valore che sarà l'indirizzo della cella puntata 

    // il valore della cella puntata 5

    // e un indirizzo









    











}