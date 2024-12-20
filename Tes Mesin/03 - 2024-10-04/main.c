/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 3 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L;
    Details D[7];
    createList (&L);

    for (int i = 0; i < 7; i++) {
        scanf ("%s %d %s", D[i].menu, &D[i].harga, D[i].pemesan);
    }

    addF (&L, D[0]);
    addL (&L, D[1]);
    addA (&L, D[2], L.head);
    printList (L);

    delA (&L, L.data[L.head].next);
    addA (&L, D[3], L.head);
    addA (&L, D[4], L.data[L.tail].prev);
    delF (&L);
    printList (L);

    addF (&L, D[5]);
    addA (&L, D[6], L.data[L.head].next);
    delL (&L);
    printReverse (L);

    delAll (&L);
    printList (L);

    return 0;
}