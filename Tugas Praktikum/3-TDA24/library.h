// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi data tontonan
typedef struct {
    char title[64];
    char type[64];
} Details;

// struct Node berisi detail node dan pointer next
typedef struct Node *address;
typedef struct Node {
    Details detail;
    address next;
} Node;

// struct Stack berisi pointer top
typedef struct {
    Node *top;
} Stack;

// FUNCTION AND PROCEDURE DECLARATION
void createStack (Stack*);
void push (Stack*, Details);
void move (Stack*, Stack*);
void printStack (Stack, Stack);