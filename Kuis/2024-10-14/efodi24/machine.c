#include "library.h"

// prosedur untuk membuat list
void createList (List *L) {
    (*L).first = NULL;                      // inisialisasi pointer ke node pertama
}

// prosedur untuk menambahkan node di depan
void addF (List *L, Details D) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if ((*L).first == NULL) {               // jika list kosong
        newNode->next = NULL;
    } else {                                // jika list tidak kosong
        newNode->next = (*L).first;
    }
    (*L).first = newNode;
    newNode = NULL;
}

// prosedur untuk menambahkan node di belakang
void addA (List *L, Details D, Node *prev) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (prev->next == NULL) {               // jika node adalah node terakhir
        newNode->next = NULL;
    } else {                                // jika node bukan node terakhir
        newNode->next = prev->next;
    }
    prev->next = newNode;
    newNode = NULL;
}

// prosedur untuk menambahkan node di belakang
void addL (List *L, Details D) {
    if ((*L).first == NULL) {
        addF (L, D);                            // jika list kosong, tambahkan node di depan
    } else {                                // jika list tidak kosong
        Node *before = (*L).first;
        while (before->next != NULL) {          // loop sampai node terakhir
            before = before->next;
        }
        addA (L, D, before);                    // tambahkan node di belakang
    }
}

// prosedur untuk memindahkan node ke paling atas
void moveTop (List *L, Node *point) {
    if (point != (*L).first) {              // jika node bukan node paling atas
        Node *before = (*L).first;
        while (before->next != point) {         // loop sampai node sebelum node yang akan dipindahkan
            before = before->next;
        }
        before->next = point->next;             // hubungkan node sebelum node yang akan dipindahkan dengan node setelahnya
        point->next = (*L).first;
        (*L).first = point;
    }
}

// prosedur untuk mengubah urutan list berdasarkan batas tanggal dan bulan
void rearrange (List *L, int B, int Y) {
    if ((*L).first != NULL) {               // jika list tidak kosong
        Node *point = (*L).first;

        // loop semua node
        while (point != NULL) {
            Node *temp = point->next;
            if ((point->detail.tahun > Y) ||            // jika tahun lebih besar
                (point->detail.tahun == Y &&            // atau tahun sama dan bulan lebih besar
                 point->detail.bulan >= B)) {
                moveTop (L, point);                         // pindahkan node ke paling atas
            } point = temp;                             // pindah ke next node
        }
    }
}

// prosedur untuk mencetak list
void printList (List L) {
    if (L.first != NULL) {
        Node *point = L.first;

        // loop untuk mencetak semua node yang sudah diubah urutannya
        while (point != NULL) {
            printf ("%s %d %d %d\n", point->detail.judul, point->detail.tanggal, point->detail.bulan, point->detail.tahun);
            point = point->next;
        }
    }
}