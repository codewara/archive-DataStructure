/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 5 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List L;
    createList(&L);

    int N; scanf("%d", &N);

    PDetail P[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", P[i].name);
        addLP(&L, P[i]);
        SDetail S[4];
        scanf("%s %d", S[0].name, &S[0].percentage);
        addFS (L.tail, S[0]);
        scanf("%s %d", S[1].name, &S[1].percentage);
        addLS (L.tail, S[1]);
        scanf("%s %d", S[2].name, &S[2].percentage);
        addAS (L.tail, S[2], L.tail->head->next);
        scanf("%s %d", S[3].name, &S[3].percentage);
        addFS (L.tail, S[3]);
    }

    printf ("==============================\n");
    
    printList(L);

    printf ("==============================\n");

    delAS(L.head->next, L.head->next->head->next);
    delFP(&L);
    printList(L);

    printf ("==============================\n");

    delFS(L.head);
    delLS(L.head->next);
    printList(L);

    printf ("==============================\n");

    delLP(&L);
    printList(L);

    printf ("==============================\n");

    delAllP(&L);
    printList(L);

    printf ("==============================\n");
}