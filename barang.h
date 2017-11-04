#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#define info(P) (P)->info

typedef struct barang
{
    string kode;
    string namabrg;
    int stok;
    int jmldibeli;
};

typedef barang infobarang;

typedef struct ElmListBarang *addressB;

typedef struct ElmListBarang
{
    infobarang info;
    addressB next;
    addressB prev;
};

typedef struct listBarang
{
    addressB first;
    addressB last;
};

void createListBarang(listBarang &L);
addressB alokasiBarang(infobarang x);
void dealokasiBarang(addressB &B);
void insertBarang(listBarang &L, addressB B);
addressB findBarang(listBarang L, infobarang x);
void deleteBarang(listBarang &L, addressB &B);
void printInfoBarang(listBarang L);

#endif // BARANG_H_INCLUDED
