/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Kuis 2 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Stack O; createStack(&O);
    int N; scanf("%d", &N);                         // input jumlah warna
    for (int i = 0; i < N; i++) {                   // input setiap warna dan tingkat kecerahannya
        Details D;
        scanf("%s %d", D.color, &D.level);
        push(&O, D);                                    // push ke stack utama
    }

    Stack B, D;
    createStack(&B); createStack(&D);
    for (int i = 0; i < N; i++) {                   // pindahkan warna ke stack B dan D
        if (!B.top) {
            move(&O, &B);                                   // jika stack B kosong, pindahkan warna ke stack B
        } else {                                        // jika tidak
            if (O.top->detail.level > B.top->detail.level) {
                move(&O, &B);                                   // jika warna di top stack utama lebih terang dari warna di stack warna terang, pindahkan warna ke stack warna terang
            } else {                                        // jika tidak, pindahkan warna top stack terang ke stack gelap, lalu pindahkan warna di stack utama ke stack terang
                move(&B, &D);
                move(&O, &B);
            }
        }
    }

    // print stack gelap dan stack terang
    printStack(D, B);

    return 0;
}