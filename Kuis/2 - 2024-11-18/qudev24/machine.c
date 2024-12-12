#include "library.h"

// prosedur untuk membuat queue
void createQueue (Queue *Q) {
    (*Q).head = -1;
    (*Q).tail = -1;
}

// prosedur untuk menambahkan elemen ke dalam queue berdasarkan prioritas
void addprior (Queue *Q, Details D) {
    if ((*Q).head == -1) {                      // jika queue kosong
        (*Q).head = 0;
        (*Q).tail = 0;
        (*Q).data[0] = D;
    } else {                                    // jika queue tidak kosong
        if ((*Q).tail + 1 < D.priority) {           // jika jumlah elemen dalam queue kurang dari angka prioritas D
            (*Q).tail++;                                // add elemen ke tail
            (*Q).data[(*Q).tail] = D;
        } else {                                    // jika jumlah elemen dalam queue lebih dari atau sama dengan angka prioritas D
            
            // geser elemen-elemen dalam queue
            for (int i = (*Q).tail; i >= D.priority - 1; i--) {
                (*Q).data[i + 1] = (*Q).data[i];
            }
            (*Q).data[D.priority - 1] = D;              // add elemen ke posisi prioritas D
            (*Q).tail++;
        }
    }
}

// prosedur untuk memindahkan elemen dari queue Q1 ke queue Q2
void move (Queue *Q1, Queue *Q2) {
    if ((*Q1).head != -1) {                     // jika Q1 tidak kosong
        if ((*Q2).head == -1) {                     // jika Q2 kosong
            (*Q2).head = 0;
            (*Q2).tail = 0;
            (*Q2).data[0] = (*Q1).data[(*Q1).head];
        } else {                                    // jika Q2 tidak kosong
            (*Q2).tail++;
            (*Q2).data[(*Q2).tail] = (*Q1).data[(*Q1).head];
        }
        if ((*Q1).head == (*Q1).tail) {         // jika head dan tail Q1 sama
            (*Q1).head = -1;
            (*Q1).tail = -1;
        } else {                                // jika head dan tail Q1 tidak sama
            (*Q1).head++;
        }
    }
}

// prosedur untuk mencetak queue Q1 dan Q2
void printQueue (Queue Q1, Queue Q2) {

    // Developer yang Diterima
    printf ("Developer yang Diterima:\n");
    if (Q1.head != -1) {                        // jika Q1 tidak kosong
        int point = Q1.head;
        while (point <= Q1.tail) {                  // selama point masih dalam batas tail, print data
            printf("%s %d %d\n", Q1.data[point].name, Q1.data[point].portofolio, Q1.data[point].skill);
            point++;
        }
    } else printf ("kosong\n");                 // jika Q1 kosong, print "kosong"

    // Calon Developer (belum diterima)
    printf ("\nCalon Developer:\n");
    if (Q2.head != -1) {                        // jika Q2 tidak kosong
        int point = Q2.head;
        while (point <= Q2.tail) {                  // selama point masih dalam batas tail, print data
            printf("%s %d %d\n", Q2.data[point].name, Q2.data[point].portofolio, Q2.data[point].skill);
            point++;
        }
    } else printf ("kosong\n");                 // jika Q2 kosong, print "kosong"
}