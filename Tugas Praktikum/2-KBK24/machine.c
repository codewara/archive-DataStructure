#include "library.h"

// fungsi menghitung jumlah digit angka
int countDigit (int n) {
    int res = 0;
    if (!n) return 1;
    else {
        while (n > 0) {
            n /= 10;
            res++;
        } return res;
    }
}

// prosedur membuat list baru
void createList (List *L) {
    (*L).head = NULL;
    (*L).tail = NULL;
}

// prosedur menambahkan node di awal list
void addF (List *L, Details D) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (!(*L).head) {                                   // jika list kosong, tambahkan di awal
        newNode->next = NULL;
        (*L).tail = newNode;
    } else {                                            // jika list tidak kosong, tambahkan di awal
        newNode->next = (*L).head;
        (*L).head->prev = newNode;
    }
    newNode->prev = NULL;
    (*L).head = newNode;
    newNode = NULL;
}

// prosedur menambahkan node setelah node tertentu
void addA (List *L, Details D, Node *before) {
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->detail = D;
    if (!before->next) {                                // jika node sebelum adalah node terakhir
        newNode->next = NULL;
        (*L).tail = newNode;
    } else {                                            // jika node sebelum bukan node terakhir
        newNode->next = before->next;
        newNode->next->prev = newNode;
    }
    newNode->prev = before;
    before->next = newNode;
    newNode = NULL;
}

// prosedur menambahkan node di akhir list
void addL (List *L, Details D) {
    if (!(*L).head) {
        addF (L, D);                                        // jika list kosong, tambahkan di awal
    } else {
        addA (L, D, (*L).tail);                             // jika list tidak kosong, tambahkan di akhir
    }
}

// prosedur menukar posisi dua node
void swap (List *L, Node *N1, Node *N2) {
    if (N1 == (*L).head) {                              // jika node pertama berada di awal list
        (*L).head = N2;
        N2->prev = NULL;
    } else {                                            // jika node pertama tidak berada di awal list
        N1->prev->next = N2;
        N2->prev = N1->prev;
    }

    if (N2 == (*L).tail) {                              // jika node kedua berada di akhir list
        (*L).tail = N1;
        N1->next = NULL;
    } else {                                            // jika node kedua tidak berada di akhir list
        N2->next->prev = N1;
        N1->next = N2->next;
    }
    N2->next = N1;                                      // tukar posisi node
    N1->prev = N2;
}

// fungsi mencari node sebelum node tertentu
Node *findPrev (List *L, Node *N, char sort[]) {
    Node *point = (*L).head;

    // loop selama node masih ada
    while (point) {
        if ((strcmp(sort, "ascending") == 0 &&              // jika sort ascending dan nama point lebih besar dari nama N
             strcmp(point->detail.name, N->detail.name) > 0) ||
            (strcmp(sort, "descending") == 0 &&             // jika sort descending dan nama point lebih kecil dari nama N
             strcmp(point->detail.name, N->detail.name) < 0)) {
            return point->prev;                                 // kembalikan node sebelum point
        } point = point->next;                              // lanjut ke node selanjutnya
    } return (*L).tail;                                 // jika tidak ditemukan, kembalikan node terakhir
}

// prosedur memisahkan node peserta profesional dari list batch
void separate (List *P, List *B, char sort[]) {

    // jika list batch tidak kosong
    if ((*B).head) {
        Node *point = (*B).head;                            // pointer ke node pertama list batch

        // loop selama node masih ada
        while (point) {
            Node *nextPoint = point->next;                      // simpan node selanjutnya

            // jika peserta profesional, maka pindahkan ke list peserta profesional
            if (point->detail.wins >= 2 * point->detail.losses) {

                // lepaskan node dari list batch
                if (point == (*B).head) {                           // jika node berada di awal list
                    (*B).head = point->next;
                    if (point->next) point->next->prev = NULL;
                } else if (point == (*B).tail) {                    // jika node berada di akhir list
                    (*B).tail = point->prev;
                    if (point->prev) point->prev->next = NULL;
                } else {                                            // jika node berada di tengah list
                    point->prev->next = point->next;
                    point->next->prev = point->prev;
                }
                point->next = NULL;
                point->prev = NULL;

                // tambahkan node ke list peserta profesional
                if (!(*P).head) {                                   // jika list peserta profesional kosong
                    (*P).head = point;
                    (*P).tail = point;
                } else {                                            // jika list peserta profesional tidak kosong
                    
                    // cari prev node dari node yang akan ditambahkan
                    Node *before = findPrev (P, point, sort);
                    if (!before) {                                      // jika node yang akan ditambahkan berada di awal list
                        point->next = (*P).head;
                        (*P).head->prev = point;
                        (*P).head = point;
                    } else {                                            // jika node yang akan ditambahkan berada di tengah/akhir list
                        point->next = before->next;
                        before->next = point;
                        point->prev = before;
                        if (point->next) point->next->prev = point;         // jika node yang akan ditambahkan berada di tengah list
                        else (*P).tail = point;                             // jika node yang akan ditambahkan berada di akhir list
                    }
                }
            } point = nextPoint;                                // lanjut ke node selanjutnya
        }
    }
}

void sortL (List *L, char sort[]) {

    // jika list tidak kosong
    if ((*L).head) {
        Node *current = (*L).head;
        Node *front = current->next;
        Node *limit;

        // bubble sort
        while (front != limit) {                            // loop selama front belum mencapai limit
            while (front) {                                     // loop selama front masih ada
                if ((strcmp (sort, "ascending") == 0 &&             // jika current dan front harus ditukar posisi
                     strcmp (current->detail.name, front->detail.name) > 0) ||
                    (strcmp (sort, "descending") == 0 &&
                     strcmp (current->detail.name, front->detail.name) < 0)) {
                    swap (L, current, front);                           // tukar posisi current dan front
                    front = current->next;                              // lanjut ke front selanjutnya
                } else {                                            // jika current dan front tidak perlu ditukar posisi
                    current = front;                                    // lanjut ke current selanjutnya
                    front = front->next;                                // lanjut ke front selanjutnya
                }

                // cek posisi front
                if (front == limit || !front) {
                    limit = current;                                    // jika front mencapai limit, set limit ke current
                    break;                                              // hentikan loop
                }
            }
            current = (*L).head;                                // kembalikan current ke awal list
            front = current->next;                              // kembalikan front ke current selanjutnya
        }
    }
}

// prosedur mencetak list
void printList (List L1 , List L2, List L3) {

    // cetak list peserta batch 1
    printf ("+-------------------------------------+\n");
    printf ("|          Peserta Batch - 1          |\n");
    printf ("+-------------------------------------+\n");
    if (L1.head) {                                      // jika list batch 1 tidak kosong
        Node *point = L1.head;
        int num = 1;

        // loop setiap node, print nama peserta, jumlah kemenangan, dan jumlah kekalahan
        while (point) {
            printf ("| %d. %s - %d:%d", num, point->detail.name,
                    point->detail.wins, point->detail.losses);
            for (int i = 0; i < point->detail.len; i++) {       // cetak spasi sesuai panjang tabel
                printf (" ");
            } printf (" |\n");
            point = point->next;                                // lanjut ke node selanjutnya
            num++;                                              // increment nomor peserta
        }
    } printf ("+-------------------------------------+\n\n");

    // cetak list peserta batch 2
    printf ("+-------------------------------------+\n");
    printf ("|          Peserta Batch - 2          |\n");
    printf ("+-------------------------------------+\n");
    if (L2.head) {                                      // jika list batch 2 tidak kosong
        Node *point = L2.head;
        int num = 1;
        
        // loop setiap node, print nama peserta, jumlah kemenangan, dan jumlah kekalahan
        while (point) {
            printf ("| %d. %s - %d:%d", num, point->detail.name,
                    point->detail.wins, point->detail.losses);
            for (int i = 0; i < point->detail.len; i++) {       // cetak spasi sesuai panjang tabel
                printf (" ");
            } printf (" |\n");
            point = point->next;                                // lanjut ke node selanjutnya
            num++;                                              // increment nomor peserta
        }
    } printf ("+-------------------------------------+\n\n");

    // cetak list peserta profesional
    printf ("+-------------------------------------+\n");
    printf ("|        Peserta Professional         |\n");
    printf ("+-------------------------------------+\n");
    if (L3.head) {                                          // jika list peserta profesional tidak kosong
        Node *point = L3.head;
        int num = 1;

        // loop setiap node, print nama peserta, jumlah kemenangan, dan jumlah kekalahan
        while (point) {
            printf ("| %d. %s - %d:%d", num, point->detail.name,
                    point->detail.wins, point->detail.losses);
            for (int i = 0; i < point->detail.len; i++) {       // cetak spasi sesuai panjang tabel
                printf (" ");
            } printf (" |\n");
            point = point->next;                                // lanjut ke node selanjutnya
            num++;                                              // increment nomor peserta
        }
    } printf ("+-------------------------------------+\n");
}