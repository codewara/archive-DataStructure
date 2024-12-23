/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
UAS pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Tree T; // inisialisasi pohon

    // input node pohon
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        Details node; char where[16];
        scanf ("%s %s %s %d", node.name, node.parent, where, &node.weight);
        if (!strcmp (where, "akar")) makeTree (&T, node); // jika akar pohon
        else if (!strcmp (where, "kiri")) addL (findNode (T.root, node), node); // jika node kiri
        else if (!strcmp (where, "kanan")) addR (findNode (T.root, node), node); // jika node kanan
    }

    // cek pohon heap
    checkHeap (T.root);

    // output hasil
    printf ("heap kiri: %d\n", L);
    printf ("heap kanan: %d\n", R);
    if (L == R) printf ("pohon heap seimbang\n"); // jika kiri dan kanan sama
    else if (L > R) printf ("pohon heap kiri\n"); // jika kiri lebih besar
    else printf ("pohon heap kanan\n"); // jika kanan lebih besar

    return 0;
}