// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// GLOBAL VARIABLES
extern int R;   // jumlah heap kanan
extern int L;   // jumlah heap kiri

// STRUCTURE DEFINITION
// struct Details berisi detail node
typedef struct{
    char name[64];
    char parent[64];
    int weight;
} Details;

// struct Node berisi detail node dan pointer left-right
typedef struct Node *address;
typedef struct Node {
    Details detail;
    address left;
    address right;
} Node;

// struct Tree berisi pointer root
typedef struct {
    Node *root;
} Tree;

// FUNCTION AND PROCEDURE DECLARATION
void makeTree (Tree*, Details);
void addL (Node*, Details);
void addR (Node*, Details);
Node *findNode (Node*, Details);
void checkHeap (Node*);
