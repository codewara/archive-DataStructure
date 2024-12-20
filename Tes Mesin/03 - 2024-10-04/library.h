#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char menu[64];
    char pemesan[64];
    int harga;
} Details;

typedef struct {
    Details detail;
    int prev;
    int next;
} Node;

typedef struct {
    int head;
    int tail;
    Node data[7];
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
void delAll (List *L);
void printList (List L);
void printReverse (List L);