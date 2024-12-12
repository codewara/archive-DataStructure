/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 2 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L;
    Details D[6];
    createList (&L);

    for (int i = 0; i < 6; i++) {
        scanf ("%s %s %d", D[i].nama, D[i].negara, &D[i].suhu);
    }

    printf ("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    addF (&L, D[0]);
    addF (&L, D[1]);
    addL (&L, D[2]);
    printList (L);

    delL (&L);
    addA (&L, D[3], L.first);
    addA (&L, D[4], L.first->next);
    delF (&L);
    printList (L);

    delA (&L, L.first->next);
    delF (&L);
    delL (&L);
    printList (L);

    addF (&L, D[5]);
    printList (L);

    return 0;
}