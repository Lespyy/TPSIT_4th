/*
Nei Pronto Soccorsi dell’ospedale i pazienti sono classificati con un colore: 
rosso (urgentissimo)
giallo (grave)
verde (moderato)
bianco (lieve). 
Funziona così: quando una persona arriva al pronto soccorso l’infermiere 
lo registra (nome e età) 
e decide anche il colore di priorità; 
appena un medico è libero deve gestire prima quelli 
con codice rosso, poi giallo, poi verde e poi bianco. 
Dichiara una struttura Paziente con i campi:
Nome,
Età,
Colore;
il programma deve gestire 4 code diverse e inserire il paziente nella lista corretta, quando un medico è libero entra il paziente successivo, (quindi sceglie il primo dei pazienti codice verde solo se non ci sono codici rosso e giallo).
Le informazioni vanno visualizzate a schermo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct paziente {
    char* nome;
    int eta;
    char Colore;
    struct paziente* next;
} Paziente;

int is_empty(Paziente* head) {
    return head == NULL;
}

void enqueue(Paziente** head, Paziente** tail, Paziente* elem) {
    if (is_empty(*head)) {
        *head = elem;
    } else {
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Paziente* dequeue(Paziente** head, Paziente** tail) {
    Paziente* ret = *head;
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

void eseguiCoda(Paziente** head, Paziente** tail) {
    Paziente* attuale;

    // Dequeue and print red patients
    while ((attuale = dequeue(head, tail)) != NULL && attuale->Colore == 'R') {
        printf("Paziente: %s, %d, %c\n", attuale->nome, attuale->eta, attuale->Colore);
        free(attuale->nome);
        free(attuale);
    }

    // Dequeue and print yellow patients
    while ((attuale = dequeue(head, tail)) != NULL && attuale->Colore == 'G') {
        printf("Paziente: %s, %d, %c\n", attuale->nome, attuale->eta, attuale->Colore);
        free(attuale->nome);
        free(attuale);
    }

    // Dequeue and print green patients
    while ((attuale = dequeue(head, tail)) != NULL && attuale->Colore == 'Y') {
        printf("Paziente: %s, %d, %c\n", attuale->nome, attuale->eta, attuale->Colore);
        free(attuale->nome);
        free(attuale);
    }

    // Dequeue and print white patients
    while ((attuale = dequeue(head, tail)) != NULL && attuale->Colore == 'W') {
        printf("Paziente: %s, %d, %c\n", attuale->nome, attuale->eta, attuale->Colore);
        free(attuale->nome);
        free(attuale);
    }
}

void visualizzaCoda(Paziente* head) {
    Paziente* h = head;
    printf("Coda: \n");
    while (h != NULL) {
        printf("%s, %d, %c\n", h->nome, h->eta, h->Colore);
        h = h->next;
    }
}

int main() {
    Paziente* head = NULL;
    Paziente* tail = NULL;

    Paziente* p1 = (Paziente*)malloc(sizeof(Paziente));
    p1->nome = strdup("Danilo");
    p1->eta = 17;
    p1->Colore = 'R';
    p1->next = NULL;

    Paziente* p2 = (Paziente*)malloc(sizeof(Paziente));
    p2->nome = strdup("Giulia");
    p2->eta = 25;
    p2->Colore = 'G';
    p2->next = NULL;

    enqueue(&head, &tail, p1);
    enqueue(&head, &tail, p2);

    visualizzaCoda(head);

    eseguiCoda(&head, &tail);


    return 0;
}

