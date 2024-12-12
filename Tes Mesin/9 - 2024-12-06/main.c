/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tes Mesin 9 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main() {
    Details D[8];
    for (int i = 0; i < 8; i++) {
        scanf (" %c", &D[i].name);
    }

    Tree T;
    createTree (&T, D[0]);
    addChild (T.root, D[1]);
    addChild (T.root->child, D[2]);
    addChild (T.root->child, D[3]);
    addChild (T.root->child->child->sibling, D[4]);
    printf ("--- Add 5 ---\nPre :");
    printPre (T.root);
    printf ("\nPost :");
    printPost (T.root);
    printf ("\n");
    
    delChild (findNode (T.root, D[4]), findNode (T.root, D[3]));
    printf ("--- Find and del  ---\nPre :");
    printPre (T.root);
    printf ("\nPost :");
    printPost (T.root);
    printf ("\n");

    addChild (findNode (T.root, D[3]), D[5]);
    addChild (findNode (T.root, D[5]), D[6]);
    addChild (findNode (T.root, D[3]), D[7]);
    printf ("--- Find and add ---\nPre :");
    printPre (T.root);
    printf ("\nPost :");
    printPost (T.root);
    printf ("\n");

    delAll(T.root);
    createTree(&T, D[4]);
    printf ("--- Reset ---\nPre :");
    printPre (T.root);
    printf ("\nPost :");
    printPost (T.root);

    return 0;
}
