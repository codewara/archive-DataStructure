/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Praktikum 1 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin*/

#include "library.h"

int main () {
    int nT, nJ;
    char sort[2][16];

    // input makanan hewan milik Taufiq
    List Taufiq;
    Taufiq.first = NULL;
    scanf ("%d", &nT);
    Details DT[nT];
    for (int i = 0; i < nT; i++) {
        // input merk, jenis, dan sisa hari expire makanan hewan milik Taufiq
        scanf ("%s %s %d", DT[i].merk, DT[i].type, &DT[i].expire);

        // menghitung panjang string merk dan sisa hari
        DT[i].merkLen = 14 - strlen (DT[i].merk);           // 14 panjang maksimal kolom merk
        DT[i].expireLen = 9 - countDigit (DT[i].expire);    //  9 panjang maksimal kolom sisa hari
        addL (&Taufiq, DT[i]);
    }

    // input makanan hewan milik Jason
    List Jason;
    Jason.first = NULL;
    scanf ("%d", &nJ);
    Details DJ[nJ];
    for (int i = 0; i < nJ; i++) {
        // input merk, jenis, dan sisa hari expire makanan hewan milik Jason
        scanf ("%s %s %d", DJ[i].merk, DJ[i].type, &DJ[i].expire);

        // menghitung panjang string merk dan sisa hari
        DJ[i].merkLen = 14 - strlen (DJ[i].merk);           // 14 panjang maksimal kolom merk
        DJ[i].expireLen = 9 - countDigit (DJ[i].expire);    //  9 panjang maksimal kolom sisa hari
        addL (&Jason, DJ[i]);
    }
    // input tipe sorting
    scanf ("%s", sort[0]);      // merk atau sisa hari
    scanf ("%s", sort[1]);      // ascending atau descending

    // lakukan sorting makanan hewan milik Taufiq dan Jason
    sortL (&Taufiq, sort[0], sort[1]);
    sortL (&Jason, sort[0], sort[1]);

    // gabungkan dan print list makanan hewan milik Taufiq dan Jason
    mergeList (&Taufiq, &Jason, sort[0], sort[1]);

    return 0;
}