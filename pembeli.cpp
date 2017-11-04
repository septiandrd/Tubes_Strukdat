#include "pembeli.h"

void createListPembeli(listPembeli &L) {
    first(L) = nil;
}


addressP alokasiPembeli(infopembeli x) {
    addressP P = new ElmListPembeli;
    info(P).ID = x.ID;
    info(P).nama = x.nama;
    next(P) = nil;
    return P;
}


void dealokasiPembeli(addressP &P) {
    delete P;
}


void insertPembeli(listPembeli &L, addressP P) { //INSERT PEMBELI (LAST)
    if ( first(L) == nil ) {
        first(L) = P;
    } else {
        addressP Q = first(L);
        while (next(Q)!=nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}


addressP findPembeli(listPembeli L, infopembeli x) { //MENCARI PEMBELI YANG MEMILIKI INFO = X
    addressP P = first(L);
    while (info(P).ID!=x.ID && P!=nil ) {
        P = next(P);
    }
    if (info(P).ID==x.ID) {
        return P;
    } else {
        return nil;
    }
}


void deletePembeli(listPembeli &L, addressP &P) { // MENGHAPUS PEMBELI P DARI LIST PEMBELI
    if (P==first(L) && next(P) == nil) {
        first(L) = nil;
    } else if (P==first(L)) {
        first(L) = next(P);
        next(P) = nil;
    } else {
        addressP Q = first(L);
        while (next(Q)!=P) {
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = nil;
    }
}


void printInfoPembeli(listPembeli L) { //MENAMPILKAN ISI LIST PEMBELI
    if (first(L)!=nil) {
        addressP P = first(L);
        while (P!=nil) {
            cout<<info(P).nama<<endl;
            P = next(P);
        }
    }
}


