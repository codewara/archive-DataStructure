#include "library.h"

void createList (List *L) {
    (*L).first = NULL;
}

int countNode (List L) {
    int res = 0;
    if (L.first != NULL) {
        Node *point = L.first;
        while (point != NULL) {
            point = point->next;
            res++;
        }
    } return res;
}

void addF (List *L, Details D) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if ((*L).first == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = (*L).first;
    }
    (*L).first = newNode;
    newNode = NULL;
}

void addA (List *L, Details D, Node *prev) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (prev->next == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = prev->next;
    }
    prev->next = newNode;
    newNode = NULL;
}

void addL (List *L, Details D) {
    if ((*L).first == NULL) {
        addF (L, D);
    } else {
        Node *before = (*L).first;
        while (before->next != NULL) {
            before = before->next;
        }
        addA (L, D, before);
    }
}

void delF (List *L) {
    if ((*L).first != NULL) {
        Node *del = (*L).first;
        if (countNode (*L) == 1) {
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
        }
        free (del);
    } 
}

void delA (List *L, Node *before) {
    Node *del = before->next;
    if (del != NULL) {
        if (del->next == NULL) {
            before->next = NULL;
        } else {
            before->next = del->next;
            del->next = NULL;
        }
        free (del);
    }
}

void delL (List *L) {
    if ((*L).first != NULL) {
        if (countNode (*L) == 1) {
            delF (L);
        } else {
            Node *last = (*L).first;
            Node *before;
            while (last->next != NULL) {
                before = last;
                last = last->next;
            }
            delA (L, before);
        }
    }
}

void printList (List L) {
    printf("+-------------------------------------+\n");
    printf("| Informasi Suhu Negara Teman-Temanku |\n");
    printf("+-------------------------------------+\n");
    if (L.first != NULL) {
        Node *point = L.first;
        while (point != NULL) {
            printf ("> %s lagi di %s yang suhunya %d Celsius.\n", point->detail.nama, point->detail.negara, (point->detail.suhu - 32) * 5 / 9);
            point = point->next;
        }
    } else {
        printf ("> Data not found.\n");
    }
    printf ("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
}