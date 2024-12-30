#include "library.h"

int levSpace[64]; // variabel untuk menyimpan panjang indentasi tiap level

// prosedur untuk membuat tree
void createTree (Tree* T, Details D) {
    // alokasi memori untuk node root
    Node* node = (Node*) malloc(sizeof(Node));
    node->detail = D; // inisialisasi detail node
    // inisialisasi variabel node
    node->head = NULL;
    node->sibling = NULL;
    node->child = NULL;
    T->root = node;
}

// fungsi untuk menambahkan node baru sebagai child dari parent (return node baru)
Node* addChild (Node* parent, Details D) {
    Node* ret = NULL; // inisialisasi node baru

    // jika parent tidak kosong
    if (parent) {
        // alokasi memori untuk node baru
        Node* newNode = (Node*) malloc(sizeof(Node));
        // inisialisasi detail node baru
        newNode->detail = D;
        newNode->detail.level = parent->detail.level + 1;
        // inisialisasi variabel node baru
        newNode->head = NULL;
        newNode->child = NULL;
        
        // jika parent tidak memiliki child
        if (!parent->child) {
            newNode->sibling = NULL;
            parent->child = newNode;

        // jika parent memiliki child
        } else {

            // jika child parent hanya satu, maka node baru akan menjadi sibling dari child parent
            if (!parent->child->sibling) {
                newNode->sibling = parent->child;
                parent->child->sibling = newNode;
            
            // jika child parent lebih dari satu
            } else {
                Node* last = parent->child; // inisialisasi node terakhir
                while (last->sibling != parent->child) last = last->sibling;
                // node baru akan menjadi sibling dari node terakhir
                newNode->sibling = parent->child;
                last->sibling = newNode;
            }
        } ret = newNode; // node baru disimpan ke variabel return
    } return ret; // return node baru
}

// prosedur untuk menambahkan course baru ke dalam list
void addList (Node* parent, char s[]) {
    // jika parent tidak kosong
    if (parent) {
        // alokasi memori untuk list baru
        List* newNode = (List*) malloc(sizeof(List));
        // inisialisasi variabel list baru
        strcpy (newNode->course.name, s);
        newNode->course.length = strlen(s) + 4;
        newNode->next = NULL;
        
        // jika parent tidak memiliki list
        if (!parent->head) {
            parent->head = newNode; // list baru akan menjadi head dari parent

        // jika parent memiliki list
        } else {
            List* last = parent->head; // inisialisasi list terakhir
            while (last->next) last = last->next;
            last->next = newNode; // list baru akan menjadi next dari list terakhir
        }
    }
}

// prosedur untuk menghapus path yang tidak sesuai
void delnot (Node* root) {

    // jika root tidak kosong
    if (root->child) {
        // loop untuk mengecek semua child dari root
        Node* current = root->child;
        while (current->sibling) {
            Node* temp = current->sibling; // inisialisasi node sibling
            if (!current->detail.matched) delChild (current, root); // hapus child yang tidak sesuai
            current = temp;
        } if (!current->detail.matched) delChild (current, root); // hapus child terakhir
    } for (int i = 0; i < 64; i++) levSpace[i] = 0; // reset panjang indentasi tiap level
}

// prosedur untuk menghapus node dan semua childnya
void delAll (Node* node) {

    // jika node tidak kosong
    if (node) {

        // jika node memiliki list
        if (node->head) {
            List* current = node->head;
            while (current) { // loop untuk menghapus semua list
                List* temp = current->next;
                free(current);
                current = temp;
            }
        }

        // jika node memiliki sibling
        if (node->child) {

            // jika node memiliki satu sibling, maka hapus node dan semua childnya
            if (!node->child->sibling) {
                delAll (node->child);
                free (node);

            // jika node memiliki lebih dari satu sibling
            } else {
                Node* current = node->child; // loop untuk semua sibling
                while (current->sibling != node->child) {
                    Node* target = current;
                    current = current->sibling;
                    delAll (target); // hapus setiap node sibling dan semua childnya
                } delAll (current); // hapus sibling terakhir dan semua childnya
                free (node); // hapus node
            }

        // jika node tidak memiliki sibling, maka langsung hapus node
        } else free (node);
    }
}

// prosedur untuk menghapus child dari parent
void delChild (Node* target, Node* parent) {

    // jika target dan parent tidak kosong, dan parent memiliki child
    if (target && parent && parent->child) {
        Node* current = parent->child;

        // jika parent hanya memiliki satu child
        if (!current->sibling) {
            if (current == target) {
                delAll (current);
                parent->child = NULL;
            }

        // jika parent memiliki lebih dari satu child
        } else {
            int found = 0; Node* prev = NULL; // loop untuk mencari target
            while (current->sibling != parent->child && !found) {
                if (current == target) found = 1; // jika target ditemukan, flag found
                else { // jika target belum ditemukan, lanjut ke sibling berikutnya
                    prev = current;
                    current = current->sibling;
                }
            } if (current == target && !found) found = 1; // jika target ditemukan di sibling terakhir, flag found

            // jika target ditemukan
            if (found) {
                Node* last = parent->child; // loop untuk mencari sibling terakhir
                while (last->sibling != parent->child) last = last->sibling;
                
                // jika target adalah child pertama
                if (!prev) {

                    // jika target adalah satu-satunya child
                    if (current->sibling == last) {
                        parent->child = last;
                        last->sibling = NULL;
                    
                    // jika target bukan satu-satunya child
                    } else {
                        parent->child = current->sibling;
                        last->sibling = parent->child;
                    }

                // jika target bukan child pertama
                } else {

                    // jika target adalah sibling terakhir
                    if (current->sibling == parent->child) {
                        parent->child->sibling = NULL;

                    // jika target bukan sibling terakhir
                    } else {
                        prev->sibling = current->sibling;
                        current->sibling = NULL;
                    }
                } delAll (current); // hapus target dan semua childnya
            }
        }
    }
}

// fungsi untuk mencari node berdasarkan nama
Node* findNode (Node* parent, Details target) {
    Node* result = NULL; // inisialisasi node hasil pencarian

    // jika parent tidak kosong
    if (parent) {

        // jika parent adalah node yang dicari, maka return parent
        if (!strcmp (parent->detail.name, target.parent)) result = parent;

        // jika parent bukan node yang dicari, maka lanjut ke child parent
        else {
            Node* current = parent->child;
            if (current) {

                // jika parent hanya memiliki satu child
                if (!current->sibling) {
                    // jika child parent adalah node yang dicari, maka return child parent
                    if (!strcmp (current->detail.name, target.parent)) result = current;
                    // jika child parent bukan node yang dicari, maka traverse ke child parent
                    else result = findNode (current, target);
                
                // jika parent memiliki lebih dari satu child
                } else {
                    int found = 0; // loop untuk mencari node yang dicari
                    while (current->sibling != parent->child && !found) {
                        // jika child parent adalah node yang dicari
                        if (!strcmp (current->detail.name, target.parent)) {
                            result = current; // return child parent
                            found = 1; // flag found
                        // jika child parent bukan node yang dicari
                        } else {
                            result = findNode (current, target); // traverse ke sibling berikutnya
                            if (result) found = 1; // jika node ditemukan, flag found
                            else current = current->sibling; // jika node belum ditemukan, lanjut ke sibling berikutnya
                        }
                    }
                    
                    // jika node belum ditemukan di sebelum sibling terakhir
                    if (!found) {
                        // jika sibling terakhir adalah node yang dicari, maka return sibling terakhir
                        if (!strcmp (current->detail.name, target.parent)) result = current;
                        // jika sibling terakhir bukan node yang dicari, maka traverse ke sibling terakhir
                        else result = findNode (current, target);
                    }
                }
            }
        }
    } return result; // return node hasil pencarian
}

// prosedur untuk mencocokkan indentasi tiap level
void matchIndent (Node* root) {

    // jika root tidak kosong
    if (root) {
        Node* current = root; // inisialisasi node current
        int max = levSpace[root->detail.level]; // inisialisasi panjang indentasi maksimum

        // loop untuk mencari panjang indentasi maksimum
        do {
            if (current->detail.length > max) max = current->detail.length; // jika panjang indentasi lebih besar dari max, update max
            
            // jika node memiliki list
            if (current->head) {
                List* list = current->head; // loop untuk mencari panjang indentasi maksimum dari list
                while (list) {
                    // jika panjang indentasi lebih besar dari max, update max
                    if (list->course.length > max) max = list->course.length;
                    list = list->next; // lanjut ke list berikutnya
                }
            } current = current->sibling; // lanjut ke sibling berikutnya
        } while (current && current != root);

        levSpace[root->detail.level] = max; // simpan panjang indentasi maksimum ke array levSpace
        
        // jika root memiliki child
        if (root->child) {
            current = root->child;
            do { // loop untuk semua child root
                matchIndent(current); // rekursif untuk child root
                current = current->sibling; // lanjut ke sibling berikutnya
            } while (current && current != root->child);
        }
    }
}

// prosedur untuk mencetak indentasi
void printIndent (int spaces, int level) {
    for (int i = 0; i < spaces; i++) printf(" "); // cetak spasi level
    for (int i = level - 2; i >= 0; i--) { // loop untuk semua level sebelumnya
        for (int j = 0; j < levSpace[i]; j++) printf(" "); // cetak spasi level sebelumnya
    }
}

// prosedur untuk mencetak node yang sesuai
void printMark (Node* parent, int spaces, char s[]) {

    // jika parent tidak kosong
    if (parent) {

        // jika parent adalah node yang dicari
        if (!strcmp (parent->detail.name, s)) parent->detail.matched = 1; // flag matched
        printIndent (spaces, parent->detail.level); // cetak indentasi
        printf("[%s][%d tahun]\n", parent->detail.name, parent->detail.duration); // cetak detail node

        // jika parent memiliki list
        if (parent->head) {
            List* current = parent->head;
            while (current) { // loop untuk semua list
                printIndent (spaces, parent->detail.level); // cetak indentasi
                printf(" - %s\n", current->course.name); // cetak detail list
                current = current->next; // lanjut ke list berikutnya
            }
        } printf ("\n"); // cetak newline

        // jika parent memiliki child
        Node* current = parent->child;
        if (current) {

            // jika parent hanya memiliki satu child
            if (!current->sibling) {
                printMark (current, levSpace[parent->detail.level], s); // rekursif untuk child parent
                if (current->detail.matched) parent->detail.matched = 1; // flag matched jika child matched

            // jika parent memiliki lebih dari satu child
            } else {
                while (current->sibling != parent->child) { // loop untuk semua sibling
                    printMark (current, levSpace[parent->detail.level], s); // rekursif untuk sibling
                    if (current->detail.matched) parent->detail.matched = 1; // flag matched jika sibling matched
                    current = current->sibling; // lanjut ke sibling berikutnya
                } printMark (current, levSpace[parent->detail.level], s); // rekursif untuk sibling terakhir
                if (current->detail.matched) parent->detail.matched = 1; // flag matched jika sibling terakhir matched
            }
        }
    }
}

// fungsi untuk mencetak tree (return total durasi course yang telah dicetak)
int printTree (Node* node, int spaces) {
    int sum = 0; // inisialisasi total durasi course

    // jika node tidak kosong
    if (node) {
        // jika node matched, tambahkan durasi course ke total durasi
        if (node->detail.matched) sum += node->detail.duration;
        printIndent (spaces, node->detail.level); // cetak indentasi
        printf("[%s][%d tahun]\n", node->detail.name, node->detail.duration); // cetak detail node

        // jika node memiliki list
        if (node->head) {
            List* current = node->head;
            while (current) { // loop untuk semua list
                printIndent (spaces, node->detail.level); // cetak indentasi
                printf(" - %s\n", current->course.name); // cetak detail list
                current = current->next; // lanjut ke list berikutnya
            }
        } printf ("\n"); // cetak newline

        // jika node memiliki child
        Node* current = node->child;
        if (current) {

            // jika node hanya memiliki satu child, maka rekursif untuk child node
            if (!current->sibling) {
                sum += printTree (current, levSpace[node->detail.level]);

            // jika node memiliki lebih dari satu child
            } else {
                while (current->sibling != node->child) { // loop untuk semua sibling
                    sum += printTree (current, levSpace[node->detail.level]); // rekursif untuk sibling
                    current = current->sibling; // lanjut ke sibling berikutnya
                } sum += printTree (current, levSpace[node->detail.level]); // rekursif untuk sibling terakhir
            }
        }
    } return sum; // return total durasi course
}

// fungsi untuk menghitung jumlah digit
int digint (int n) {
    int ret = 0;
    if (n == 0) ret = 1; // jika angka = 0, return 1
    else while (n > 0) n /= 10, ret++; // jika angka > 0, hitung jumlah digit
    return ret;
}