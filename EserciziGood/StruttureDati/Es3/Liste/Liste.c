#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Lista{

    int value;

    struct Lista* next;

}List;

bool isEmpty(List* punt){

    bool ret;

    if (punt == NULL){

        ret = true;

    }else{

        ret = false;

    }

    return ret;

}

int somma (List* head){

    if (isEmpty(head)){

        return 0;

    }else{

        int somma = 0;

        List* lista = head;

        while (lista != NULL){

            somma += lista->value;

            lista = lista->next;

        }

        return somma;

    }
    
    List* attuale = head;



}



int main(){

    List* head = NULL;

    /*if (isEmpty(head)){

        printf("la lista e vuota\n");

    }else{

        printf("la lista non e vuota\n");

    }

    head = malloc(sizeof(List));

    if (isEmpty(head)){

        printf("la lista e vuota\n");

    }else{

        printf("la lista non e vuota\n");

    }

    head->next = NULL;

    /*head->value = 10;

    printf("%d\n", head->value);

    if (isEmpty(head)){

        printf("la lista e vuota\n");

    }else{

        printf("la lista non e vuota\n");

    }*/


    //corretto
    /*
    int volte = 5;

    int k = 0;

    int num = 0;

    List* lista = head;

    while(lista->next != NULL){

        lista = lista->next;

    }

    for (k = 0; k < 5; k++){

        lista->next = malloc(sizeof(List));

        lista = lista->next;

        printf("dammi un numero");        

        scanf("%d", &lista->value);

        lista->next = NULL;

    }

    lista = head;

    while(lista != NULL){

        printf("%d\n", lista->value);

        lista = lista->next;

    }

    //corretto

    */

   List* lista = head; 

   int num = 0;

    do{

        printf("dammi un numero");

        scanf("%d", &num);

        

        if (num > 0){

            if (isEmpty(lista)){

                lista = malloc(sizeof(List));

                head = lista;

                lista->value = num;

                lista->next = NULL;

            }else{

                lista->next = malloc(sizeof(List));

                lista = lista->next;

                lista->value = num;

                lista->next = NULL;

            }

            

        }  

    }while(num > 0);

    lista = head;

    while(lista != NULL){

        printf("%d/", lista->value);

        lista = lista->next;

    }

    printf("%d", somma(head));

    lista = head;
    while (lista != NULL) {
        List* temp = lista;
        lista = lista->next;
        free(temp);
    }


    

}