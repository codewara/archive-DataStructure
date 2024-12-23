#include "library.h"

// prosedur untuk inisialisasi root
void createTree (Tree* T) {
    // alokasi memori
    Node* node = (Node*) malloc(sizeof(Node));
    // inisialisasi detail root
    Details D;
    D.size = 0;
    D.type = 'D';
    strcpy (D.name, "Root");
    strcpy (D.parent, "NULL");
    // inisialisasi node root
    node->detail = D;
    node->sibling = NULL;
    node->child = NULL;
    T->root = node;
}

// prosedur untuk menambahkan child ke parent
void addChild (Tree* T, Node* parent, Details D) {
    // jika parent valid
    if (parent) {
        // alokasi memori dan inisialisasi node baru
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->detail = D;
        newNode->child = NULL;
        
        // jika parent tidak punya child, tambahkan child pertama
        if (!parent->child) {
            newNode->sibling = NULL;
            parent->child = newNode;

        // jika parent punya child
        } else {
            // jika child hanya 1, langsung tambahkan
            if (!parent->child->sibling) {
                newNode->sibling = parent->child;
                parent->child->sibling = newNode;

            // jika child lebih dari 1
            } else {
                Node* last = parent->child; // cari child terakhir
                while (last->sibling != parent->child) last = last->sibling;
                // tambahkan node baru pada child terakhir
                newNode->sibling = parent->child;
                last->sibling = newNode;
            }
        }

        // update size parent
        // jika parent adalah root, langsung update size parent
        if (!strcmp (parent->detail.name, "Root")) parent->detail.size += D.size;
        else {
            // jika parent bukan root, update size parent sampai root
            Node* current = parent; // cari parent sampai root
            while (strcmp (current->detail.name, "Root") != 0) {
                current->detail.size += D.size;
                current = findNode (T->root, current->detail, 0);
            } current->detail.size += D.size; // update size root
        }
    }
}

// prosedur untuk menghapus semua child dari root
void delRoot (Tree T) {
    // jika root punya child
    if (T.root->child) {
        Node* current = T.root->child;
        // jika child hanya 1, langsung hapus child
        if (!current->sibling) delChild (&T, current, T.root);
        else{
            // jika child lebih dari 1, hapus satu per satu
            while (current->sibling) { // hapus semua sibling child
                Node* temp = current->sibling;
                delChild (&T, current, T.root);
                current = temp;
            } delChild (&T, current, T.root); // hapus child terakhir
        }
    }
}

// prosedur untuk menghapus node dan semua child dari suatu node
void delAll (Node* node) {
    // jika node valid
    if (node) {

        // jika node punya child
        if (node->child) {

            // jika child hanya 1, langsung hapus child dan node
            if (!node->child->sibling) {
                delAll (node->child);
                free (node);

            // jika child lebih dari 1, hapus satu per satu
            } else {
                Node* target;
                Node* current = node->child; // hapus semua sibling child
                while (current->sibling != node->child) {
                    target = current;
                    current = current->sibling;
                    delAll (target);
                } delAll (current); // hapus child terakhir
                free (node); // hapus node
            }

        // jika node tidak punya child, langsung hapus node
        } else free (node);
    }
}

// prosedur untuk menghapus child dari direct parent
void delChild (Tree* T, Node* target, Node* parent) {
    // jika target dan parent valid, dan parent punya child
    if (target && parent && parent->child) {
        Node* current = parent->child;

        // jika child parent hanya 1
        if (!current->sibling) {
            if (current == target) { // jika target adalah child parent
                // update size parent sampai root
                Node* curr = parent; // cari parent sampai root
                while (strcmp (curr->detail.name, "Root") != 0) {
                    curr->detail.size -= target->detail.size;
                    curr = findNode (T->root, curr->detail, 0);
                } curr->detail.size -= target->detail.size; // update size root

                // hapus child
                delAll (current);
                parent->child = NULL;
            }
        
        // jika child lebih dari 1
        } else {
            int found = 0; Node* prev = NULL;
            while (current->sibling != parent->child && !found) { // cari target di sibling
                if (current == target) found = 1; // jika target ditemukan, flag found
                else { // jika target belum ditemukan, lanjut ke sibling berikutnya
                    prev = current;
                    current = current->sibling;
                }
            } if (current == target && !found) found = 1; // jika target ditemukan di child terakhir, flag found

            // jika target ditemukan
            if (found) {
                // update size parent sampai root
                Node* curr = parent; // cari parent sampai root
                while (strcmp (curr->detail.name, "Root") != 0) {
                    curr->detail.size -= target->detail.size;
                    curr = findNode (T->root, curr->detail, 0);
                } curr->detail.size -= target->detail.size; // update size root

                // hapus child
                Node* last = parent->child; // cari child terakhir
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

                    // jika target adalah child terakhir
                    if (current->sibling == parent->child) {
                        parent->child->sibling = NULL;

                    // jika target bukan child terakhir
                    } else {
                        prev->sibling = current->sibling;
                        current->sibling = NULL;
                    }
                } delAll (current); // hapus target
            }
        }
    }
}

// fungsi untuk mencari node berdasarkan detail
Node* findNode (Node* parent, Details target, int self) {
    Node* result = NULL; // inisialisasi hasil pencarian

    // jika parent valid
    if (parent) {

        // jika mencari node dan parent adalah target, input hasil pencarian
        if (self && !strcmp (parent->detail.name, target.name)) result = parent;
        // jika mencari direct-parent dan parent adalah direct-parent dari target, input hasil pencarian
        else if (!self && !strcmp (parent->detail.name, target.parent)) result = parent;

        // jika parent punya child
        else {
            Node* current = parent->child; // cari node di child
            if (current) {

                // jika child hanya 1
                if (!current->sibling) {

                    // jika mencari node dan current adalah target, input hasil pencarian
                    if (self && !strcmp (current->detail.name, target.name)) result = current;
                    // jika mencari direct-parent dan current adalah direct-parent dari target, input hasil pencarian
                    else if (!self && !strcmp (current->detail.name, target.parent)) result = current;

                    // jika hasil pencarian belum ditemukan, traverse ke child
                    else result = findNode (current, target, self);

                // jika child lebih dari 1
                } else {
                    int found = 0;
                    while (current->sibling != parent->child && !found) { // cari target di sibling

                        // jika mencari node dan current adalah target
                        if (self && !strcmp (current->detail.name, target.name)) {
                            result = current; found = 1; // input hasil pencarian dan flag found
                        // jika mencari direct-parent dan current adalah direct-parent dari target
                        } else if (!self && !strcmp (current->detail.name, target.parent)) {
                            result = current; found = 1; // input hasil pencarian dan flag found

                        // jika hasil pencarian belum ditemukan, traverse ke sibling berikutnya
                        } else {
                            result = findNode (current, target, self);
                            current = current->sibling;
                            if (result) found = 1; // jika hasil pencarian ditemukan, flag found
                        }
                    }
                    
                    // cek child terakhir
                    if (!found) {

                        // jika mencari node dan child terakhir adalah target, input hasil pencarian
                        if (self && !strcmp (current->detail.name, target.name)) result = current;
                        // jika mencari direct-parent dan child terakhir adalah direct-parent dari target, input hasil pencarian
                        else if (!self && !strcmp (current->detail.name, target.parent)) result = current;

                        // jika hasil pencarian belum ditemukan, traverse ke child
                        else result = findNode (current, target, self);
                    }
                }
            }
        }
    } return result; // return hasil pencarian
}

// prosedur untuk mencetak tree (preorder)
void printTree (Node* node, int spaces) {
    int sum = 0; // inisialisasi total size child

    // jika node valid
    if (node) {
        // print detail node
        printf("[%c] %s(%dkB)\n", node->detail.type, node->detail.name, node->detail.size);

        // jika node punya child, traverse ke child
        Node* current = node->child;
        if (current) {

            // jika child hanya 1, langsung print child
            if (!current->sibling) {
                for (int i = 0; i < spaces; i++) printf(" "); printf("└──"); // print indentasi child
                printTree (current, spaces + 4); // print child
            
            // jika child lebih dari 1
            } else {
                // loop untuk print semua sibling child
                while (current->sibling != node->child) {
                    for (int i = 0; i < spaces; i++) printf(" "); printf("├──"); // print indentasi child dari setiap sibling
                    printTree (current, spaces + 4); // print child dari setiap sibling
                    current = current->sibling; // traverse ke sibling berikutnya
                }
                for (int i = 0; i < spaces; i++) printf(" "); printf("└──"); // print indentasi child dari child terakhir
                printTree (current, spaces + 4); // print child dari child terakhir
            }
        }
    }
}
