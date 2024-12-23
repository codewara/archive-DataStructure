#include "library.h"

int nodepath = 0;

// prosedur untuk membuat graph
void createGraph (Graph *G) {
    G->first = NULL;
}

// prosedur untuk menambahkan node ke dalam graph
void addNode (Graph *G, Details D) {
    // alokasi memori untuk node baru
    Node *newNode = (Node*) malloc(sizeof(Node));
    // inisialisasi node baru
    newNode->detail = D;
    newNode->detail.visited = 0;
    newNode->next = NULL;
    newNode->dest = NULL;

    // jika graph kosong, tambahkan node di awal (pertama)
    if (!G->first) G->first = newNode;

    // jika graph tidak kosong, tambahkan node di akhir
    else {
        Node *last = G->first;
        while (last->next) last = last->next;
        last->next = newNode;
    }
}

// prosedur untuk menambahkan edge ke dalam graph
void addDest (Graph *G, Node *src, Node *dest, int weight) {
    // alokasi memori untuk edge baru
    Dest *newDest = (Dest*) malloc(sizeof(Dest));
    // inisialisasi edge baru
    newDest->weight = weight;
    newDest->next = NULL;
    newDest->dest = dest;

    // jika node src belum punya edge, tambahkan edge di awal
    if (!src->dest) src->dest = newDest;

    // jika node src sudah punya edge, tambahkan edge di akhir
    else {
        Dest *last = src->dest;
        while (last->next) last = last->next;
        last->next = newDest;
    }
}

// fungsi untuk mencari node berdasarkan detail
Node *findNode (Graph G, Details D) {
    Node *ret = NULL; // inisialisasi node yang ditemukan
    Node *current = G.first; // inisialisasi node yang sedang dicek

    // traverse graph untuk mencari node
    while (current && !ret) {
        if (!strcmp (current->detail.name, D.name)) ret = current; // jika node ditemukan, input node ke ret
        else current = current->next; // jika node belum ditemukan, traverse ke node berikutnya
    } return ret; // return node yang ditemukan
}

// fungsi untuk melakukan traversal dari src ke dest
int traverse (Node *src, Node *dest, int total, char nodes[][4], int idx) {
    int found = 0; // inisialisasi hasil traversal

    // jika node src dan dest valid
    if (src && dest) {
        src->detail.visited = 1; // tandai node src sebagai visited

        // traverse ke semua node dest dari node src
        Dest *current = src->dest;
        while (current ) {
            strcpy (nodes[idx], current->dest->detail.name); // input node ke nodes

            // jika node dest belum pernah dikunjungi
            if (!current->dest->detail.visited) {

                // jika node dest adalah node dest yang dicari
                if (current->dest->detail.name == dest->detail.name) {
                    for (int i = 0; i < idx; i++) printf ("%s ", nodes[i]); // print path traversal
                    found = total + current->weight; // jika total kurang dari limit, input valid ke found
                    nodepath += idx; // increment idx ke nodepath
                
                // jika node dest bukan node dest yang dicari, traverse ke node dest
                } else found += traverse (current->dest, dest, total + current->weight, nodes, idx + 1);
            } current = current->next; // traverse ke edge berikutnya
            nodes[idx][0] = '\0'; // hapus node terakhir dari nodes
        } src->detail.visited = 0; // reset visited node src
    } return found; // return hasil traversal
}
