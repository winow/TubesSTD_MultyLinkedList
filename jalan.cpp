#include "semua_header.h"

void createListJalan(ListJalan &LJ){
    first(LJ)    =   NULL;
}

addressJalan alokasiJalan(string nama_jalan, string tipe_jalan){
    addressJalan Q  =   new elementJalan;
    infoJalan(Q).nama_jalan =   nama_jalan;
    infoJalan(Q).tipe_jalan =   tipe_jalan;
    next(Q) =   NULL;
    return Q;
};

addressJalan searchJalanNama(ListJalan LJ, string nama_jalan){
    addressJalan Q = first(LJ);
    while(Q != NULL){
        if(infoJalan(Q).nama_jalan == nama_jalan){
            return Q;
        }
        Q = next(Q);
    }
}

void insertfirstJalan(ListJalan &LJ,addressJalan Q){
    if(first(LJ)==NULL){
        first(LJ)=Q;
    }else{
        next(Q)=first(LJ);
        first(LJ)=Q;
    }
}

void showJalan(ListJalan LJ){

    if(first(LJ)==NULL){
        cout << "Data Jalan Tidak Ada!" <<endl;
    }else{
        addressJalan Q = first(LJ);
        while(Q!=NULL){
            cout << "----------------------------------------------------------"<<endl;
            cout << "Nama Jalan: " << infoJalan(Q).nama_jalan <<endl;
            cout << "Tipe Jalan: " << infoJalan(Q).tipe_jalan<<endl;
            cout << "----------------------------------------------------------"<<endl;
            Q = next(Q);
        }
    }
}
void deleteFirstJalan(ListJalan &LJ, addressJalan Q){
    if(first(LJ)!=NULL){
        Q = first(LJ);
        first(LJ)=next(Q);
        next(Q)=NULL;
    }
}

