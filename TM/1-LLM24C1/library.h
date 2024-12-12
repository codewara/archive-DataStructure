#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 10

typedef struct {
    char nama[64];
    char nim[16];
    int duration;
} Details;

typedef struct {
    Details detail;
    int next;
} Node;

typedef struct {
    int first;
    Node data[MAX];
} List;

void createList (List *L);
int countNode (List L);
int emptyNode (List L);
void addF (List *L, Details D);
void addA (List *L, Details D, int before);
void addL (List *L, Details D);
void delF (List *L);
void delA (List *L, int before);
void delL (List *L);
void printList (List L);