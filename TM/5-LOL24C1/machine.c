#include "library.h"

/* ---------- CREATE NODE ---------- */

void createList (List *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

void createSList (PNode *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

/* ----------  ADD  NODE  ---------- */

void addFP (List *L, PDetail D) {
    PNode *newNode = (PNode *) malloc (sizeof (PNode));
    newNode->detail = D;

    createSList (newNode);
    if (!(*L).head) {
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

void addFS (PNode *L, SDetail D) {
    SNode *newNode = (SNode *) malloc (sizeof (SNode));
    newNode->detail = D;

    if (!(*L).head) {
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

void addAP (List *L, PDetail D, PNode *before) {
    PNode *newNode = (PNode *) malloc (sizeof (PNode));
    newNode->detail = D;

    createSList (newNode);
    if (!before->next) {
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

void addAS (PNode *L, SDetail D, SNode *before) {
    SNode *newNode = (SNode *) malloc (sizeof (SNode));
    newNode->detail = D;

    if (!before->next) {
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

void addLP (List *L, PDetail D) {
    if (!(*L).head) {
        addFP (L, D);
    } else {
        addAP (L, D, (*L).tail);
    }
}

void addLS (PNode *L, SDetail D) {
    if (!(*L).head) {
        addFS (L, D);
    } else {
        addAS (L, D, (*L).tail);
    }
}

/* ---------- DELETE NODE ---------- */

void delFS (PNode *L) {
    if ((*L).head) {
        SNode *del = (*L).head;

        if (!(*L).head->next) {
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

void delAS (PNode *L, SNode *before) {
    if (before) {
        SNode *del = before->next;
        if (del) {
            if (!del->next) {
                before->next = NULL;
                (*L).tail = before;
            } else {
                before->next = del->next;
                del->next->prev = before;
                del->next = NULL;
            }
            del->prev = NULL;
            free(del);
        }
    }
}

void delLS (PNode *L) {
    if ((*L).head) {
        if (!(*L).head->next) {
            delFS (L);
        } else {
            delAS (L, (*L).tail->prev);
        }
    }
}

void delAllS (PNode *L) {
    while ((*L).head) {
        delFS (L);
    }
}

void delFP (List *L) {
    if ((*L).head) {
        PNode *del = (*L).head;
        if (del->head) delAllS (del);
        if (!(*L).head->next) {
            (*L).head = NULL;
            (*L).tail = NULL;
        } else {
            (*L).head = (*L).head->next;
            (*L).head->prev = NULL;
            del->next = NULL;
        }
    } 
}

void delAP (List *L, PNode *before) {
    if (before) {
        PNode *del = before->next;
        if (del->head) delAllS (del);
        if (del) {
            if (!del->next) {
                before->next = NULL;
                (*L).tail = before;
            } else {
                before->next = del->next;
                del->next->prev = before;
                del->next = NULL;
            }
            del->prev = NULL;
            free(del);
        }
    }
}

void delLP (List *L) {
    if ((*L).head) {
        PNode *del = (*L).tail;
        if (del->head) delAllS (del);
        if (!(*L).head->next) {
            delFP (L);
        } else {
            delAP (L, (*L).tail->prev);
        }
    }
}

void delAllP (List *L) {
    while ((*L).head) {
        delLP (L);
    }
}

void printList (List L) {
    if (L.head) {
        PNode *Ppoint = L.head;
        int num = 1;
        while (Ppoint) {
            printf ("%s:\n", Ppoint->detail.name);
            SNode *Spoint = Ppoint->head;
            while (Spoint) {
                printf ("| - %s dengan %d persen\n", Spoint->detail.name, Spoint->detail.percentage);
                Spoint = Spoint->next;
            }
            Ppoint = Ppoint->next;
            num++;
        }
    } else printf ("List habis deh :(\n");
}