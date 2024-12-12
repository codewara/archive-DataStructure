/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 7 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Queue Q1, Q2;
    createQueue(&Q1);
    createQueue(&Q2);

    int N, done;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        Details D;
        scanf("%s %d", D.name, &D.ticket);
        addprior(&Q1, D);
    } scanf("%d", &done);

    for (int i = 0; i < done; i++) {
        move(&Q1, &Q2);
    }

    printQueue(Q1, Q2);

    return 0;
}