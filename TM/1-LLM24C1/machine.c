#include "library.h"

void createList (List *L) {
    (*L).first = -1;
    for (int i = 0; i < MAX; i++) {
        (*L).data[i].next = -2;
    }
}

int countNode (List L) {
    int res = 0;
    if (L.first != -1) {
        int count = L.first;
        while (count != -1) {
            res++;
            count = L.data[count].next;
        }
    } return res;
}

int emptyNode (List L) {
    int res = -1;
    if (countNode (L) < MAX) {
        int found = 0, i = 0;
        while (found == 0 && i < MAX) {
            if (L.data[i].next == -2) {
                res = i;
                found = 1;
            } else i++;
        }
    } return res;
}

void addF (List *L, Details D) {
    if (countNode (*L) < MAX) {
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).first == -1) {
            (*L).data[newNode].next = -1;
        } else {
            (*L).data[newNode].next = (*L).first;
        } (*L).first = newNode;
    }
}

void addA (List *L, Details D, int prev) {
    if (countNode (*L) < MAX) {
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).data[prev].next == -1) {
            (*L).data[newNode].next = -1;
        } else {
            (*L).data[newNode].next = (*L).data[prev].next;
        } (*L).data[prev].next = newNode;
    }
}

void addL (List *L, Details D) {
    if ((*L).first == -1) {
        addF (L, D);
    } else {
        if (countNode (*L) < MAX) {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            } addA (L, D, prev);
        }
    }
}

void delF (List *L) {
    if ((*L).first != -1) {
        int del = (*L).first;
        if (countNode (*L) == 1) {
            (*L).first = -1;
        } else {
            (*L).first = (*L).data[del].next;
        } (*L).data[del].next = -2;
    }
}

void delA (List *L, int prev) {
    int del = (*L).data[prev].next;
    if (del != -1) {
        if ((*L).data[del].next == -1) {
            (*L).data[prev].next = -1;
        } else {
            (*L).data[prev].next = (*L).data[del].next;
        } (*L).data[del].next = -2;
    }
}

void delL (List *L) {
    if ((*L).first != -1) {
        if (countNode (*L) == 1) {
            delF (L);
        } else {
            int del = (*L).first;
            int prev;
            while ((*L).data[del].next != -1) {
                prev = del;
                del = (*L).data[del].next;
            } delA (L, prev);
        }
    }
}

void printList (List L) {
    printf("DATA LARI MAHASISWA\n");
    if (L.first != -1) {
        int point = L.first;
        while (point != -1) {
            printf ("-> %s - %s - %d menit %d detik\n", L.data[point].detail.nama, L.data[point].detail.nim, L.data[point].detail.duration / 60, L.data[point].detail.duration % 60);
            point = L.data[point].next;
        }
    } else printf ("~Ga ada yang lari, pada jompo.~\n");
}