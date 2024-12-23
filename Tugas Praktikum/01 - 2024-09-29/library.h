// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi data makanan hewan
typedef struct {
    char merk[16];
    char type[4];
    int expire;
    int merkLen;
    int expireLen;
} Details;

// struct Node berisi detail node dan pointer next
typedef struct Node* address;
typedef struct Node {
    Details detail;
    address next;
} Node;

// struct List berisi node
typedef struct {
    Node *first;
} List;

// FUNCTION AND PROCEDURE DECLARATION
int countDigit (int);
int checkSort (Details, Details, char*, char*);
void addF (List*, Details);
void addA (List*, Details, Node*);
void addL (List*, Details);
void sortL (List*, char*, char*);
void mergeList (List*, List*, char*, char*);
void printList (List);