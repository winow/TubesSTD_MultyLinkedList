#include "semua_header.h"

void showKotaNamaJalan(ListRelasi LR, ListJalan LJ, ListKota LK, string nama_jalan){
    addressKota refKota;
    addressJalan Q, refJalan;
    addressRelasi R;
    int i;
    i = 0;
    if((first(LJ)!= NULL)&&(first(LR)!=NULL)){
        Q = first(LJ);
        R = first(LR);
        while ((Q!=NULL)&&(infoJalan(Q).nama_jalan!=nama_jalan)){
            Q = next(Q);
        }
        if (Q!=NULL){
            while(R!=NULL){
                if(refJalan(R)=Q){
                    cout <<" ------------------- DATA KOTA --------------------"<<endl;
                    cout <<" Nama Kota  :"<<infoKota(refKota(R)).nama_kota<<endl;
                    cout <<" ID Kota    :"<<infoKota(refKota(R)).id_kota<<endl;
                    cout <<" --------------------------------------------------"<<endl;
                }
                R = nextR(R);
            }
        }else{
            Q = NULL;
            cout <<" Jalan tidak dimiliki kota"<<endl;
        }
    }

}
void showJalanNamaKota(ListRelasi LR, ListJalan LJ, ListKota LK, string nama_kota){
    addressJalan refJalan;
    addressKota P, refKota;
    addressRelasi R;
    int i;
    i = 0;
    if (first(LK)!=NULL){
        P = first(LK);
        while ((next(P)!=NULL)&&(infoKota(P).nama_kota!=nama_kota)){
            P = next(P);
        }
        if(infoKota(P).nama_kota==nama_kota){
            R = first(LR);
            while(R!=NULL){
                if(refKota(R)==P){
                    cout<<"-------------------- DATA JALAN -------------------"<<endl;
                    cout<<"Nama Jalan   :"<<infoJalan(refJalan(R)).nama_jalan<<endl;
                    cout<<"Tipe Jalan   :"<<infoJalan(refJalan(R)).tipe_jalan<<endl;
                    cout<<"---------------------------------------------------"<<endl;
                    i = i + 1;

                }R = nextR(R);
            }
        }
    }else{
        P = NULL;
        cout<<" Kota tidak memiliki Jalan"<<endl;
    }

}
void showKotaJalanTipeJalan(ListRelasi LR, ListJalan LJ, ListKota LK, string tipe_jalan){
    addressKota refKota;
    addressJalan Q, refJalan;
    addressRelasi R;
    int i;
    i = 0;
    if((first(LJ)!= NULL)&&(first(LR)!=NULL)){
        Q = first(LJ);
        R = first(LR);
        while ((Q!=NULL)&&(infoJalan(Q).tipe_jalan!=tipe_jalan)){
            Q = next(Q);
        }
        if (Q!=NULL){
            while(R!=NULL){
                if(refJalan(R)=Q){
                    cout <<" --------- DATA NAMA KOTA dan NAMA JALAN ---------"<<endl;
                    cout <<" Nama Kota  :"<<infoKota(refKota(R)).nama_kota<<endl;
                    cout <<" Nama Jalan :"<<infoJalan(refJalan(R)).nama_jalan<<endl;
                    cout <<" -------------------------------------------------"<<endl;
                }
                R = nextR(R);
            }
        }else{
            Q = NULL;
            cout <<" Nama Kota dan Nama Jalan tidak ada"<<endl;
        }
    }
}


