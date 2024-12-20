#include "library.h"

void createGraph (Graph *G) {
    G->first = NULL;
}

void addNode (Graph *G, Details D) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->detail = D;
    newNode->next = NULL;
    newNode->dest = NULL;

    if (!G->first) G->first = newNode;
    else {
        Node *last = G->first;
        while (last->next) last = last->next;
        last->next = newNode;
    }
}

void addDest (Graph *G, Node *src, Node *dest, int weight) {
    Dest *newDest = (Dest*) malloc(sizeof(Dest));
    newDest->weight = weight;
    newDest->next = NULL;
    newDest->dest = dest;

    if (!src->dest) src->dest = newDest;
    else {
        Dest *last = src->dest;
        while (last->next) last = last->next;
        last->next = newDest;
    }
}

void delNode (Graph *G, Details D) {
    Node *del = G->first;

    if (del) {
        Node *prev = NULL; int found = 0;
        while (del && !found) {
            if (del->detail.name == D.name) found = 1;
            else {
                prev = del;
                del = del->next;
            }
        }

        if (found) {
            Node *current = G->first;
            while (current) {
                if (current != del) {
                    delDest(current, del->detail);
                } current = current->next;
            } delAll (del);

            if (!prev) {
                G->first = del->next;
                del->next = NULL;
            } else {
                if (!del->next) prev->next = NULL;
                else {
                    prev->next = del->next;
                    del->next = NULL;
                }
            } free(del);
        }
    }
}

void delDest (Node *src, Details D) {
    Dest *del = src->dest;

    if (del) {
        Dest *prev = NULL; int found = 0;
        while (del && !found) {
            if (del->dest->detail.name == D.name) found = 1;
            else {
                prev = del;
                del = del->next;
            }
        }

        if (found) {
            if (!prev) {
                src->dest = del->next;
                del->next = NULL;
            } else {
                if (!del->next) prev->next = NULL;
                else {
                    prev->next = del->next;
                    del->next = NULL;
                }
            } free(del);
        }
    }
}

void delAll (Node *N) {
    Dest *current = N->dest;
    while (current) {
        Dest *del = current;
        current = current->next;
        N->dest = current;
        del->next = NULL;
        free(del);
    }
}

Node *findNode (Graph G, Details D) {
    Node *ret = NULL;
    Node *current = G.first;
    while (current && !ret) {
        if (current->detail.name == D.name) ret = current;
        else current = current->next;
    } return ret;
}

void printGraph (Graph G) {
    Node *current = G.first;
    while (current) {
        printf ("Node %c\n", current->detail.name);
        Dest *currDest = current->dest;
        while (currDest) {
            printf ("- Jalur %c ke %c\n", current->detail.name, currDest->dest->detail.name);
            currDest = currDest->next;
        } current = current->next;
    }
}
