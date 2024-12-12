// LIBRARY HEADER FILE
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// STRUCTURE DEFINITION
// struct Details berisi data developer
typedef struct {
    char name[64];
    int portofolio;
    int skill;
    int priority;
} Details;

// struct Queue berisi head, tail, dan data developer
typedef struct {
    int head;
    int tail;
    Details data[100];
} Queue;

// FUNCTION AND PROCEDURE DECLARATION
void createQueue (Queue*);
void add (Queue*, Details);
void addprior (Queue*, Details);
void del (Queue*);
void move (Queue*, Queue*);
void printQueue (Queue, Queue);