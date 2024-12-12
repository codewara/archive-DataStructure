#include "library.h"

void createQueue (Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

void add (Queue *Q, Details D) {
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->detail = D;
    newNode->next = NULL;

    if (!Q->head) Q->head = newNode;
    else Q->tail->next = newNode;
    Q->tail = newNode;
    newNode = NULL;
}

void addprior (Queue *Q, Details D) {
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->detail = D;
    newNode->next = NULL;

    if (!Q->head) {
        Q->head = newNode;
        Q->tail = newNode;
    } else {
        if (Q->head->detail.ticket > D.ticket) {
            newNode->next = Q->head;
            Q->head = newNode;
        } else {
            Node *curr = Q->head;
            while (curr->next && curr->next->detail.ticket < D.ticket) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            if (!newNode->next) Q->tail = newNode;
        }
    } newNode = NULL;
}

void del (Queue *Q) {
    if (Q->head) {
        Node *del = Q->head;
        if (!Q->head->next) {
            Q->head = NULL;
            Q->tail = NULL;
        } else {
            Q->head = Q->head->next;
            del->next = NULL;
        } free(del);
    }
}

void move (Queue *Q1, Queue *Q2) {
    if (Q1->head) {
        Node *curr = Q1->head;
        Q1->head = Q1->head->next;
        curr->next = NULL;
        if (!Q2->head) {
            Q2->head = curr;
            Q2->tail = curr;
        } else {
            Q2->tail->next = curr;
            Q2->tail = curr;
        } curr = NULL;
    }
}

void printQueue (Queue Q1, Queue Q2) {
    printf ("******************\n");
    printf ("Queue 1\n");
    printf ("******************\n");
    Node *curr = Q1.head;
    while (curr) {
        printf("%s %d\n", curr->detail.name, curr->detail.ticket);
        curr = curr->next;
    }
    printf ("******************\n");
    printf ("Queve 2\n");
    printf ("******************\n");
    curr = Q2.head;
    while (curr) {
        printf("%s %d\n", curr->detail.name, curr->detail.ticket);
        curr = curr->next;
    }
    printf ("*******************\n");
}