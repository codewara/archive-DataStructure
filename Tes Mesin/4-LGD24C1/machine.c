#include "library.h"

void createList (List *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

int countNode (List L) {
    int count = 0;
    if (L.head != NULL) {
        Node *point = L.head;
        while (point != NULL) {
            count++;
            point = point->next;
        }
    }
    return count;
}

void addF (List *L, Details D) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if ((*L).head == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
        (*L).tail = newNode;
    } else {
        newNode->next = (*L).head;
        newNode->prev = NULL;
        (*L).head->prev = newNode;
    }
    (*L).head = newNode;
    newNode = NULL;
}

void addA (List *L, Details D, Node *before) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (before->next == NULL) {
        newNode->next = NULL;
        (*L).tail = newNode;
    } else {
        newNode->next = before->next;
        newNode->next->prev = newNode;
    }
    newNode->prev = before;
    before->next = newNode;
    newNode = NULL;
}

void addB (List *L, Details D, Node *after) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (after->prev == NULL) {
        newNode->prev = NULL;
        (*L).head = newNode;
    } else {
        newNode->prev = after->prev;
        newNode->prev->next = newNode;
    }
    newNode->next = after;
    after->prev = newNode;
    newNode = NULL;
}

void addL (List *L, Details D) {
    if ((*L).head == NULL) {
        addF (L, D);
    } else {
        addA (L, D, (*L).tail);
    }
}

void delF (List *L) {
    if ((*L).head != NULL) {
        Node *del = (*L).head;
        if (countNode (*L) == 1) {
            (*L).head = NULL;
            (*L).tail = NULL;
        } else {
            (*L).head = (*L).head->next;
            (*L).head->prev = NULL;
            del->next = NULL;
        }
        free (del);
    } 
}

void delA (List *L, Node *before) {
    if (before != NULL && before->next != NULL) {
        Node *del = before->next;
        if (del->next == NULL) {
            before->next = NULL;
            (*L).tail = before;
        } else {
            before->next = del->next;
            del->next->prev = before;
        }
        del->next = NULL;
        del->prev = NULL;
        free(del);
    }
}

void delL (List *L) {
    if ((*L).head != NULL) {
        if (countNode (*L) == 1) {
            delF (L);
        } else {
            delA (L, (*L).tail->prev);
        }
    }
}

void delAll (List *L) {
    for (int i = countNode (*L); i > 0; i--) {
        delL (L);
    }
}

void printList (List L) {
    printf ("+-------------------------------------+\n");
    printf ("|       The Brainrot Song List        |\n");
    printf ("+-------------------------------------+\n");
    if (L.head != NULL) {
        Node *point = L.head;
        int num = 1;
        while (point != NULL) {
            printf ("| %d. %s %d %s\n", num, point->detail.title, point->detail.year, point->detail.singer);
            point = point->next;
            num++;
        }
    } else {
        printf ("| - The playlist is empty\n");
    }
    printf ("+-------------------------------------+\n");
}

void printListR (List L) {
    printf ("+-------------------------------------+\n");
    printf ("|       The Brainrot Song List        |\n");
    printf ("+-------------------------------------+\n");
    if (L.tail != NULL) {
        Node *point = L.tail;
        int num = 1;
        while (point != NULL) {
            printf ("| %d. %s %d %s\n", num, point->detail.title, point->detail.year, point->detail.singer);
            point = point->prev;
            num++;
        }
    } else {
        printf ("| - The playlist is empty\n");
    }
    printf ("+-------------------------------------+\n");
}