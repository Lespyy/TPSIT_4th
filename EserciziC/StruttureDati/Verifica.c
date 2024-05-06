#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int num;
    struct node* next;
} Node;

bool is_empty(Node* head) {
    return head == NULL;
}

void push(Node** head, Node* element) {
    if (is_empty(*head)) {
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node** head) {
    Node* ret = *head;
    if (is_empty(*head)) {
        return NULL;
    } else {
        *head = ret->next;
        ret->next = NULL;
    }
    return ret;
}

void stampaPila(Node* head) {
    Node* l = head;
    printf("\nValori pila: ");
    while (l != NULL) {
        printf("%d ", l->num);
        l = l->next;
    }
}

void enqueue(Node** head, Node* e) {
    /*
        MScorro coda portandola su pila di appoggio
        mtto elemento al fondo della pila principale   
        scorro la pila d'appoggio invertendo l'assegnamento
    */

    Node* appoggio = NULL;

    // Scorro coda portandola su pila di appoggio
    while (!is_empty(*head)) {
        push(&appoggio, pop(head));
    }

    //mtto elemento al fondo della pila principale  
    push(head, e);

    // scorro la pila d'appoggio invertendo l'assegnamento
    while (!is_empty(appoggio)) {
        push(head, pop(&appoggio));
    }
}

Node* dequeue(Node** head) {
    /*
        creo una ret a cui assegno head
        sposto la head in basso  
        ritorno ret
    */

    //creo una ret a cui assegno head/sposto la head in basso 
    Node* ret = pop(head);

    // ritorno ret
    return ret;
}


int main() {
    Node* head = NULL;

    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->num = 1;
    enqueue(&head, node1);

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->num = 2;
    enqueue(&head, node2);

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->num = 3;
    enqueue(&head, node3);

    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->num = 4;
    enqueue(&head, node4);

    stampaPila(head);

    dequeue(&head);
    stampaPila(head);
    dequeue(&head);
    stampaPila(head);
    
    while (!is_empty(head)) {
        Node* freee = pop(&head);
        free(freee);
    }

    return 0;
}
