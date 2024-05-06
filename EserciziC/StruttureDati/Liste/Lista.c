#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int n;
    Node* lista = NULL;
    Node* l;

    do {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);

        if (n >= 0) {
            // Aggiunta di un elemento alla fine della lista
            AggiungiElementoFondo(&lista, n);
        }
    } while (n >= 0);

    l = lista;
    printf("Numeri inseriti:\n");
    while (l != NULL) {
        printf("%d - %p\n", l->value, (void*)l->next);
        l = l->next;
    }
    printf("\n");

    l = lista;

    printf("Lunghezza della lista: %d\n", CalcolaLunghezzaRicorsiva(l));

    // Elimina l'ultimo elemento
    EliminaUltimoElemento(&lista);

    // Aggiungi un elemento all'inizio della lista
    AggiungiElementoInizio(&lista, 999);

    printf("Lista dopo le operazioni:\n");
    l = lista;
    while (l != NULL) {
        printf("%d - %p\n", l->value, (void*)l->next);
        l = l->next;
    }

    // Deallocazione della memoria
    while (lista != NULL) {
        Node* temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}
