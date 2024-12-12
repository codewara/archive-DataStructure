// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct detail untuk menyimpan data penjualan foto
typedef struct {
    char judul[64];
    int tanggal, bulan, tahun;
} Details;

// struct node untuk menyimpan data penjualan foto dan pointer
typedef struct Node* address;
typedef struct Node {
    Details detail;
    address next;
} Node;

// struct list untuk menyimpan pointer ke node pertama
typedef struct {
    Node *first;
} List;

// FUNCTION AND PROCEDURE DECLARATION
void createList (List *L);
int countNode (List L);
void addF (List *L, Details D);
void addA (List *L, Details D, Node *prev);
void addL (List *L, Details D);
void moveTop (List*, Node*);
void rearrange (List*, int, int);
void printList (List L);