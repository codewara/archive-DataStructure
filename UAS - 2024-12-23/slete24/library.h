// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

extern int nodepath;

// STRUCTURE DEFINITION
// struct Details berisi detail node
typedef struct {
    char name[4];
    int visited;
} Details;

typedef struct Node *Naddress;
typedef struct Dest *Daddress;

// struct Node berisi detail node dan pointer ke sibling dan child
typedef struct Node {
    Details detail;
    Naddress next;
    Daddress dest;
} Node;

// struct Dest berisi detail edge dan pointer ke next node
typedef struct Dest {
    int weight;
    Daddress next;
    Node *dest;
} Dest;

// struct Graph berisi pointer ke first node
typedef struct {
    Node *first;
} Graph;

// FUNCTION AND PROCEDURE DECLARATION
void createGraph (Graph*);
void addNode (Graph*, Details);
void addDest (Graph*, Node*, Node*, int);
Node *findNode (Graph, Details);
int traverse (Node*, Node*, int, char[][4], int);
