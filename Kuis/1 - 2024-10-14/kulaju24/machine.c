#include "library.h"

// fungsi untuk membuat list
void createList (List *L) {
    
    // inisialisasi head dan tail list
    (*L).head = -1;
    (*L).tail = -1;

    // inisialisasi prev dan next node
    for (int i = 0; i < MAX; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

// fungsi untuk menghitung jumlah node
int countNode (List L) {
    int res = 0;
    if (L.head != -1) {                     // jika list tidak kosong
        int count = L.head;
        while (count != -1) {                   // loop sampai node terakhir
            res++;
            count = L.data[count].next;
        }
    } return res;                           // return jumlah node
}

// fungsi untuk mencari node kosong
int emptyNode (List L) {
    int res = -1;
    if (countNode (L) < MAX) {              // jika list belum penuh
        int found = 0, i = 0;
        while (found == 0 && i < MAX) {         // loop sampai node kosong ditemukan
            if (L.data[i].next == -2) {
                res = i; found = 1;                     // jika ditemukan node kosong, simpan indeksnya
            } else i++;                             // jika tidak, pindah ke node berikutnya
        }
    } return res;                           // return indeks node kosong
}

// fungsi untuk menambahkan node di depan
void addF (List *L, Details D) {
    if (countNode (*L) < MAX) {             // jika list belum penuh
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).head == -1) {                  // jika list kosong
            (*L).data[newNode].prev = -1;
            (*L).data[newNode].next = -1;
            (*L).tail = newNode;
        } else {                                // jika list tidak kosong
            (*L).data[newNode].prev = -1;
            (*L).data[newNode].next = (*L).head;
            (*L).data[(*L).head].prev = newNode;
        } (*L).head = newNode;
    }
}

// fungsi untuk menambahkan node di belakang
void addA (List *L, Details D, int before) {
    if (countNode (*L) < MAX) {             // jika list belum penuh
        int newNode = emptyNode (*L);
        (*L).data[newNode].detail = D;
        if ((*L).data[before].next != -1) {     // jika node bukan node terakhir
            (*L).data[newNode].prev = before;
            (*L).data[newNode].next = (*L).data[before].next;
            (*L).data[before].next = newNode;
            (*L).data[(*L).data[newNode].next].prev = newNode;
        } else {                                // jika node adalah node terakhir
            (*L).data[newNode].prev = before;
            (*L).data[before].next = newNode;
            (*L).data[newNode].next = -1;
            (*L).tail = newNode;
        }
    }
}

// fungsi untuk menambahkan node di belakang
void addL (List *L, Details D) {
    if ((*L).head == -1) {
        addF (L, D);                        // jika list kosong, tambahkan node di depan
    } else {
        addA (L, D, (*L).tail);             // jika list tidak kosong, tambahkan node di belakang
    }
}

// fungsi untuk memindahkan node ke paling atas
void moveTop (List *L, int point) {

    // jika node bukan node paling atas
    if (point != (*L).head) {
        if (point == (*L).tail) {           // jika node adalah node paling bawah
            (*L).tail = (*L).data[point].prev;
            (*L).data[(*L).data[point].prev].next = -1;
        } else {                            // jika node bukan node paling bawah
            (*L).data[(*L).data[point].prev].next = (*L).data[point].next;
            (*L).data[(*L).data[point].next].prev = (*L).data[point].prev;
        }
        (*L).data[point].prev = -1;
        (*L).data[point].next = (*L).head;
        (*L).data[(*L).head].prev = point;
        (*L).head = point;
    }
}

// fungsi untuk mengubah urutan list berdasarkan kelayakan
void rearrange (List *L) {
    if ((*L).head != -1) {
        int point = (*L).head;

        // loop untuk memindahkan node layak ke paling atas
        while (point != -1) {
            int temp = (*L).data[point].next;   // simpan next node

            // jika node layak, pindahkan ke paling atas
            if (strcmp ((*L).data[point].detail.expired, "layak") == 0) {
                moveTop (L, point);
            } point = temp;                     // pindah ke next node
        }
    }
}

// fungsi untuk mencetak list
void printList (List L) {
    if (L.head != -1) {
        int point;

        // cetak list layak jual dari depan
        point = L.head;
        printf ("Kue Layak Jual:\n");
        while (point != -1) {
            if (strcmp (L.data[point].detail.expired, "layak") == 0) {
                printf ("%s %s %s\n", L.data[point].detail.code, L.data[point].detail.pemesan, L.data[point].detail.expired);
            } point = L.data[point].next;
        }

        // cetak list kadaluarsa dari belakang
        point = L.tail;
        printf ("\nKue Kadaluarsa:\n");
        while (point != -1) {
            if (strcmp (L.data[point].detail.expired, "kadaluarsa") == 0) {
                printf ("%s %s %s\n", L.data[point].detail.code, L.data[point].detail.pemesan, L.data[point].detail.expired);
            } point = L.data[point].prev;
        }
    }
}