#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char name[64];
    int ticket;
} Details;

typedef struct Node *address;
typedef struct Node {
    Details detail;
    address next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

void createQueue (Queue*);
void add (Queue*, Details);
void addprior (Queue*, Details);
void del (Queue*);
void move (Queue*, Queue*);
void printQueue (Queue, Queue);