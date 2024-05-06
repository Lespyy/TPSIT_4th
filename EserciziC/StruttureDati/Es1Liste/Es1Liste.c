#include <stdio.h>
#include <stdlib.h>

/*
Si
consideri una lista dinamica di interi, i cui elementi sono del tipo definito
come di seguito riportato:


typedef
struct El {


                             int dato;


                             struct El *next;


                           } ELEMENTO;


• Si
codifichi in C la funzione somma avente il seguente prototipo:


 int somma(ELEMENTO *Testa, int M)


• Tale
funzione riceve come parametro la testa della lista e un intero M.


Quindi,
restituisce la somma dei soli valori della lista che sono multipli di M. Se la
lista è vuota, la funzione restituisce il valore -1.
*/

typedef struct El {


    int dato;


    struct El *next;


} ELEMENTO;



int somma(ELEMENTO *head, int M){

    ELEMENTO *l = head;

    int somma = 0;
    
    if (head == NULL) {

        return -1;

    }else{

        while (l != NULL){
            if ((l)->dato % M == 0){
                
                somma = somma = l->dato;

            }
        }

        return somma; 
    }

}

int main(){

    int n;

    ELEMENTO* lista = NULL;

    ELEMENTO* l;

    do{
        printf ("Inserisci un naturale o -1 per terminare\n");
        scanf ("%d", &n);
        if (n >= 0){
            if (lista == NULL){
                lista = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = lista;
            } else {

                l->next = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = l->next; 

            }

            l->dato = n;
            l->next = NULL;
        }
    }while (n >= 0);

    int num;

    printf ("dammi un numero");

    scanf ("%d", num);

    printf("%d", somma(lista, num));

    

}