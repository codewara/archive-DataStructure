#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[64];
    char negara[64];
    int suhu;
} Details;

typedef struct Node* address;
typedef struct Node {
    Details detail;
    address next;
} Node;

typedef struct {
    Node *first;
} List;

void createList (List *L);
int countNode (List L);
void addF (List *L, Details D);
void addA (List *L, Details D, Node *prev);
void addL (List *L, Details D);
void delF (List *L);
void delA (List *L, Node *before);
void delL (List *L);
void printList (List L);