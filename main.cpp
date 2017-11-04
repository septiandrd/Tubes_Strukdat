#include "pembeli.h"
#include "barang.h"
#include "relasi.h"

int main()
{
    listPembeli LP;
    listBarang LB;
    listRelasi LR;

    createListPembeli(LP);
    createListBarang(LB);
    createListRelasi(LR);

    infopembeli xp1;
    xp1.ID = 01;
    xp1.nama = "Adi";

    infopembeli xp2;
    xp2.ID = 02;
    xp2.nama = "Edo";

    infopembeli xp3;
    xp3.ID = 03;
    xp3.nama = "Lulu";

    infobarang xb1;
    xb1.kode = "B01";
    xb1.namabrg = "Oreo";
    xb1.stok = 10;
    xb1.jmldibeli = 0;

    infobarang xb2;
    xb2.kode = "B02";
    xb2.namabrg = "Bengbeng";
    xb2.stok = 10;
    xb2.jmldibeli = 0;

    infobarang xb3;
    xb3.kode = "B03";
    xb3.namabrg = "Kitkat";
    xb3.stok = 10;
    xb3.jmldibeli = 0;

    addressB b1 = alokasiBarang(xb1);
    addressB b2 = alokasiBarang(xb2);
    addressB b3 = alokasiBarang(xb3);

    addressP p1 = alokasiPembeli(xp1);
    addressP p2 = alokasiPembeli(xp2);
    addressP p3 = alokasiPembeli(xp3);

    insertPembeli(LP,p1);
    insertPembeli(LP,p2);
    insertPembeli(LP,p3);

    insertBarang(LB,b1);
    insertBarang(LB,b2);
    insertBarang(LB,b3);

    insertRelasi(LR,p1,b1);
    insertRelasi(LR,p1,b2);
    insertRelasi(LR,p3,b3);

    printInfoPembeli(LP);
    cout<<endl;
    printInfoBarang(LB);
    cout<<endl;
    printRelasi(LR);
    cout<<endl;
    printBarangDibeli(LR,p1);
    cout<<endl;
    printPembeliBarang(LR,b3);
    cout<<endl;

    deleteRelasiBarang(LR,b1);
    deleteBarang(LB,b1);

    printInfoPembeli(LP);
    cout<<endl;
    printInfoBarang(LB);
    cout<<endl;
    printRelasi(LR);

    return 0;
}
