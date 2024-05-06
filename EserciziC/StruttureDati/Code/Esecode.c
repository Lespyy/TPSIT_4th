#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
author: Danilo Rinaldi
date: 26/01/2024
es: 013
text: esempio coda in c
*/

typedef struct code {
    int num;
    struct code* next;
} Code;

bool is_empty(Code* cod) {
    return cod == NULL;
}

void enqueue(Code** head, Code** tail, Code* element) {
    if (is_empty(*head)) {
        *head = element;
    } else {
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}


Code* dequeue(Code** head, Code** tail) {
    Code* ret = *head;
    if (is_empty(*head)) {
        return NULL;
    } else {
        *head = ret->next;
    }
    if (is_empty(*head)) {
        *tail = NULL;
    }
    return ret;
}


void stampaCoda(Code* head) {
    Code* l = head;
    while (l != NULL) {
        printf("%d\n", l->num);
        l = l->next;
    }
}

int contaCoda(Code** head, Code** tail){
    int cont = 0;
    Code* l = *head;
    while (l->next != NULL) {
        cont++;
        l = dequeue(head, tail);
    }
    return cont;
}

int main() {
    Code* head = NULL;
    Code* tail = NULL;
    Code* c1 = (Code*)malloc(sizeof(Code));
    Code* c2 = (Code*)malloc(sizeof(Code));
    Code* c3 = (Code*)malloc(sizeof(Code));

    c1->num = 1;
    c2->num = 2;
    c3->num = 3;

    enqueue(&head, &tail, c1);
    enqueue(&head, &tail, c2);
    enqueue(&head, &tail, c3);

    printf("Queue elements:\n");
    stampaCoda(head);

    int cont = contaCoda(&head, &tail);

    printf("cont = %d", cont);

    return 0;
}
