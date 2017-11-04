#include "relasi.h"

void createListRelasi(listRelasi &L){
    first(L) = nil;
    last(L) = nil;
}

addressR alokasiRelasi(addressP P, addressB B){
    addressR R = new ElmListRelasi;
    parent(R) = P;
    child(R) = B;
    next(R) = nil;
    prev(R) = nil;
    return R;
}

void dealokasiRelasi(addressR &R){
    delete R;
}

void insertRelasi(listRelasi &L, addressP P, addressB B){ // INSERT RELASI, MENGHUBUNGKAN PEMBELI P DENGAN BARANG B
    addressR R = alokasiRelasi(P,B);
    if ( first(L) == nil ) {
        first(L) = R;
        last(L) = R;
    } else {
        next(last(L)) = R;
        prev(R) = last(L);
        last(L) = R;
    }
}

addressR findRelasiPembeli(listRelasi L, addressP P){ //MENCARI PEMBELI P DI LIST RELASI
    addressR R = first(L);
    while (info(parent(R)).ID!=info(P).ID && R!=nil) {
        R = next(R);
    }
    if (R==nil){
        return nil;
    } else {
        return R;
    }
}

addressR findRelasiBarang(listRelasi L, addressB B){ //MENCARI BARANG B DI LIST RELASI
    addressR R = first(L);
    while (info(child(R)).kode!=info(B).kode && R!=nil) {
            cout<<"A";
        R = next(R);
    }
    if (info(child(R)).kode==info(B).kode){
        return R;
    } else {
        return nil;
    }
}

void deleteRelasi(listRelasi &L, addressR &R) { // MENGHAPUS RELASI R
    if (R==first(L) && R==last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else if (R==first(L)) {
        first(L) = next(first(L));
        next(R) = nil;
        prev(first(L)) = nil;
    } else if (R==last(L)) {
        last(L) = prev(last(L));
        next(last(L)) = nil;
        prev(R) = nil;
    }
}

void deleteRelasiBarang(listRelasi &L, addressB B){ // MENGHAPUS SEMUA RELASI YANG TERHUBUNG KE BARANG B
    addressR R = first(L);
    while (R!=nil){
        if ( info(child(R)).kode==info(B).kode ) {
            R = next(R);
            deleteRelasi(L,prev(R));
        } else {
            R = next(R);
        }
    }
}

void deleteRelasiPembeli(listRelasi &L, addressP &P){ // MENGHAPUS SELURUH RELASI YANG TERHUBUNG KE PEMBELI P
    addressR R = first(L);
    while (R!=nil){
        if (info(parent(R)).ID==info(P).ID) {
            R = next(R);
            deleteRelasi(L,prev(R));
        } else {
            R = next(R);
        }
    }
}

void printRelasi(listRelasi L){ // MENAMPILKAN ISI LIST RELASI
    addressR R = first(L);
    while (R!=nil){
        cout<<info(parent(R)).nama<<" - "<<info(child(R)).namabrg<<endl;
        R = next(R);
    }
}

void printBarangDibeli(listRelasi L, addressP P) { // MENAMPILKAN BARANG2 YANG DIBELI OLEH PEMBELI P
    cout<<"Pembeli : "<<info(P).nama<<endl;
    addressR R = first(L);
    while (R!=nil) {
        if ( info(parent(R)).ID == info(P).ID ) {
            cout<<" - "<<info(child(R)).namabrg<<endl;
        }
        R = next(R);
    }
}

void printPembeliBarang(listRelasi L, addressB B) { // MENAMPILKAN PEMBELI YANG MEMBELI BARANG B
    cout<<"Barang : "<<info(B).namabrg<<endl;
    addressR R = first(L);
    while (R!=nil) {
        if ( info(child(R)).kode == info(B).kode ) {
            cout<<" - "<<info(parent(R)).nama<<endl;
        }
        R = next(R);
    }
}
