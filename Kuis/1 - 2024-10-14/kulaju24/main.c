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
        scanf ("%s %s %s", D[i].code, D[i].pemesan, D[i].expired);
        addL (&L, D[i]);    // masukkan data ke dalam list
    }

    // Ubah urutan list berdasarkan kelayakan
    rearrange (&L);

    // Print list
    printList (L);
    
    return 0;
}