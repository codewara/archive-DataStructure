/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 6 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Stack S1, S2;
    createStack(&S1);
    createStack(&S2);

    Details D[6];
    for (int i = 0; i < 6; i++) {
        scanf("%s %s %d", D[i].title, D[i].category, &D[i].price);
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printStack(S1, S2);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    push(&S1, D[0]);
    push(&S2, D[1]);
    push(&S2, D[2]);

    printStack(S1, S2);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    pop(&S1);
    move(&S2, &S1);
    push(&S1, D[3]);
    push(&S2, D[4]);
    push(&S1, D[5]);
    pop(&S2);
    move(&S1, &S2);

    printStack(S1, S2);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}