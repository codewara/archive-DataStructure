/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Masa Depan pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    // inisialisasi tree, detail, dan variabel lainnya
    Tree T; Details D;
    char s[64]; int n;

    // input jumlah data
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %64[^#]#%64[^#]#%d#%d", D.name, D.parent, &D.duration, &D.qty);
        D.length = 11 + strlen(D.name) + digint (D.duration); // panjang node adalah 11 + panjang nama + panjang digit durasi
        D.matched = 0, D.level = 0; // inisialisasi variabel detail

        // jika parent adalah null
        if (!strcmp (D.parent, "null")) {
            createTree (&T, D); // buat tree dengan detail D

            // jika qty > 0, maka tambahkan list skill
            if (D.qty > 0) {
                for (int j = 0; j < D.qty; j++) {
                    scanf ("%s", s);
                    addList (T.root, s);
                }
            }

        // jika parent bukan null
        } else {
            Node* current = addChild (findNode (T.root, D), D); // tambahkan child dengan detail D

            // jika qty > 0, maka tambahkan list skill
            if (D.qty > 0) {
                for (int j = 0; j < D.qty; j++) {
                    scanf ("%s", s);
                    addList (current, s);
                }
            }
        }
    } scanf ("%s", s); // input nama node yang dicari

    // print semua node tree
    matchIndent (T.root); // match indentasi per level tree
    printMark (T.root, 0, s); // print semua node tree dan flag path dari node yang dicari

    // print tree setelah menghapus path lain
    delnot (T.root); // hapus path yang tidak sesuai
    matchIndent (T.root); // match indentasi per level tree
    int sum = printTree (T.root, 0); // print semua node tree dan hitung total durasi
    printf ("Untuk menjadi %s dibutuhkan waktu %d tahun.\n", s, sum); // print total durasi
    
    return 0;
}
