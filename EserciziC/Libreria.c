#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct Pila {
    int num;
    struct Pila* next;
} Pila;

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

//Liste

typedef struct node {
    int value;
    struct node* next;
} Node;

// Funzione per calcolare la lunghezza della lista in modo ricorsivo
int CalcolaLunghezzaRicorsiva(Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + CalcolaLunghezzaRicorsiva(head->next);
}

// Funzione per eliminare l'ultimo elemento della lista
void EliminaUltimoElemento(Node** lista) {
    if (*lista == NULL) {
        return;
    }

    Node* l = *lista;
    Node* l2 = NULL;

    while (l->next != NULL) {
        l2 = l;
        l = l->next;
    }

    if (l2 != NULL) {
        l2->next = NULL;
        free(l); // Deallocazione della memoria dell'ultimo nodo
    } else {
        // Se c'è un solo elemento nella lista
        free(*lista);
        *lista = NULL;
    }
}

// Funzione per aggiungere un elemento in fondo alla lista
void AggiungiElementoFondo(Node** lista, int num) {
    Node* l = *lista;

    while (l != NULL && l->next != NULL) {
        l = l->next;
    }

    if (l == NULL) {
        // La lista è vuota, crea un nuovo nodo
        *lista = (Node*)malloc(sizeof(Node));
        l = *lista;
    } else {
        // Altrimenti, crea un nuovo nodo alla fine
        l->next = (Node*)malloc(sizeof(Node));
        l = l->next;
    }

    l->value = num;
    l->next = NULL;
}

// Funzione per aggiungere un elemento all'inizio della lista
void AggiungiElementoInizio(Node** lista, int num) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = num;
    head->next = *lista;
    *lista = head;
}

//code

typedef struct node {
    int value;
    struct node* next;
} Node;

int is_empty(Node *head) {
    return head == NULL;
}

void enqueue(Node **head, Node **tail, Node *element){
    if (is_empty(*head)){
        *head = element;
    } else {
        (*tail)->next = element;
    }
    *tail = element;
    element->next = NULL;
}

struct Node *dequeue(Node **head, Node **tail){
    Node *ret = *head;

    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head == NULL){
        *tail = NULL;
    }

    return ret;
}
