#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int numero;
    struct Node* next;
} Node;

typedef Node Queue;

int is_empty(Queue* head) {
    return head == NULL;
}

void enqueue(Queue** head, Queue** tail, int num) {
    Node* elem = (Node*)malloc(sizeof(Node));
    elem->numero = num;
    elem->next = NULL;

    if (is_empty(*head) || num % 2 == 0) {
        // If the queue is empty or the number is even, insert at the front
        elem->next = *head;
        *head = elem;

        if (is_empty(*tail)) {
            // If the queue was empty, update the tail
            *tail = elem;
        }
    } else {
        // If the number is odd, insert at the end
        (*tail)->next = elem;
        *tail = elem;
    }
}

int dequeue(Queue** head, Queue** tail) {
    if (is_empty(*head)) {
        return -1;  // Indicate an empty queue
    }

    Node* ret = *head;
    int num = ret->numero;

    *head = ret->next;
    free(ret);

    if (*head == NULL) {
        *tail = NULL;
    }

    return num;
}

void visualizeQueue(Queue* head) {
    printf("Queue:\n");
    Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->numero);
        current = current->next;
    }
}

int main() {
    Queue* head = NULL;
    Queue* tail = NULL;

    printf("Enter a series of numbers that stops with a non-positive number:\n");
    int num;
    do {
        scanf("%d", &num);
        if (num > 0) {
            enqueue(&head, &tail, num);
        }
    } while (num > 0);

    visualizeQueue(head);

    // Free the memory for the queue
    while (!is_empty(head)) {
        dequeue(&head, &tail);
    }

    return 0;
}
