// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi detail file
typedef struct {
    char name[64], parent[64], type;
    int size;
} Details;

// struct Node berisi detail file dan pointer ke sibling dan child
typedef struct Node* Naddress;
typedef struct Node {
    Details detail;
    Naddress sibling;
    Naddress child;
} Node;

// struct Tree berisi pointer ke root
typedef struct {
    Node *root;
} Tree;

// FUNCTION AND PROCEDURE DECLARATION
void createTree (Tree*);
void addChild (Tree*, Node*, Details);
void delRoot (Tree);
void delAll (Node*);
void delChild (Tree*, Node*, Node*);
Node* findNode (Node*, Details, int);
void printTree (Node*, int);
