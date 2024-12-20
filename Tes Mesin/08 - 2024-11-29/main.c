/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 8 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    char nodes[8];
    for (int i = 0; i < 8; i++) {
        scanf(" %c", &nodes[i]);
    }

    Tree T;
    makeTree (&T, nodes[0]);
    addL (T.root, nodes[1]);
    addR (T.root, nodes[2]);
    addL (T.root->left, nodes[3]);
    addR (T.root->left, nodes[4]);

    addL (T.root->right, nodes[5]);
    addR (T.root->right, nodes[6]);
    addL (T.root->right->right, nodes[7]);

    printf ("Pre Order\n => ");
    printPre (T.root);
    delL (T.root->right->right);
    printf ("\nIn Order\n => ");
    printIn (T.root);
    delR (T.root->right);
    printf ("\nPost Order\n => ");
    printPost (T.root);
    printf ("\n");
}