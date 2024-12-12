#include <stdio.h>
#include <malloc.h>

extern int pre;
extern int in;
extern int post;

typedef struct Node *address;
typedef struct Node {
    char name;
    address left;
    address right;
} Node;

typedef struct {
    Node *root;
} Tree;

void makeTree (Tree*, char);
void addL (Node*, char);
void addR (Node*, char);
void delTree (Node*);
void delL (Node*);
void delR (Node*);
void printPre (Node*);
void printIn (Node*);
void printPost (Node*);
