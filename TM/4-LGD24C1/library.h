#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char title[64];
    int year;
    char singer[64];
} Details;

typedef struct Node* address;
typedef struct Node {
    Details detail;
    address next;
    address prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void createList (List *L);
int countNode (List L);
void addF (List *L, Details D);
void addA (List *L, Details D, Node *before);
void addB (List *L, Details D, Node *after);
void addL (List *L, Details D);
void delF (List *L);
void delA (List *L, Node *before);
void delL (List *L);
void delAll (List *L);
void printList (List L);
void printListR (List L);