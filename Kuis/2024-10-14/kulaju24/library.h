// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 50

// STRUCTURE DEFINITION
// struct detail untuk menyimpan data pemesanan
typedef struct {
    char code[8];
    char pemesan[32];
    char expired[32];
} Details;

// struct node untuk menyimpan data pemesanan dan pointer
typedef struct {
    Details detail;
    int prev;
    int next;
} Node;

// struct list untuk menyimpan head, tail, dan data node
typedef struct {
    int head;
    int tail;
    Node data[MAX];
} List;

// FUNCTION AND PROCEDURE DECLARATION
void createList (List *L);
int countNode (List L);
int emptyNode (List L);
void addF (List *L, Details D);
void addA (List *L, Details D, int before);
void addL (List *L, Details D);
void moveTop (List *L, int point);
void rearrange (List *L);
void printList (List L);