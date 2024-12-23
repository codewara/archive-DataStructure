/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Praktikum 4 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    // inisialisasi root
    Tree T; createTree (&T);

    Node* curr = T.root; // inisialisasi current directory
    int first = 1; Details D; // inisialisasi variabel
    char cmd[64]; scanf ("%s", cmd); // input command

    // loop sampai command exit
    while (strcmp (cmd, "exit;") != 0) {

        // jika command add
        if (!strcmp (cmd, "add")) {
            // input detail file dan tambahkan ke tree
            scanf (" %64[^-]-%d-%c %64[^;];", D.name, &D.size, &D.type, D.parent);
            addChild (&T, findNode (T.root, D, 0), D);

        // jika command del
        } else if (!strcmp (cmd, "del")) {
            // input nama file dan directory, lalu hapus file
            Details from; scanf ("%s %64[^;];", D.name, from.name);
            delChild (&T, findNode (T.root, D, 1), findNode (findNode (T.root, from, 1), D, 0));

        // jika command find
        } else if (!strcmp (cmd, "find")) {
            // input nama file dan directory, lalu cari file
            Details from; scanf ("%s %64[^;];", D.name, from.name);
            Node* N = findNode (findNode (T.root, from, 1), D, 1);
            if (!first) printf ("\n"); first = 0; // print newline jika bukan output pertama
            printf ("===== Find Output =====\n");
            // jika file ditemukan, print detail file
            if (N) printf ("[%c] %s(%dkB) Found!\n",N->detail.type, N->detail.name, N->detail.size);
            else printf ("[!] Not found!\n"); // jika tidak ditemukan, print not found

        // jika command nuke, hapus semua file
        } else if (!strcmp (cmd, "nuke;")) {
            delRoot (T);

        // jika command list, print tree secara preorder
        } else if (!strcmp (cmd, "list;")) {
            if (!first) printf ("\n"); first = 0; // print newline jika bukan output pertama
            printf ("===== File List =====\n");
            printTree (curr, 0);

        // jika command change
        } else if (!strcmp (cmd, "change")) {
            // input nama directory, lalu pindah ke directory tersebut
            scanf (" %64[^;];", D.name);
            curr = findNode (T.root, D, 1);
        } scanf ("%s", cmd); // input command lanjutan
    }   
    
    return 0;
}

/*
ADD    : add <name>-<size>-<type> <parent>;
         addChild (&T, findNode (T.root, D, 0), D);
         findNode([root], D, 0) untuk mencari direct-parent dari file yang akan ditambahkan,
         addChild() untuk menambahkan file tersebut.

DEL    : del <name> <root directory>;
         delChild (&T, findNode (T.root, D, 1), findNode (findNode (T.root, from, 1), D, 0));
         findNode([root], D, 1) untuk mencari file yang akan dihapus dalam tree,
         findNode([root], from, 1) untuk mencari root directory dari file yang akan dihapus dalam tree,
         findNode(findNode(from, 1), D, 0) untuk mencari direct-parent dari file yang akan dihapus dalam root directory,
         delChild() untuk menghapus file tersebut.

FIND   : find <name> <root directory>;
         Node* N = findNode (findNode (T.root, from, 1), D, 1);
         findNode([root], from, 1) untuk mencari root directory dari file yang akan dicari dalam tree,
         findNode(findNode(from, 1), D, 1) untuk mencari node dari file yang akan dicari dalam root directory,
         Node* N untuk menyimpan hasil pencarian file.

NUKE   : nuke;
         delRoot (T);
         delRoot() untuk menghapus semua file/directory dalam tree (kecuali root).

LIST   : list;
         printTree (curr, 0);
         printTree([current directory], 0) untuk menampilkan tree secara preorder.

CHANGE : change <new directory>;
         curr = findNode (T.root, D, 1);
         findNode([root], D, 1) untuk mencari directory yang akan diubah menjadi current directory.

EXIT   : exit;
         keluar dari program.
*/