#ifndef SEMUA_HEADER_H_INCLUDED
#define SEMUA_HEADER_H_INCLUDED

#include <conio.h>
#include <dos.h>
#include <istream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev

#define infoKota(P)  (P)->infoKota
#define infoJalan(Q) (Q)->infoJalan

#define nextR(R) (R)->nextR
#define refKota(R) (R)->refKota
#define refJalan(R) (R)->refJalan

using namespace std;

int system(const char);

//DEKLARASI LIST
typedef struct elementKota *addressKota;
typedef struct elementJalan *addressJalan;
typedef struct elementRelasi *addressRelasi;

//STRUKTUR DATA LIST
struct Kota {
    int id_kota;
    string nama_kota;
};
struct Jalan {
    string nama_jalan;
    string tipe_jalan;
};
struct Relasi {
    addressJalan Jalan;
    addressKota Kota;
};
//Kota menggunakanCircular double linked list
struct elementKota {
    Kota infoKota;
    addressKota next,prev;
};
//Jalan menggunakan single linked list
struct elementJalan {
    Jalan infoJalan;
    addressJalan next;
};
//Relasi menggunakan double  linked list
struct elementRelasi{
    addressKota refKota;
    addressJalan refJalan;
    addressRelasi nextR,prev;

};
struct ListKota {
    addressKota first;
    addressKota last;
};
struct ListJalan {
    addressJalan first;

};
struct ListRelasi {
    addressRelasi first;
    addressRelasi last;

};


//Procedure Welcome
void welcome();

//Procedure Menu
void menu(ListJalan &LJ, ListKota &LK, ListRelasi &LR);

//Procedure Kota
void createListKota(ListKota &LK);
addressKota alokasiKota(string nama_kota, int id_kota);
addressKota searchKota(ListKota LK, string nama_kota);
void insertsortKota(ListKota &LK, addressKota P);
void showKota(ListKota LK);
void deleteFirstKota(ListKota &LK, addressKota P);


//Procedure Jalan
void createListJalan(ListJalan &LJ);
addressJalan alokasiJalan(string nama_jalan,string tipe_jalan);
addressJalan searchJalanNama(ListJalan LJ, string nama_jalan);
addressJalan searchJalanTipe(ListJalan LJ, string tipe_jalan);
void insertfirstJalan(ListJalan &LJ,addressJalan Q);
void showJalan(ListJalan LJ);
void deleteFirstJalan(ListJalan &LJ, addressJalan Q);

//Procedure Relasi
void createListRelasi(ListRelasi &LR);
addressRelasi alokasiRelasi(addressKota refKota, addressJalan refJalan);
addressRelasi searchRelasi(ListRelasi LR, addressKota refKota, addressJalan refJalan);
void insertLastRelasi(ListRelasi &LR, addressRelasi R);
void showRelasi(ListRelasi LR);

//Procedure Sesudah direlasikan
void showKotaNamaJalan(ListRelasi LR, ListJalan LJ, ListKota LK, string nama_jalan);
void showJalanNamaKota(ListRelasi LR, ListJalan LJ, ListKota LK, string nama_kota);
void showKotaJalanTipeJalan(ListRelasi LR, ListJalan LJ, ListKota LK, string tipe_jalan);


#endif // SEMUA_HEADER_H_INCLUDED
