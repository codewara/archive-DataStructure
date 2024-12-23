#include "library.h"

// inisialisasi variabel global
int R = 0, L = 0;

// prosedur untuk membuat pohon
void makeTree(Tree *T, Details D) {
    // alokasi memori untuk node
    Node *root = (Node *) malloc(sizeof(Node));
    root->detail = D; // inisialisasi detail node

    // inisialisasi node
    root->left = NULL;
    root->right = NULL;
    T->root = root;
    root = NULL;
}

// prosedur untuk menambahkan node kiri
void addL (Node *parent, Details D) {
    // jika node kiri kosong
    if (!parent->left) {
        // alokasi memori untuk node
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->detail = D;

        // inisialisasi node
        newNode->left = NULL;
        newNode->right = NULL;
        parent->left = newNode;
    }
}

// prosedur untuk menambahkan node kanan
void addR (Node *parent, Details D) {
    // jika node kanan kosong
    if (!parent->right) {
        // alokasi memori untuk node
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->detail = D;

        // inisialisasi node
        newNode->left = NULL;
        newNode->right = NULL;
        parent->right = newNode;
    }
}

// fungsi untuk mencari node
Node *findNode (Node *root, Details D) {
    // jika node ada
    if (root) {

        // jika node ditemukan, return node
        if (!strcmp (root->detail.name, D.parent)) return root;

        // rekursi ke kiri dan kanan jika node belum ditemukan
        Node *found = findNode (root->left, D);
        if (!found) found = findNode (root->right, D);
        return found; // return node yang ditemukan
    } return NULL; // return NULL jika node tidak ditemukan
}

// prosedur untuk mengecek pohon heap
void checkHeap (Node *root) {
    // jika node ada
    if (root) {
        // jika child node kiri dan kanan ada
        if (root->left && root->right) {
            if (root->right->detail.weight < root->left->detail.weight) L++; // jika kiri lebih besar
            if (root->right->detail.weight > root->left->detail.weight) R++; // jika kanan lebih besar
        } checkHeap (root->left); checkHeap (root->right); // rekursi ke kiri dan kanan
    }
}