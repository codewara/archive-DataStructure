/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Kuis 1 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L;
    createList (&L);

    // Input
    int n; scanf ("%d", &n);
    Details D[n];
    for (int i = 0; i < n; i++) {
        scanf ("%s %d %d %d", D[i].judul, &D[i].tanggal, &D[i].bulan, &D[i].tahun);
        addL (&L, D[i]);    // masukkan data ke dalam list
    }

    // Input batas tanggal dan bulan
    int Blimit, Ylimit;
    scanf ("%d %d", &Blimit, &Ylimit);

    // Ubah urutan list berdasarkan batas tanggal dan bulan
    rearrange (&L, Blimit, Ylimit);

    // Print list
    printList (L);
    
    return 0;
}