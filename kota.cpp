#include "semua_header.h"

void createListKota(ListKota &LK){
    first(LK)    =   NULL;
    last(LK) = NULL;
}

addressKota alokasiKota(string nama_kota, int id_kota){
    addressKota P   =   new elementKota;
    infoKota(P).nama_kota =   nama_kota;
    infoKota(P).id_kota = id_kota;
    next(P) =   NULL;
    prev(P) = NULL;
    return P;
}


addressKota searchKota(ListKota LK, string nama_kota){
    addressKota P = first(LK);
    while(P != NULL){
        if (infoKota(P).nama_kota==nama_kota){
            return P;
        }
        P = next(P);
    }
}

void insertsortKota(ListKota &LK, addressKota P){
    addressKota prec,j;
    if (first(LK)==NULL){
        first(LK)=P;
        last(LK)=P;
        next(P)=NULL;
        prev(P)=NULL;

    }else if(next(first(LK))==NULL){
        if(infoKota(first(LK)).id_kota>=infoKota(P).id_kota){
               next(first(LK))=P;
               last(LK)=P;
        }else{
                next(P)=first(LK);
                first(LK)=P;
        }
    }else{
        prec = first(LK);
        while(prec!=NULL){
            j = next(prec);
            if((infoKota(P).id_kota<=infoKota(prec).id_kota) && (j!=NULL) && (infoKota(P).id_kota>=infoKota(j).id_kota)){
                next(P)=next(prec);
                next(prec)=P;
                prec = NULL;
                P = NULL;
            }else if((infoKota(P).id_kota<=infoKota(prec).id_kota)&&(j==NULL)){
                next(prec)=P;
                prec = NULL;
                P = NULL;
            }else{
                prec = next(prec);
            }
        }if(P!=NULL){
            next(P)=first(LK);
            first(LK)=P;
        }
    }
}
void showKota(ListKota LK){
    if (first(LK)!=NULL){
        addressKota P   =   first(LK);
        while (P!=NULL){
            cout << "-------------------------------------------------------"<<endl;
            cout << "Nama Kota  : " << infoKota(P).nama_kota <<endl;
            cout << " ID Kota   : " << infoKota(P).id_kota <<endl;
            cout << "-------------------------------------------------------"<<endl;
            P = next(P);
        }

    }else{
        cout << "Data Kota Tidak Ada!";
    }
}
void deleteFirstKota(ListKota &LK, addressKota P){
    if(first(LK) != NULL){
        P = last(LK);
        if(P == last(LK)){
            first(LK) = NULL;
            last(LK) = NULL;
        }
    }
    else{
        last(LK) = prev(P);
        prev(P) = NULL;
        next(last(LK)) = NULL;
    }
}
