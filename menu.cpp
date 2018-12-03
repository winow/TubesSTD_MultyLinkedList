#include "semua_header.h"

void menu(ListJalan &LJ, ListKota &LK, ListRelasi &LR){

    int pilihan, memilih,id_kota, jumlahRelasi;
    string nama_kota, nama_jalan, tipe_jalan,lagi;
    addressKota P,cekkota;
    addressJalan Q,cekjalan;
    addressRelasi R;

    Beranda:
    system("CLS");
    cout<<"--------------- PILIHAN MENU ----------------"<<endl;
    cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
    cout<<"|| 1.Tambah Data                           ||"<<endl;
    cout<<"|| 2.Tampilkan Data                        ||"<<endl;
    cout<<"|| 3.Hapus Data                            ||"<<endl;
    cout<<"|| 0.Keluar                                ||"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<" Inputkan Pilihan : ";
    cin>>pilihan;
    switch(pilihan){
    case 1:
        system("CLS");
        Menu:
        system("CLS");
        cout<<"------------ MENU TAMBAH DATA ---------------"<<endl;
		cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
        cout<<"|| 1.Tambah Data Kota                      ||"<<endl;
        cout<<"|| 2.Tambah Data Jalan                     ||"<<endl;
        cout<<"|| 3.Relasi Data Kota Dan Jalan	          ||"<<endl;
        cout<<"|| 4.Kembali                               ||"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<" Inputkan Pilihan : ";
        cin>>memilih;
        switch(memilih){
        case 1:
            system("CLS");
            MenuKota:
            system("CLS");
            cout<<"--------- MENU PENAMBAHAN DATA KOTA ---------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<" Nama Kota : ";
            cin.ignore();
            getline(cin,nama_kota);
            cekkota = searchKota(LK, nama_kota);
            if (cekkota==NULL){
                cout<<" ID Kota : ";cin>>id_kota;
                P = alokasiKota(nama_kota,id_kota);
                insertsortKota(LK, P);
                cout<<" Penambahan Data Berhasil!"<<endl;
                cout<<"--------------- DATA KOTA ---------------"<<endl;
                showKota(LK);
                cout<<" Masukkan data lagi? [Ya/Tidak](Tidak untuk kembali kemenu sebelumnya)    :";cin>>lagi;
                if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                    goto MenuKota;
                }else{
                    goto Menu;
                }
            }else{
                cout<<"Nama Kota telah ada!"<<endl;
                cout<<"--------------- DATA KOTA ---------------"<<endl;
                showKota(LK);
                cout<<" Masukkan data lagi? [Ya/Tidak](Tidak untuk kembali kemenu sebelumnya)    :";cin>>lagi;
                if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                    goto MenuKota;
                }else{
                    goto Menu;
                }
            }

        case 2:
            system("CLS");
            MenuJalan:
            system("CLS");
            cout<<"--------- MENU PENAMBAHAN DATA JALAN --------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<" Nama Jalan  :";
            cin.ignore();
            getline(cin,nama_jalan);
            cekjalan = searchJalanNama(LJ, nama_jalan);
            if (cekjalan==NULL){
                cout<<" Tipe Jalan  :";
                getline(cin,tipe_jalan);
                cin.ignore();
                Q = alokasiJalan(nama_jalan, tipe_jalan);
                insertfirstJalan(LJ,Q);
                cout<<" Penambahan Data Berhasil!"<<endl;
                cout<<"--------------- DATA JALAN ---------------"<<endl;
                showJalan(LJ);
                cout<<" Masukkan data lagi? [Ya/Tidak](Tidak untuk kembali kemenu sebelumnya)    :";cin>>lagi;
                if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                    goto MenuJalan;
                }else{
                    goto Menu;
                }
            }else{
                cout<<" Nama Jalan telah ada!"<<endl;
                cout<<"--------------- DATA JALAN ---------------"<<endl;
                showJalan(LJ);
                cout<<" Masukkan data lagi? [Ya/Tidak](Tidak untuk kembali kemenu sebelumnya)    :";cin>>lagi;
                if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                    goto MenuJalan;
                }else{
                    goto Menu;
                }
            }

        case 3:
            system("CLS");
            MenuRelasi:
            system("CLS");
            cout<<"---------------------- MENU PENAMBAHAN RELASI DATA ----------------------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<" Ket. Masukkan Nama Kota dan Nama Jalan yang ingin direlasikan."<<endl;
            cout<<" Nama Kota   :";cin.ignore();getline(cin,nama_kota);
            cekkota = searchKota(LK,nama_kota);
            P = cekkota;
            if(P!=NULL){
                cout<<" Nama Jalan  :";
                getline(cin,nama_jalan);cin.ignore();
                cekjalan = searchJalanNama(LJ,nama_jalan);
                Q = cekjalan;
                if(Q!=NULL){
                    R = alokasiRelasi(P, Q);
                    insertLastRelasi(LR,R);
                }
                cout<<" Penambahan Relasi Data Berhasil!"<<endl;
                cout<<"--------------- DATA RELASI ---------------"<<endl;
                showRelasi(LR);
                cout<<" RelasiData lagi? [Ya/Tidak](Tidak untuk kembali kemenu sebelumnya)    :";cin>>lagi;
                if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                    goto MenuRelasi;
                }else{
                    goto Menu;
                }
            }else {
                cout << "Inputkan Nama Kota yang benar? [Ya/Tidak] (Tidak untuk kembali)   :";cin>>lagi;
                    if((lagi=="Ya")||(lagi=="yA")||(lagi=="YA")||(lagi=="ya")||(lagi=="y")){
                        goto MenuRelasi;
                    }else{
                        goto Menu;
                    }
            }

        case 4:
            system("CLS");
            goto Beranda;
    }
    case 2:
        system("CLS");
        TampilkanData:
        system("CLS");
        cout<<"------------------------- MENU MENAMPILKAN DATA -------------------------"<<endl;
        cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
        cout<<" 1. Tampilkan semua Data Kota beserta Jalan "<<endl;
        cout<<" 2. Tampilkan Data Kota yang memiliki Nama Jalan tertentu "<<endl;
        cout<<" 3. Tampilkan Data Jalan yang dimiliki suatu Kota tertentu "<<endl;
        cout<<" 4. Tampilkan Data Kota dan Nama Jalan yang memiliki Tipe Jalan tertentu "<<endl;
        cout<<" 5. Kembali "<<endl;
        cout<<" Inputkan Pilihan : ";cin>>memilih;
        switch(memilih){
        case 1:
            system("CLS");
            cout<<"---------- DATA KOTA BESERTA JALAN ----------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            showRelasi(LR);
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto TampilkanData;
        case 2:
            system("CLS");
            cout<<"----- DATA KOTA YANG MEMILIKI NAMA JALAN -----"<<endl;
            cout<<"''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<"Inputkan Nama Jalan  :";cin.ignore();getline(cin,nama_jalan);
            showKotaNamaJalan(LR, LJ, LK, nama_jalan);
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto TampilkanData;
        case 3:
            system("CLS");
            cout<<"----- DATA JALAN YANG DIMILIKI SUATU KOTA -----"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<" Inputkan Nama Kota  :";cin.ignore();getline(cin,nama_kota);
            showJalanNamaKota( LR, LJ, LK, nama_kota);
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto TampilkanData;
        case 4:
            system("CLS");
            cout<<"--- DATA KOTA DAN NAMA JALAN YANG MEMILIKI TIPE DATA TERTENTU ---"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            cout<<" Inputkan Tipe Jalan :";cin.ignore();getline(cin,tipe_jalan);
            showKotaJalanTipeJalan( LR, LJ, LK, tipe_jalan);
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto TampilkanData;
        case 5:
            goto Beranda;
        }
    case 3:
        system("CLS");
        MenuHapus:
        system("CLS");
        cout<<"-------------- MENU HAPUS DATA --------------"<<endl;
        cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
        cout<<" 1. Hapus Data Kota                          "<<endl;
        cout<<" 2. Hapus Data Jalan                         "<<endl;
        cout<<" 3. Kembali                                  "<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<" Inputkan Pilihan    :";cin>>memilih;
        switch(memilih){
        case 1:
            system("CLS");
            cout<<"----------- MENU HAPUS DATA KOTA ------------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            deleteFirstKota(LK, P);
            cout<<" Penghapusan Data Berhasil!"<<endl;
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto MenuHapus;
        case 2:
            system("CLS");
            cout<<"----------- MENU HAPUS DATA JALAN -----------"<<endl;
            cout<<"'''''''''''''''''''''''''''''''''''''''''''''"<<endl;
            deleteFirstJalan(LJ, Q);
            cout<<" Penghapusan Data Berhasil!"<<endl;
            cout<<" Tekan Enter untuk kembali ";
            getch();
            goto MenuHapus;
        case 3:
            system("CLS");
            goto Beranda;
        }
    case 4:
        int close();
    }
}

