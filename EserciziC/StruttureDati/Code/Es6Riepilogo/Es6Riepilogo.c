#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pila {
    int num;
    struct Pila* next;
} Pila;

typedef struct Coda {
    int num;
    struct Coda* next;
} Coda;

int is_empty(Coda* head) {
    return head == NULL;
}

Coda* dequeue(Coda** head, Coda** tail) {
    Coda* ret = *head;
    if (is_empty(*head)) {
        return NULL;
    } else {
        *head = ret->next;
    }
    if (*head == NULL) {
        *tail = NULL;
    }
    return ret;
}

void enqueue(Coda** head, Coda** tail, Coda* elem) {
    if (is_empty(*head)) {
        *head = elem;
    } else {
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

void visualizzaCoda(Coda* head) {
    Coda* h = head;
    printf("Coda: \n");
    while (h != NULL) {
        printf("%d\n", h->num);
        h = h->next;
    }
}

void push(Pila** head, Pila* element) {
    if (is_empty(*head)) {
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Pila* pop(Pila** head) {
    Pila* ret = *head;
    if (is_empty(*head)) {
        return NULL;
    } else {
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Pila* head) {
    Pila* l = head;
    printf("\nPila: ");
    while (l != NULL) {
        printf("%d ", l->num);
        l = l->next;
    }
}

bool confrontoCode(Coda* coda1, Coda* coda2) {
    while (coda1 != NULL && coda2 != NULL) {
        if (coda1->num != coda2->num) {
            return false;
        }
        coda1 = coda1->next;
        coda2 = coda2->next;
    }

    return (coda1 == NULL && coda2 == NULL);
}

int main() {
    Coda* headCoda1 = NULL;
    Coda* tailCoda1 = NULL;
    Coda* headCoda2 = NULL;
    Coda* tailCoda2 = NULL;
    Pila* headPila = NULL;

    enqueue(&headCoda1, &tailCoda1, (Coda*)malloc(sizeof(Coda)));
    headCoda1->num = 1;

    enqueue(&headCoda1, &tailCoda1, (Coda*)malloc(sizeof(Coda)));
    headCoda1->num = 2;

    enqueue(&headCoda2, &tailCoda2, (Coda*)malloc(sizeof(Coda)));
    headCoda2->num = 1;

    push(&headPila, (Pila*)malloc(sizeof(Pila)));
    headPila->num = 3;


    visualizzaCoda(headCoda1);
    visualizzaCoda(headCoda2);
    stampaPila(headPila);

    
    if (confrontoCode(headCoda1, headCoda2)) {
        printf("\nLe code sono uguali.\n");
    } else {
        printf("\nLe code sono diverse.\n");
    }

    
    Coda* extractedElem = dequeue(&headCoda1, &tailCoda1);
    if (extractedElem != NULL) {
        printf("\nElemento estratto dalla coda: %d\n", extractedElem->num);
        free(extractedElem);
    }

    Pila* poppedElem = pop(&headPila);
    if (poppedElem != NULL) {
        printf("Elemento estratto dalla pila: %d\n", poppedElem->num);
        free(poppedElem);
    }

    
    visualizzaCoda(headCoda1);
    visualizzaCoda(headCoda2);
    stampaPila(headPila);

    return 0;
}
