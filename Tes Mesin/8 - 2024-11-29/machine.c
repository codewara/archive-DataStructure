#include "library.h"

int pre = 1, in = 1, post = 1;

void makeTree(Tree *T, char name) {
    Node *root = (Node *) malloc(sizeof(Node));
    root->name = name;
    root->left = NULL;
    root->right = NULL;
    T->root = root;
    root = NULL;
}

void addL (Node *parent, char name) {
    if (!parent->left) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->name = name;
        newNode->left = NULL;
        newNode->right = NULL;
        parent->left = newNode;
    }
}

void addR (Node *parent, char name) {
    if (!parent->right) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->name = name;
        newNode->left = NULL;
        newNode->right = NULL;
        parent->right = newNode;
    }
}

void delTree (Node *parent) {
    if (parent) {
        delTree (parent->left);
        delTree (parent->right);
        free (parent);
    }
}

void delL (Node *parent) {
    Node *temp = parent->left;
    parent->left = NULL;
    delTree (temp);
}

void delR (Node *parent) {
    Node *temp = parent->right;
    parent->right = NULL;
    delTree (temp);
}

void printPre (Node *root) {
    if (root) {
        if (pre) {
            printf ("%c", root->name);
            pre = 0;
        } else printf("-%c", root->name);
        printPre (root->left);
        printPre (root->right);
    }
}

void printIn (Node *root) {
    if (root) {
        printIn (root->left);
        if (in) {
            printf ("%c", root->name);
            in = 0;
        } else printf("-%c", root->name);
        printIn (root->right);
    }
}

void printPost (Node *root) {
    if (root) {
        printPost (root->left);
        printPost (root->right);
        if (post) {
            printf ("%c", root->name);
            post = 0;
        } else printf("-%c", root->name);
    }
}