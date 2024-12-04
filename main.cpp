#include <iostream>
#include "headers\headerUtama.h"
#include "functions\menu\menu.cpp"

using namespace std;

int main()
{
    int pilihMenu;
    cout << "Welcome to YaReJol Text Editor!" << endl;
    pilihMenu = Menu();
    while (pilihMenu != 0)
    {
        if (pilihMenu == 1)
        {
            // MENGETIK TEKS
            cout << "Silahkan isi teks" << endl;
        }
        else if (pilihMenu = 2)
        {
            // EDIT TEKS
            cout << "Edit teks" << endl;
            // OPSI EDIT
        }
        else if (pilihMenu = 3)
        {
        }
        pilihMenu = Menu();
    }
}