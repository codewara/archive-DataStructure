#include "library.h"

// prosedur untuk membuat stack
void createStack (Stack *S) {
    S->top = NULL;
}

// prosedur untuk menambahkan node ke stack
void push (Stack *S, Details D) {
    Node *newNode = (Node*) malloc (sizeof(Node));      // alokasi memori untuk node baru
    newNode->detail = D;                                // inisialisasi detail node
    if (!S->top) {                                      // jika stack kosong
        newNode->next = NULL;
    } else {                                            // jika stack tidak kosong
        newNode->next = S->top;
    }
    S->top = newNode;
    newNode = NULL;                                     // kosongkan pointer newNode
}

// prosedur untuk memindahkan node dari stack S1 ke stack S2
void move (Stack *S1, Stack *S2) {
    if (S1->top) {                                      // jika stack S1 tidak kosong
        Node *move = S1->top;                               // inisialisasi pointer move

        // lepaskan node dari stack S1
        if (move->next) {                                   // jika node bukan node terakhir
            S1->top = move->next;
        } else {                                            // jika node adalah node terakhir
            S1->top = NULL;
        }

        // tambahkan node ke stack S2
        if (!S2->top) {                                     // jika stack S2 kosong
            move->next = NULL;
        } else {                                            // jika stack S2 tidak kosong
            move->next = S2->top;
        }
        S2->top = move;
        move = NULL;                                        // kosongkan pointer move
    }
}

// prosedur untuk mencetak node dari stack
void printStack (Stack S1, Stack S2) {

    // print stack warna gelap
    printf("Stack Warna Gelap:\n");
    Node *curr = S1.top;
    if (curr) {                                     // jika stack tidak kosong
        while (curr) {                                  // print selama node tidak NULL
            printf("%s %d\n", curr->detail.color, curr->detail.level);
            curr = curr->next;
        }
    } else printf("kosong\n");                      // jika stack kosong, print "kosong"
    
    // print stack warna terang
    printf("\nStack Warna Terang:\n");
    curr = S2.top;
    if (curr) {                                    // jika stack kosong
        while (curr) {                                  // print selama node tidak NULL
            printf("%s %d\n", curr->detail.color, curr->detail.level);
            curr = curr->next;
        }
    } else printf("kosong\n");                      // jika stack kosong, print "kosong"
}