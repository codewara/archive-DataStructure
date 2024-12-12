#include "library.h"

void createStack (Stack *S) {
    S->top = NULL;
}

void push (Stack *S, Details D) {
    Node *newNode = (Node*) malloc (sizeof(Node));
    newNode->detail = D;
    if (!S->top) {
        newNode->next = NULL;
    } else {
        newNode->next = S->top;
    }
    S->top = newNode;
    newNode = NULL;
}

void pop (Stack *S) {
    if (S->top) {
        Node *del = S->top;
        if (del->next) {
            S->top = del->next;
        } else {
            S->top = NULL;
        }
        free(del);
    }
}

void move (Stack *S1, Stack *S2) {
    if (S1->top) {
        Node *del = S1->top;
        if (del->next) {
            S1->top = del->next;
        } else {
            S1->top = NULL;
        }
        if (!S2->top) {
            del->next = NULL;
        } else {
            del->next = S2->top;
        }
        S2->top = del;
        del = NULL;
    }
}

void printStack (Stack S1, Stack S2) {
    printf("Buku di S1:\n");
    Node *curr = S1.top;
    if (!curr) {
        printf("- KoShong!!!l\n");
    } else {
        int num = 1;
        while (curr) {
            printf("%d. %s %s Rp.%d\n", num, curr->detail.title, curr->detail.category, curr->detail.price);
            num++;
            curr = curr->next;
        }
    }
    
    printf("\nBuku di S2:\n");
    curr = S2.top;
    if (!curr) {
        printf("- KoShongg!!!\n");
    } else {
        int num = 1;
        while (curr) {
            printf("%d. %s %s Rp.%d\n", num, curr->detail.title, curr->detail.category, curr->detail.price);
            num++;
            curr = curr->next;
        }
    }
}