#include "library.h"

// fungsi hitung digit angka
int countDigit (int n) {
    int res = 0;
    if (n == 0) return 1;                                   // jika angka 0, return 1
    else {
        while (n > 0) {                                     // selama digit angka masih ada
            n /= 10;                                            // bagi angka dengan 10
            res++;                                              // increment digit angka
        } return res;
    }
}

// fungsi cek dan bandingkan data untuk sorting
int checkSort (Details D1, Details D2, char sort[], char type[]) {
    int compare;
    if (strcmp(sort, "merk") == 0) {
        if (strcmp(type, "ascending") == 0) {                       // jika sorting berdasarkan merk dan ascending
            compare = strcmp(D1.merk, D2.merk);
        } else {                                                    // jika sorting berdasarkan merk dan descending
            compare = strcmp(D2.merk, D1.merk);
        }
    } else if (strcmp(sort, "sisaHari") == 0) {
        if (strcmp(type, "ascending") == 0) {                       // jika sorting berdasarkan sisa hari dan ascending
            compare = D1.expire - D2.expire;
        } else {                                                    // jika sorting berdasarkan sisa hari dan descending
            compare = D2.expire - D1.expire;
        }
    }

    return compare;
}

// prosedur tambah node baru di awal list
void addF (List *L, Details D) {
    Node *newNode = (Node *) malloc (sizeof (Node));            // alokasi memori node baru
    newNode->detail = D;                                        // isi detail node dengan data input
    if ((*L).first == NULL) {
        newNode->next = NULL;                                       // jika list kosong, next dari node baru adalah NULL
    } else {
        newNode->next = (*L).first;                                 // jika tidak, next dari node baru adalah node pertama
    }
    (*L).first = newNode;                                       // node baru menjadi node pertama
    newNode = NULL;
}

// prosedur tambah node baru setelah node lain pada list
void addA (List *L, Details D, Node *prev) {
    Node *newNode = (Node *) malloc (sizeof (Node));            // alokasi memori node baru
    newNode->detail = D;                                        // isi detail node dengan data input
    if (prev->next == NULL) {
        newNode->next = NULL;                                       // jika node prev adalah node terakhir, next dari node baru adalah NULL
    } else {
        newNode->next = prev->next;                                 // jika tidak, next dari node baru adalah node setelah node prev
    }
    prev->next = newNode;                                       // node baru menjadi node setelah node prev
    newNode = NULL;
}

// prosedur tambah node baru di akhir list
void addL (List *L, Details D) {
    if ((*L).first == NULL) {
        addF (L, D);                                                // jika list kosong, tambah node di awal list
    } else {
        Node *before = (*L).first;                                  // jika tidak, tunjuk node pertama
        while (before->next != NULL) {                              // selama node yang ditunjuk bukan node terakhir
            before = before->next;                                      // tunjuk node selanjutnya
        }
        addA (L, D, before);                                        // tambah node setelah node terakhir
    }
}

// prosedur tukar data antar node
void swap (List *L, Node *N1, Node *N2) {
    if (N1 == (*L).first) {                                         // jika node N1 adalah node yang akan ditukar
        N1->next = N2->next;                                            // next dari node N1 adalah node setelah node N2
        (*L).first = N2;                                                // node N2 menjadi node pertama
        (*L).first->next = N1;                                          // next dari node pertama adalah node N1
    } else {                                                        // jika tidak
        Node *back = (*L).first;                                        // inisialisasi node belakang mulai dari node pertama
        while (back->next != N1) {                                      // selama node belakang bukan node sebelum node N1
            back = back->next;                                              // tunjuk node selanjutnya
        }
        N1->next = N2->next;                                            // next dari node N1 adalah node setelah node N2
        N2->next = N1;                                                  // next dari node N2 adalah node N1
        back->next = N2;                                                // next dari node belakang menunjuk ke node N2
    }
}

// fungsi sorting list
void sortL (List *L, char sort[], char type[]) {
    // bubble sort
    if ((*L).first != NULL) {
        Node *current = (*L).first;                                 // tunjuk node pertama
        Node *front = current->next;                                // tunjuk node selanjutnya
        Node *limit;                                                // inisialisasi batas node yang sudah diurutkan

        while (front != limit) {                                    // selama node di depan bukan batas sorted node
            while (front != NULL) {                                     // selama node di depan bukan NULL

                // cek node untuk sorting
                int compare = checkSort (current->detail, front->detail, sort, type);
                if (compare > 0) {                                          // jika hasil compare lebih dari 0
                    swap (L, current, front);                                   // tukar data antar node
                    front = current->next;                                      // tunjuk node di depan node sekarang
                } else {                                                    // jika tidak
                    current = front;                                            // node sekarang pindah ke node di depan
                    front = front->next;                                        // tunjuk node di depan node sekarang
                }

                // cek batas node
                if (front == limit || front == NULL) {                      // jika pointer sama dengan batas node atau NULL
                    limit = current;                                            // tentukan batas node, keluar dari loop
                    break;
                }
            }
            current = (*L).first;                                       // tunjuk node pertama sebagai node sekarang
            front = current->next;                                      // tunjuk node selanjutnya sebagai node di depan
        }
    }
}

// prosedur penggabungan list
void mergeList (List *L1, List *L2, char sort[], char type[]) {
    if ((*L1).first != NULL && (*L2).first != NULL) {
        Node *pointL = (*L1).first;                                 // tunjuk node pertama list 1
        Node *pointR = (*L2).first;                                 // tunjuk node pertama list 2
        Node *path = NULL;                                          // inisialisasi node path
        (*L2).first = NULL;                                         // kosongkan list 2
        
        // cek dan bandingkan data
        int compare = checkSort (pointL->detail, pointR->detail, sort, type);
        if (compare > 0) {                                          // jika hasil compare lebih dari 0
            path = pointR;                                              // starting node pindah ke node pertama list 2
            pointR = pointR->next;                                      // tunjuk node selanjutnya
        } else {                                                    // jika tidak
            path = pointL;                                              // starting node tetap di node pertama list 1
            pointL = pointL->next;                                      // tunjuk node selanjutnya
        }
        (*L1).first = path;                                         // definisikan node path ke list 1

        while (pointR != NULL || pointL != NULL) {                  // selama penunjuk tidak NULL
            if (pointL != NULL && pointR != NULL) {                     // jika kedua penunjuk tidak NULL, cek compare value
                compare = checkSort (pointL->detail, pointR->detail, sort, type);
            } else if (pointL == NULL) compare = 1;                     // jika penunjuk list 1 NULL, otomatis compare = 1
              else compare = -1;                                        // jika penunjuk list 2 NULL, otomatis compare = -1

            if (compare > 0) {                                          // jika hasil compare lebih dari 0
                path->next = pointR;                                        // path selanjutnya menunjuk ke node list 2
                path = pointR;                                              // path pindah ke node list 2
                pointR = pointR->next;                                      // tunjuk node list 2 selanjutnya
            } else {                                                    // jika tidak
                path->next = pointL;                                        // path selanjutnya menunjuk ke node list 1
                path = pointL;                                              // path pindah ke node list 1
                pointL = pointL->next;                                      // tunjuk node list 1 selanjutnya
            }
        }
    }

    printList (*L1);                                            // print list hasil penggabungan
}

// prosedur print list
void printList (List L) {
    if (L.first != NULL) {
        Node *point = L.first;                                  // tunjuk node pertama
        // print header tabel
        printf("+----------------+-------+-----------+\n");
        printf("| Merk           | Jenis | Sisa Hari |\n");
        printf("+----------------+-------+-----------+\n");

        while (point != NULL) {                                 // selama pointer tidak NULL
            printf("| %s", point->detail.merk);                     // print merk makanan hewan
            for (int i = 0; i < point->detail.merkLen; i++) {
                printf(" ");                                        // print spasi untuk merk
            }
            printf(" | %s   ", point->detail.type);                 // print jenis makanan hewan
            printf("| %d", point->detail.expire);                   // print sisa hari expire makanan hewan
            for (int i = 0; i < point->detail.expireLen; i++) {
                printf(" ");                                        // print spasi untuk sisa hari
            }
            printf(" |\n");                                         // print batas baris tabel
            point = point->next;                                    // tunjuk node selanjutnya
        }
        printf("+----------------+-------+-----------+\n");     // print footer tabel
    }
}