#include "library.h"

// prosedur untuk membuat stack
void createStack (Stack *S) {
    S->top = NULL;
}

// prosedur untuk menambahkan elemen ke dalam stack
void push (Stack *S, Details D) {
    Node *newNode = (Node*) malloc (sizeof(Node));      // alokasi memori elemen baru
    newNode->detail = D;                                // isi elemen baru
    if (!S->top) {                                      // jika stack kosong
        newNode->next = NULL;
    } else {                                            // jika stack tidak kosong
        newNode->next = S->top;
    }
    S->top = newNode;
    newNode = NULL;                                     // kosongkan pointer
}

// prosedur untuk memindahkan elemen dari stack S1 ke stack S2
void move (Stack *S1, Stack *S2) {
    if (S1->top) {                                      // jika stack S1 tidak kosong
        Node *move = S1->top;                               // tunjuk elemen teratas dari stack S1 yang akan dipindah

        // melepas elemen
        if (move->next) {                                   // jika elemen yang akan dipindah bukan elemen terakhir
            S1->top = move->next;
        } else {                                            // jika elemen yang akan dipindah adalah elemen terakhir
            S1->top = NULL;
        }

        // memasukkan elemen
        if (!S2->top) {                                     // jika stack S2 kosong
            move->next = NULL;
        } else {                                            // jika stack S2 tidak kosong
            move->next = S2->top;
        }
        S2->top = move;
        move = NULL;                                        // kosongkan pointer
    }
}

// prosedur untuk menampilkan isi dari stack S1 dan S2
void printStack (Stack S1, Stack S2) {
    Node *curr;
    int num1 = 0, num2 = 0;

    // isi stack ANGST
    printf ("==================================\n");
    printf ("Tontonan ANGST Abdul:\n");
    printf ("==================================\n");
    curr = S1.top;
    if (curr) {                                         // jika stack S1 tidak kosong
        while (curr) {                                      // print semua elemen stack S1 sesuai format
            num1++;
            printf ("%d. %s {%s Ending}\n", num1, curr->detail.title, curr->detail.type);
            curr = curr->next;
        }
    } else printf ("Abdul bersih dari kesedihan...\n"); // jika stack S1 kosong, print pesan ini

    // isi stack Non ANGST
    printf ("\n==================================\n");
    printf ("Tontonan Non ANGST Abdul:\n");
    printf ("===================================\n");
    curr = S2.top;
    if (curr) {                                         // jika stack S2 tidak kosong
        while (curr) {                                      // print semua elemen stack S2 sesuai format
            num2++;
            printf ("%d. %s {%s Endin9}\n", num2, curr->detail.title, curr->detail.type);
            curr = curr->next;
        }
    } else printf ("Rawan sekali...\n");                // jika stack S2 kosong, print pesan ini

    // kesimpulan tontonan Abdul
    printf ("\n-----------------------------------\n");
    if (num1 > num2) {
        printf ("Bawa ke psikiater sekarang..\n");          // jika jumlah elemen stack S1 lebih banyak dari S2
    } else if (num1 < num2) {
        printf ("Abdul bebas menonton..\n");                // jika jumlah elemen stack S1 lebih sedikit dari S2
    } else {
        printf ("Pantau truszzz..\n");                      // jika jumlah elemen stack S1 sama dengan S2
    }
    printf ("-----------------------------------\n");
}