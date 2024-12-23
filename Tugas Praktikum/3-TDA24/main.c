/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Praktikum 3 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    // membuat stack utama
    Stack S; createStack (&S);
    int N; scanf ("%d", &N);                        // input jumlah tontonan
    for (int i = 0; i < N; i++) {                   // input detail tontonan
        Details D;
        scanf ("%s %s", D.title, D.type);
        push (&S, D);                                   // push ke stack utama
    }

    // memindahkan stack ke dua stack
    Stack angst, nonangst;
    createStack (&angst); createStack (&nonangst);  // buat stack ANGST dan non ANGST
    for (int i = 0; i < N; i++) {
        if (strcmp (S.top->detail.type, "Sad") == 0) {
            move (&S, &angst);                              // move ke stack ANGST jika sad ending
        } else {
            move (&S, &nonangst);                           // move ke stack non ANGST jika tidak sad ending
        }
    }

    // print kedua stack
    printStack (angst, nonangst);

    return 0;
}