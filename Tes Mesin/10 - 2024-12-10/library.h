#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char name;
} Details;

typedef struct Node *Naddress;
typedef struct Dest *Daddress;

typedef struct Node {
    Details detail;
    Naddress next;
    Daddress dest;
} Node;

typedef struct Dest {
    int weight;
    Daddress next;
    Node *dest;
} Dest;

typedef struct {
    Node *first;
} Graph;

void createGraph (Graph*);
void addNode (Graph*, Details);
void addDest (Graph*, Node*, Node*, int);
void delNode (Graph*, Details);
void delDest (Node*, Details);
void delAll (Node*);
Node *findNode (Graph, Details);
void printGraph (Graph);
