#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Details {
    char name;
} Details;

typedef struct Node* address;
typedef struct Node {
    Details detail;
    address sibling;
    address child;
} Node;

typedef struct{
    Node *root;
} Tree;

void createTree (Tree*, Details);
void addChild (Node*, Details);
void delAll (Node*);
void delChild (Node*, Node*);
Node* findNode (Node*, Details);
void printPre (Node*);
void printPost (Node*);
void copyTree (Node*, Node**);
int treecmp (Node*, Node*);
