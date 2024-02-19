#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod{

    char carattere;

    struct nod* next;

}Node;

int is_empty(Node* head){
    if(head == NULL){
        return 1;
    } else{
        return 0;
    }
}

void push(Node** head, Node* element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    } else{
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node** head){
    Node* ret = *head;
    if(is_empty(*head)){
        return NULL;
    } else{
        *head = ret->next;
    }
    return ret;
}


int main(){

    printf("dammi tramite carattere per carattere una frase palindroma (inserisci ' ' per smettere)");

    char* str;

    scanf ("%s", str);

    char car;

    Node* head;

    Node* nodo;

    head->next = nodo;

    int compare = 0;

    while (strcmp(car, ' ') != 0){

        if (getc(str) != '\n'){

            nodo->carattere = getc(str);

            push (head, nodo);

            

        }

    }

   

}