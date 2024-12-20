#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char name[64];
    int percentage;
} SDetail;

typedef struct {
    char name[64];
} PDetail;

typedef struct SNode* SAddress;
typedef struct SNode {
    SDetail detail;
    SAddress next;
    SAddress prev;
} SNode;

typedef struct PNode* PAddress;
typedef struct PNode {
    PDetail detail;
    SNode *head;
    SNode *tail;
    PAddress next;
    PAddress prev;
} PNode;

typedef struct {
    PNode *head;
    PNode *tail;
} List;

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