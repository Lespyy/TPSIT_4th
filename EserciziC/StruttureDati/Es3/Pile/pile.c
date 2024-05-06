#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{

    int value;

    struct Node* next;

}Node;

bool isVoid(Node** head){

    bool ret;

    if (*head == NULL){

        ret = true;

    }else{

        ret = false;

    }

    return ret;

}

Node* Push (Node* head, int value){//puntatyore di puntatori di tipo node

    Node* new;//puntatore di tipo node

    new = malloc(sizeof(Node));//ci assegno un indirizzo in memoria

    new->next = head;//la cella puntata da new ha un next il quale punta a il valore della cella puntata da head che è l'inizio della pila

    head = new;// alla cella puntata da head ci asegno l'indirizzo della nuova area di memoria appena creata

    new->value = value;

    return head;

}

int main(){

    //Pile sono delle "Liste" che posso accedere solo grazie alla pushe alla pop quindi 

    Node* head = NULL;

    int dim = 5;

    for(int k = 0; k < dim; k++){

        head = Push(head, k + 1);

    }

    Node* current = head;

    while (current != NULL) {

        printf("%d\t", current->value);

        current = current->next;
        
    }

    
    // Libera la memoria allocata
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    

    

}