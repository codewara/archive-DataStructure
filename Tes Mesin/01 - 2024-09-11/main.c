/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 1 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L; createList(&L);
    Details D[6];
    for (int i = 0; i < 6; i++) {
        scanf("%s %s %d", D[i].nama, D[i].nim, &D[i].duration);
    }
    
    addF (&L, D[0]);
    addF (&L, D[1]);
    addL (&L, D[2]);
    addF (&L, D[3]);
    addA (&L, D[4], L.data[L.first].next);
    printList (L);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    delA (&L, L.first);
    addA (&L, D[5], L.first);
    delL (&L);
    printList (L);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    delF (&L);
    delA (&L, L.data[L.first].next);
    delF (&L);
    printList (L);
    printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    delL (&L);
    printList (L);
    
    return 0;
}