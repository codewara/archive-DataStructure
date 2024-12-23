// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi data peserta
typedef struct {
    char name[64];
    int wins, losses;
    int len;
} Details;

// struct Node berisi detail node dan pointer next dan prev
typedef struct Node* address;
typedef struct Node {
    Details detail;
    address next;
    address prev;
} Node;

// struct List berisi node head dan tail
typedef struct {
    Node *head;
    Node *tail;
} List;

// FUNCTION AND PROCEDURE DECLARATION
int countDigit (int);
void createList (List*);
void addF (List*, Details);
void addA (List*, Details, Node*);
void addB (List*, Details, Node*);
void addL (List*, Details);
void swap (List*, Node*, Node*);
void separate (List*, List*, char*);
void sortL (List*, char*);
void printList (List, List, List);