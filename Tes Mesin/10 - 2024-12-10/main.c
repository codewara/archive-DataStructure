/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 10 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main() {
    Graph G;
    createGraph(&G);

    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Details D1, D2; int weight;
        scanf(" %c %c %d", &D1.name, &D2.name, &weight);
        if (!findNode(G, D1)) addNode(&G, D1);
        if (!findNode(G, D2)) addNode(&G, D2);
        addDest(&G, findNode(G, D1), findNode(G, D2), weight);
    } Details del; scanf (" %c", &del.name);
    printGraph(G);
    printf ("==============\n");
    delNode(&G, del);
    printGraph(G);

    return 0;
}