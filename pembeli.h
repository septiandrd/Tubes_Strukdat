#ifndef PEMBELI_H_INCLUDED
#define PEMBELI_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define next(P) (P)->next
#define first(L) (L).first
#define info(P) (P)->info

typedef struct pembeli
{
    string ID;
    string nama;
};

typedef pembeli infopembeli;

typedef struct ElmListPembeli *addressP;

typedef struct ElmListPembeli
{
    infopembeli info;
    addressP next;
};

typedef struct listPembeli
{
    addressP first;
};

void createListPembeli(listPembeli &L);
addressP alokasiPembeli(infopembeli x);
void dealokasiPembeli(addressP &P);
void insertPembeli(listPembeli &L, addressP P);
addressP findPembeli(listPembeli L, infopembeli x);
void deletePembeli(listPembeli &L, addressP &P);
void printInfoPembeli(listPembeli L);

#endif // PEMBELI_H_INCLUDED
