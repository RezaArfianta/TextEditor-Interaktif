#include "../../headers/headerUtama.h"
#include <iostream>
using namespace std;

int Menu()
{
    int xpilih = 999;
    cout << "------------MENU------------" << endl;
    cout << "1. Mengetik dalam teks editor" << endl;
    cout << "2. Edit dalam teks editor" << endl;
    cout << "3. Hapus semua" << endl;
    cout << "0. Exit Aplikasi" << endl;

    cout << "Enter nomor: ";
    cin >> xpilih;
    return xpilih;
}