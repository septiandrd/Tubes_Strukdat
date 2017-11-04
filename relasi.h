#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "pembeli.h"
#include "barang.h"
#include <iostream>
using namespace std;

#define nil NULL
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#define info(P) (P)->info
#define parent(P) (P)->parent
#define child(P) (P)->child


typedef struct ElmListRelasi *addressR;

typedef struct ElmListRelasi
{
    addressP parent;
    addressB child;
    addressR next;
    addressR prev;
};

typedef struct listRelasi
{
    addressR first;
    addressR last;
};

void createListRelasi(listRelasi &L);
addressR alokasiRelasi(addressP P, addressB B);
void dealokasiRelasi(addressR &R);
void insertRelasi(listRelasi &L, addressP P, addressB B);
addressR findRelasiPembeli(listRelasi L, addressP P);
addressR findRelasiBarang(listRelasi L, addressB B);
void deleteRelasiBarang(listRelasi &L, addressB B);
void deleteRelasiPembeli(listRelasi &L, addressP P);
void printRelasi(listRelasi L);
void printBarangDibeli(listRelasi L, addressP P);
void printPembeliBarang(listRelasi L, addressB B);

#endif // RELASI_H_INCLUDED
