/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
UAS pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    Graph G; createGraph (&G); // inisialisasi graph

    // input jumlah node dan edge
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Details D1, D2; int weight;
        scanf("%s %s %d", D1.name, D2.name, &weight); // input detail node, edge, dan weight
        if (!findNode(G, D1)) addNode(&G, D1); // tambahkan node jika belum ada (1)
        if (!findNode(G, D2)) addNode(&G, D2); // tambahkan node jika belum ada (2)
        addDest(&G, findNode(G, D1), findNode(G, D2), weight); // tambahkan edge
    }
    
    // input node awal, node tujuan, dan node tengah
    Details src, dest, mid; char nodes[100][4]; int idx = 1;
    scanf ("%s %s %s", src.name, dest.name, mid.name);

    // traverse dari node awal ke node tengah
    strcpy (nodes[0], src.name);
    int total = traverse (findNode(G, src), findNode(G, mid), 0, nodes, idx);

    // traverse dari node tengah ke node tujuan
    strcpy (nodes[0], mid.name);
    total += traverse (findNode(G, mid), findNode(G, dest), 0, nodes, idx);

    // print hasil
    printf ("%s\n%d simpul\n%d\n", dest.name, nodepath + 1, total);

    return 0;
}