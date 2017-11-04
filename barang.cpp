#include "barang.h"

void createListBarang(listBarang &L){
    first(L) = nil;
    last(L) = nil;
}
addressB alokasiBarang(infobarang x){
    addressB B = new ElmListBarang;
    info(B).kode = x.kode;
    info(B).namabrg = x.namabrg;
    info(B).stok = x.stok;
    info(B).jmldibeli = x.jmldibeli;
    next(B) = nil;
    prev(B) = nil;
    return B;
}

void dealokasiBarang(addressB &B){
    delete B;
}

void insertBarang(listBarang &L, addressB B){ // INSERT BARANG (LAST)
    if (first(L)==nil) {
        first(L) = B;
        last(L) = B;
    } else {
        next(last(L)) = B;
        prev(B) = last(L);
        last(L) = B;
    }
}

addressB findBarang(listBarang L, infobarang x){ // MENCARI BARANG YANG MEMILIKI INFO = X
    addressB B = first(L);
    while (info(B).kode!=x.kode || B!=nil) {
        B = next(B);
    }
    if (info(B).kode==x.kode) {
        return B;
    } else {
        return nil;
    }
}

void deleteBarang(listBarang &L, addressB &B){ // MENGHAPUS BARANG B DARI LIST BARANG
    if (B==first(L) && B==last(L)) {
        first(L) = nil;
        last(L) = nil;
    } else if (B==first(L)) {
        first(L) = next(first(L));
        next(B) = nil;
        prev(first(L)) = nil;
    } else if (B==last(L)) {
        last(L) == prev(last(L));
        prev(B) = nil;
        next(last(L)) = nil;
    }
}

void printInfoBarang(listBarang L){ // MENAMPILKAN ISI LIST BARANG
    if ( first(L)!=nil ) {
        addressB B = first(L);
        while (B!=nil) {
            cout<<info(B).namabrg<<endl;
            B=next(B);
        }
    }
}
