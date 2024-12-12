/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
UTS pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    
    // inisialisasi list dan variabel
    List L; createList (&L);
    int products, sellers, changes;

    // jenis produk
    scanf ("%d", &products);
    for (int i = 0; i < products; i++) {
        PDetail P;
        
        // input nama dan harga pasar produk
        scanf ("%s %d", P.name, &P.market);

        // tambahkan produk ke list
        addLP (&L, P);
    }

    // penjual produk
    scanf ("%d", &sellers);
    for (int i = 0; i < sellers; i++) {
        SDetail S; char src[64];

        // input nama produk, nama penjual, dan tahun
        scanf ("%s %s %d", src, S.name, &S.year);

        // tambahkan penjual ke sublist produk
        addLS (getP (L, src), S);
    }

    // pemilik yang mengganti produknya
    scanf ("%d", &changes);
    for (int i = 0; i < changes; i++) {
        SDetail S;
        char src[64], dest[64];

        // input nama produk awal, nama produk baru, nama pemilik, dan tahun
        scanf ("%s %s %s %d", src, dest, S.name, &S.year);

        // pindahkan penjual dari produk lama ke produk baru
        move (S, getP (L, src), getP (L, dest));
    }

    // cetak list
    printList (L);
    
    return 0;
}