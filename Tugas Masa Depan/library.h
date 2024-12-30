// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// GLOBAL VARIABLE
extern int levSpace[64];

// STRUCTURE DEFINITION
// struct Details untuk menyimpan detail dari node
typedef struct {
    char name[64], parent[64];
    int duration, qty, length, matched, level;
} Details;

// struct Courses untuk menyimpan detail dari course
typedef struct {
    char name[64];
    int length;
} Courses;

// struct List untuk menyimpan list course
typedef struct List* Laddress;
typedef struct List {
    Courses course;
    Laddress next;
} List;

// struct Node untuk menyimpan node dari tree
typedef struct Node* Naddress;
typedef struct Node {
    Details detail;
    List *head;
    Naddress sibling;
    Naddress child;
} Node;

// struct Tree untuk menyimpan root dari tree
typedef struct {
    Node *root;
} Tree;

// FUNCTION AND PROCEDURE DECLARATION
void createTree (Tree*, Details);
Node* addChild (Node*, Details);
void addList (Node*, char*);
void delnot (Node*);
void delAll (Node*);
void delChild (Node*, Node*);
Node* findNode (Node*, Details);
void matchIndent (Node*);
void printIndent (int, int);
void printMark (Node*, int, char*);
int printTree (Node*, int);
int digint (int);
