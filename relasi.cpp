#include "semua_header.h"

void createListRelasi(ListRelasi &LR){
    first(LR)    =    NULL;
    last(LR) = NULL;
}
addressRelasi alokasiRelasi(addressKota refKota, addressJalan refJalan){
    addressRelasi R = new elementRelasi;
    refKota(R)=refKota;
    refJalan(R)=refJalan;
    nextR(R)  = NULL;
    prev(R) = NULL;
    return R;
}

void insertLastRelasi(ListRelasi &LR, addressRelasi R){
    if(first(LR)==NULL){
        first(LR)=R;
    }else{
        prev(R)=last(LR);
        nextR(last(LR))=R;
        last(LR)=R;
    }
}

addressRelasi searchRelasi(ListRelasi LR, addressKota refKota, addressJalan refJalan){
    addressRelasi R = first(LR);
    while(R != NULL){
        if((refKota(R)==refKota)&&(refJalan(R)==refJalan)){
            return R;
        }
        R = nextR(R);
    }
    return NULL;

}

void showRelasi(ListRelasi LR){
    if(first(LR)==NULL){
        cout << "Data Kosong" << endl;
    }else{
        addressRelasi R=first(LR);
        while(R != NULL){
            cout <<"------------------------------------------------------"<<endl;
            cout <<" Nama Kota  :"<<infoKota(refKota(R)).nama_kota <<endl;
            cout <<" ID Kota    :"<<infoKota(refKota(R)).id_kota <<endl;
            cout <<" Nama Jalan :"<<infoJalan(refJalan(R)).nama_jalan <<endl;
            cout <<" Tipe Jalan :"<< infoJalan(refJalan(R)).tipe_jalan <<endl;
            cout <<"------------------------------------------------------"<<endl;
            R=nextR(R);
        }
    }

}
