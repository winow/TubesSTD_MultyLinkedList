#include "semua_header.h"
int main()
{
    ListKota LK;
    ListJalan LJ;
    ListRelasi LR;

    createListKota(LK);
    createListJalan(LJ);
    createListRelasi(LR);

    welcome();
    menu(LJ,LK,LR);
    return 0;
}
