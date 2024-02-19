#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

    int value;
    struct node* next;

}Node;

bool is_empty(Node* head) {
    return head == NULL;
}

void enqueue(Node** head, Node** tail, Node* elem) {
    if (is_empty(*head)) {
        *head = elem;
    } else {
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Node* dequeue(Node** head, Node** tail) {
    Node* ret = *head;
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

void visualizeQueue(Node* head) {
    printf("Queue:\n");
    Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}


int main(){

    Node* head;
    

}