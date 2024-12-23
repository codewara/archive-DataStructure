/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Praktikum 5 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Graph G; createGraph (&G); // inisialisasi graph

    // input jumlah node dan edge
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Details D1, D2; int weight;
        scanf(" %c %c %d", &D1.name, &D2.name, &weight); // input detail node, edge, dan weight
        if (!findNode(G, D1)) addNode(&G, D1); // tambahkan node jika belum ada (1)
        if (!findNode(G, D2)) addNode(&G, D2); // tambahkan node jika belum ada (2)
        addDest(&G, findNode(G, D1), findNode(G, D2), weight); // tambahkan edge
    }
    
    // input node awal, node tujuan, dan limit weight
    Details src, dest; int limit; char nodes[64] = "x";
    scanf (" %c %c %d", &src.name, &dest.name, &limit); nodes[0] = src.name;
    if (traverse (findNode(G, src), findNode(G, dest), 0, nodes, limit)) { // traverse + print dari node awal ke node tujuan
        printf ("Jalan rahasia ditemukan!\n"); // jika jalan rahasia ditemukan
    } else printf ("Tidak ditemukan jalan rahasia!\n"); // jika jalan rahasia tidak ditemukan

    return 0;
}