#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

int CalcolaLunghezzaRicorsiva(Node* head){

    if (head == NULL) {
        return 0;
    }

    return 1 + CalcolaLunghezzaRicorsiva(head->next);

}

int main (){

    int n;

    Node* lista = NULL;

    Node* l;

    do{
        printf ("Inserisci un naturale o -1 per terminare\n");
        scanf ("%d", &n);
        if (n >= 0){
            if (lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {

                l->next = (Node*) malloc(sizeof(Node));
                l = l->next; 

            }

            l->value = n;
            l->next = NULL;
        }
    }while (n >= 0);

    l = lista; 
    printf("numeri inseriti: "); 
    while (l != NULL){
        printf("%d - %p \n", l->value, l->next);
        l = l->next;
    }
    printf("\n");

    l = lista;

    printf("%d", CalcolaLunghezzaRicorsiva(l));

    return 0;

}