// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi color dan level dari node
typedef struct {
    char color[64];
    int level;
} Details;

// struct Node berisi detail dan pointer next
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
void pop (Stack*);
void move (Stack*, Stack*);
void printStack (Stack, Stack);