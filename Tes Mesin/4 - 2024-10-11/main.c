/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 4 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L;
    Details D[9];
    createList (&L);

    for (int i = 0; i < 9; i++) {
        scanf ("%s %d %s", D[i].title, &D[i].year, D[i].singer);
    }

    addL (&L, D[0]);
    addF (&L, D[1]);
    addB (&L, D[2], L.head->next);
    printList (L);

    addA (&L, D[3], L.head->next);
    delA (&L, L.head);
    addA (&L, D[4], L.head);
    addB (&L, D[5], L.tail);
    delF (&L);
    addA (&L, D[6], L.tail);
    printList (L);

    delL (&L);
    addB (&L, D[7], L.head);
    delA (&L, L.head);
    addL (&L, D[8]);
    printListR (L);

    delAll (&L);
    printList (L);

    return 0;
}