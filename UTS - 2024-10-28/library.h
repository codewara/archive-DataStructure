// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct SDetail berisi data penjual
typedef struct {
    char name[64];
    int year;
} SDetail;

// struct PDetail berisi data produk
typedef struct {
    char name[64];
    int market;
} PDetail;

// struct SNode berisi detail node dan pointer next-prev
typedef struct SNode* SAddress;
typedef struct SNode {
    SDetail detail;
    SAddress next;
    SAddress prev;
} SNode;

// struct PNode berisi subnode head dan tail, detail node, dan pointer next-prev
typedef struct PNode* PAddress;
typedef struct PNode {
    PDetail detail;
    SNode *head;
    SNode *tail;
    PAddress next;
    PAddress prev;
} PNode;

// struct List berisi node head dan tail
typedef struct {
    PNode *head;
    PNode *tail;
} List;

// FUNCTION AND PROCEDURE DECLARATION
void createList (List*);
void createSList (PNode*);
void addFP (List*, PDetail);
void addFS (PNode*, SDetail);
void addAP (List*, PDetail, PNode*);
void addAS (PNode*, SDetail, SNode*);
void addLP (List*, PDetail);
void addLS (PNode*, SDetail);
void delFS (PNode*);
void delAS (PNode*, SNode*);
void delLS (PNode*);
void delAllS (PNode*);
void delFP (List*);
void delAP (List*, PNode*);
void delLP (List*);
void delAllP (List*);
void printList (List);
PNode* getP (List, char[]);
void move (SDetail, PNode*, PNode*);