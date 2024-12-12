#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char title[64];
    char category[64];
    int price;
} Details;

typedef struct Node *address;
typedef struct Node {
    Details detail;
    address next;
} Node;

typedef struct {
    Node *top;
} Stack;

void createStack (Stack*);
void push (Stack*, Details);
void pop (Stack*);
void move (Stack*, Stack*);
void printStack (Stack, Stack);