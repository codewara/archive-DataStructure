#include "library.h"

void createList (List *L) {
    (*L).head = -1;
    (*L).tail = -1;
    for (int i = 0; i < 7; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countNode (List L) {
    int res = 0;
    if (L.head != -1) {
        int help = L.head;
        while (help != -1) {
            res++;
            help = L.data[help].next;
        }
    } return res;
}

int emptyNode (List L) {
    int res = -1;
    if (countNode (L) < 7) {
        int found = 0, i = 0;
        while (found == 0 && i < 7) {
            if (L.data[i].next == -2) {
                res = i;
                found = 1;
            } else i++;
        }
    } return res;
}

void addF (List *L, Details D) {
    if (countNode (*L) < 7) {
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).head == -1) {
            (*L).data[newNode].prev = -1;
            (*L).data[newNode].next = -1;
            (*L).tail = newNode;
        } else {
            (*L).data[newNode].prev = -1;
            (*L).data[newNode].next = (*L).head;
            (*L).data[(*L).head].prev = newNode;
        } (*L).head = newNode;
    }
}

void addA (List *L, Details D, int before) {
    if (countNode (*L) < 7) {
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).data[before].next != -1) {
            (*L).data[newNode].prev = before;
            (*L).data[newNode].next = (*L).data[before].next;
            (*L).data[before].next = newNode;
            (*L).data[(*L).data[newNode].next].prev = newNode;
        } else {
            (*L).data[newNode].prev = before;
            (*L).data[before].next = newNode;
            (*L).data[newNode].next = -1;
            (*L).tail = newNode;
        }
    }
}

void addL (List *L, Details D) {
    if ((*L).head == -1) {
        addF (L, D);
    } else {
        addA (L, D, (*L).tail);
    }
}

void delF (List *L) {
    if ((*L).head != -1) {
        int del = (*L).head;
        if (countNode (*L) == 1) {
            (*L).head = -1;
            (*L).tail = -1;
        } else {
            (*L).head = (*L).data[(*L).head].next;
            (*L).data[(*L).head].prev = -1;
        }
        (*L).data[del].prev = -2;
        (*L).data[del].next = -2;
    }
}

void delA (List *L, int before) {
    int del = (*L).data[before].next;
    if (del != -1) {
        if ((*L).data[del].next == -1) {
            (*L).tail = before;
            (*L).data[before].next = -1;
        } else {
            (*L).data[before].next = (*L).data[del].next;
            (*L).data[(*L).data[del].next].prev = before;
        }
        (*L).data[del].prev = -2;
        (*L).data[del].next = -2;
    }
}

void delL (List *L) {
    if ((*L).head != -1) {
        if (countNode (*L) == 1) {
            delF (L);
        } else {
            delA (L, (*L).data[(*L).tail].prev);
        }
    }
}

void delAll (List *L) {
    if ((*L).head != -1) {
        int point = (*L).head;
        while (point != -1) {
            int del = point;
            point = (*L).data[point].next;
            (*L).data[del].prev = -2;
            (*L).data[del].next = -2;
        } (*L).head = -1;
        (*L).tail = -1;
    }
}

void printList (List L) {
    printf("+-------------------------------------+\n");
    printf("|   Los Pollos Hermanos Orders List   |\n");
    printf("+-------------------------------------+\n");
    if (L.head != -1) {
        int point = L.head;
        int i = 1;
        while (point != -1) {
            printf ("| %d. %s %d %s\n", i, L.data[point].detail.menu, L.data[point].detail.harga, L.data[point].detail.pemesan);
            point = L.data[point].next;
            i++;
        }
    } else {
        printf ("| - Relax, no orders at the moment\n");
    }
    printf ("+-------------------------------------+\n");
}

void printReverse (List L) {
    printf("+-------------------------------------+\n");
    printf("|   Los Pollos Hermanos Orders List   |\n");
    printf("+-------------------------------------+\n");
    if (L.head != -1) {
        int point = L.tail;
        int i = 1;
        while (point != -1) {
            printf ("| %d. %s %d %s\n", i, L.data[point].detail.menu, L.data[point].detail.harga, L.data[point].detail.pemesan);
            point = L.data[point].prev;
            i++;
        }
    } else {
        printf ("| - Relax, no orders at the moment\n");
    }
    printf ("+-------------------------------------+\n");
}