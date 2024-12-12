#include "library.h"

/* ---------- CREATE NODE ---------- */

// prosedur membuat list
void createList (List *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

// prosedur membuat sublist
void createSList (PNode *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

/* ----------- ADD  NODE ----------- */

// prosedur menambahkan node di awal list
void addFP (List *L, PDetail D) {
    // alokasi memori untuk node baru
    PNode *newNode = (PNode *) malloc (sizeof (PNode));
    newNode->detail = D;

    // buat sublist baru
    createSList (newNode);
    if (!(*L).head) {                   // jika list kosong
        newNode->next = NULL;
        newNode->prev = NULL;
        (*L).tail = newNode;
    } else {                            // jika list tidak kosong
        newNode->next = (*L).head;
        newNode->prev = NULL;
        (*L).head->prev = newNode;
    }
    (*L).head = newNode;
    newNode = NULL;
}

// prosedur menambahkan node di awal sublist
void addFS (PNode *L, SDetail D) {
    // alokasi memori untuk node baru
    SNode *newNode = (SNode *) malloc (sizeof (SNode));
    newNode->detail = D;

    if (!(*L).head) {                   // jika sublist kosong
        newNode->next = NULL;
        newNode->prev = NULL;
        (*L).tail = newNode;
    } else {                            // jika sublist tidak kosong
        newNode->next = (*L).head;
        newNode->prev = NULL;
        (*L).head->prev = newNode;
    }
    (*L).head = newNode;
    newNode = NULL;
}

// prosedur menambahkan node di tengah list
void addAP (List *L, PDetail D, PNode *before) {
    // alokasi memori untuk node baru
    PNode *newNode = (PNode *) malloc (sizeof (PNode));
    newNode->detail = D;

    // buat sublist baru
    createSList (newNode);
    if (!before->next) {                // jika node sebelumnya adalah node terakhir
        newNode->next = NULL;
        (*L).tail = newNode;
    } else {                            // jika node sebelumnya bukan node terakhir
        newNode->next = before->next;
        newNode->next->prev = newNode;
    }
    newNode->prev = before;
    before->next = newNode;
    newNode = NULL;
}

// prosedur menambahkan node di tengah sublist
void addAS (PNode *L, SDetail D, SNode *before) {
    // alokasi memori untuk node baru
    SNode *newNode = (SNode *) malloc (sizeof (SNode));
    newNode->detail = D;

    if (!before->next) {                // jika node sebelumnya adalah node terakhir
        newNode->next = NULL;
        (*L).tail = newNode;
    } else {                            // jika node sebelumnya bukan node terakhir
        newNode->next = before->next;
        newNode->next->prev = newNode;
    }
    newNode->prev = before;
    before->next = newNode;
    newNode = NULL;
}

// prosedur menambahkan node di akhir list
void addLP (List *L, PDetail D) {
    if (!(*L).head) {
        addFP (L, D);                       // jika list kosong, tambahkan di awal list
    } else {
        addAP (L, D, (*L).tail);            // jika list tidak kosong, tambahkan di akhir list
    }
}

// prosedur menambahkan node di akhir sublist
void addLS (PNode *L, SDetail D) {
    if (!(*L).head) {
        addFS (L, D);                       // jika sublist kosong, tambahkan di awal sublist
    } else {
        addAS (L, D, (*L).tail);            // jika sublist tidak kosong, tambahkan di akhir sublist
    }
}

/* ---------- DELETE NODE ---------- */

// prosedur menghapus node di awal sublist
void delFS (PNode *L) {
    if ((*L).head) {                    // jika sublist tidak kosong
        SNode *del = (*L).head;             // simpan node yang akan dihapus

        if (!(*L).head->next) {             // jika node yang dihapus adalah node terakhir
            (*L).head = NULL;
            (*L).tail = NULL;
        } else {                            // jika node yang dihapus bukan node terakhir
            (*L).head = (*L).head->next;
            (*L).head->prev = NULL;
            del->next = NULL;
        }
        free (del);                         // dealokasi/hapus node
    } 
}

// prosedur menghapus node di tengah sublist
void delAS (PNode *L, SNode *before) {
    if (before) {                       // jika node sebelumnya ada
        SNode *del = before->next;          // simpan node yang akan dihapus

        if (del) {                          // jika node yang akan dihapus ada
            if (!del->next) {                   // jika node yang dihapus adalah node terakhir
                before->next = NULL;
                (*L).tail = before;
            } else {                            // jika node yang dihapus bukan node terakhir
                before->next = del->next;
                del->next->prev = before;
                del->next = NULL;
            }
            del->prev = NULL;
            free(del);                          // dealokasi/hapus node
        }
    }
}

// prosedur menghapus node di akhir sublist
void delLS (PNode *L) {
    if ((*L).head) {                    // jika sublist tidak kosong
        if (!(*L).head->next) {
            delFS (L);                          // jika node yang dihapus adalah node terakhir, hapus di awal sublist
        } else {
            delAS (L, (*L).tail->prev);         // jika node yang dihapus bukan node terakhir, hapus di akhir sublist
        }
    }
}

// prosedur menghapus semua node di sublist
void delAllS (PNode *L) {
    while ((*L).head) {
        delFS (L);                          // selama node masih ada, hapus node dari awal sublist
    }
}

// prosedur menghapus node di awal list
void delFP (List *L) {
    if ((*L).head) {                    // jika list tidak kosong
        PNode *del = (*L).head;             // simpan node yang akan dihapus
        
        // jika sublist tidak kosong, hapus semua node di sublist
        if (del->head) delAllS (del);

        if (!(*L).head->next) {             // jika node yang dihapus adalah node terakhir
            (*L).head = NULL;
            (*L).tail = NULL;
        } else {                            // jika node yang dihapus bukan node terakhir
            (*L).head = (*L).head->next;
            (*L).head->prev = NULL;
            del->next = NULL;
        }
        free (del);                         // dealokasi/hapus node
    } 
}

// prosedur menghapus node di tengah list
void delAP (List *L, PNode *before) {
    if (before) {                           // jika node sebelumnya ada
        PNode *del = before->next;              // simpan node yang akan dihapus
        
        // jika sublist tidak kosong, hapus semua node di sublist
        if (del->head) delAllS (del);

        if (del) {                              // jika node yang akan dihapus ada
            if (!del->next) {                       // jika node yang dihapus adalah node terakhir
                before->next = NULL;
                (*L).tail = before;
            } else {                                // jika node yang dihapus bukan node terakhir
                before->next = del->next;
                del->next->prev = before;
                del->next = NULL;
            }
            del->prev = NULL;
            free(del);                              // dealokasi/hapus node
        }
    }
}

// prosedur menghapus node di akhir list
void delLP (List *L) {
    if ((*L).head) {                        // jika list tidak kosong
        
        PNode *del = (*L).tail;                 // simpan node yang akan dihapus

        // jika sublist tidak kosong, hapus semua node di sublist
        if (del->head) delAllS (del);

        if (!(*L).head->next) {
            delFP (L);                              // jika node yang dihapus adalah node terakhir, hapus di awal list
        } else {
            delAP (L, (*L).tail->prev);             // jika node yang dihapus bukan node terakhir, hapus di akhir list
        }
    }
}

// prosedur menghapus semua node di list
void delAllP (List *L) {
    while ((*L).head) {
        delLP (L);                              // selama node masih ada, hapus node dari awal list
    }
}

/* ---------- PRINT  LIST ---------- */

// prosedur mencetak list
void printList (List L) {
    if (L.head) {                           // jika list tidak kosong
        PNode *Ppoint = L.head;
        while (Ppoint) {                        // selama list node masih ada
            if (Ppoint->head) {                     // jika sublist tidak kosong

                // jika list node sebelumnya ada, cetak spasi
                if (Ppoint->prev) printf ("\n");

                // cetak node list
                printf ("%s %d\n", Ppoint->detail.name, Ppoint->detail.market);
                SNode *Spoint = Ppoint->head;
                while (Spoint) {                        // selama sublist node masih ada

                    // cetak node sublist
                    printf ("- %s %d\n", Spoint->detail.name, Spoint->detail.year);
                    Spoint = Spoint->next;                  // pindah ke sublist node berikutnya
                }
            } Ppoint = Ppoint->next;                    // pindah ke list node berikutnya
        }
    }
}

/* ------ ADDITIONAL FUNCTION ------ */

// fungsi mencari node di list
PNode *getP (List L, char *name) {
    PNode *Ppoint = L.head;

    // selama list node masih ada dan nama tidak sama, pindah ke list node berikutnya
    while (Ppoint && strcmp (Ppoint->detail.name, name) != 0) Ppoint = Ppoint->next;
    return Ppoint;                          // kembalikan list node yang ditemukan
}

// prosedur memindahkan sublist dari node ke node lain
void move (SDetail D, PNode *src, PNode *dest) {
    SNode *Spoint = src->head;

    // selama sublist node masih ada dan nama tidak sama, pindah ke sublist node berikutnya
    while (Spoint && strcmp (Spoint->detail.name, D.name) != 0) Spoint = Spoint->next;

    if (Spoint) {                           // jika sublist node ditemukan

        // lepaskan sublist node dari node sebelumnya
        if (!Spoint->prev) {                    // jika node sebelumnya tidak ada
            src->head = Spoint->next;
            if (Spoint->next) Spoint->next->prev = NULL;
        } else {                                // jika node sebelumnya ada
            Spoint->prev->next = Spoint->next;
            if (Spoint->next) Spoint->next->prev = Spoint->prev;
        }

        // lepaskan sublist node dari node setelahnya
        if (!Spoint->next) {                    // jika node setelahnya tidak ada
            src->tail = Spoint->prev;
        } Spoint->prev = NULL;
        Spoint->next = NULL;

        // ubah tahun pada node
        Spoint->detail.year = D.year;
        
        // pasangkan sublist node ke node lain
        if (!(*dest).head) {                    // jika sublist node kosong
            Spoint->next = NULL;
            Spoint->prev = NULL;
            (*dest).tail = Spoint;
        } else {                                // jika sublist node tidak kosong
            Spoint->next = (*dest).head;
            Spoint->prev = NULL;
            (*dest).head->prev = Spoint;
        }
        (*dest).head = Spoint;
        Spoint = NULL;                          // kosongkan pointer
    }
}