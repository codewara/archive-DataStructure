/*Saya Datuk Daneswara Raditya Samsura dengan NIM 2308224 mengerjakan
Tugas Praktikum 2 pada Mata Kuliah Struktur Data untuk keberkahan-Nya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.
Aamiin*/

#include "library.h"

int main () {
    List B1, B2, P;
    Details D1[16], D2[16];
    int idx;
    char sort[3][16];

    // Input peserta batch 1
    idx = 0;
    createList (&B1);
    scanf ("%s", D1[0].name);
    // selama nama peserta bukan "selesai", maka lanjutkan
    while (strcmp (D1[idx].name, "selesai") != 0) {
        scanf ("%d %d", &D1[idx].wins, &D1[idx].losses);

        // hitung panjang data peserta
        D1[idx].len = 28 - (strlen (D1[idx].name) +
                      countDigit (D1[idx].wins) +
                      countDigit (D1[idx].losses));
        addL (&B1, D1[idx]);            // tambahkan peserta ke list
        idx++;                          // lanjut ke peserta selanjutnya
        scanf ("%s", D1[idx].name);
    }
    scanf ("%s", sort[0]);          // input jenis sorting batch 1 (ascending/descending)

    // Input peserta batch 2
    idx = 0;
    createList (&B2);
    scanf ("%s", D2[0].name);
    // selama nama peserta bukan "selesai", maka lanjutkan
    while (strcmp (D2[idx].name, "selesai") != 0) {
        scanf ("%d %d", &D2[idx].wins, &D2[idx].losses);

        // hitung panjang data peserta
        D2[idx].len = 28 - (strlen (D2[idx].name) +
                      countDigit (D2[idx].wins) +
                      countDigit (D2[idx].losses));
        addL (&B2, D2[idx]);            // tambahkan peserta ke list
        idx++;                          // lanjut ke peserta selanjutnya
        scanf ("%s", D2[idx].name);
    }
    scanf ("%s", sort[1]);          // input jenis sorting batch 2 (ascending/descending)

    createList (&P);
    scanf ("%s", sort[2]);          // input jenis sorting peserta profesional (ascending/descending)

    separate (&P, &B1, sort[2]);    // pisahkan peserta profesional dari batch 1
    separate (&P, &B2, sort[2]);    // pisahkan peserta profesional dari batch 2

    // sorting list sesuai input
    sortL (&B1, sort[0]);
    sortL (&B2, sort[1]);

    // cetak ketiga list
    printList (B1, B2, P);
    return 0;
}