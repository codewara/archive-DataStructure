/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Kuis 2 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Queue O; createQueue(&O);
    int N; scanf("%d", &N);                     // input jumlah developer
    for (int i = 0; i < N; i++) {               // input setiap data developer
        Details D;
        scanf("%s %d %d %d", D.name, &D.portofolio, &D.skill, &D.priority);
        addprior(&O, D);                            // tambahkan developer ke queue berdasarkan prioritas
    } int passed; scanf("%d", &passed);         // input jumlah developer yang lolos
    
    Queue Q1, Q2;
    createQueue(&Q1); createQueue(&Q2);
    for (int i = 0; i < N; i++, passed--) {     // pindahkan jumlah developer yang lolos
        if (passed > 0) move(&O, &Q1);              // jika masih ada jatah developer yang lolos, pindahkan ke Q1
        else move(&O, &Q2);                         // jika tidak, pindahkan ke Q2
    }

    // print kedua queue
    printQueue(Q1, Q2);

    return 0;
}