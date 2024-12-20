#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "headerUtama.h"

using namespace std;

int main()
{
    ListHuruf L;
    createList(L);

    Stack stackUndo, stackRedo;
    createStack(stackUndo);
    createStack(stackRedo);

    adrHuruf P, posisiCursor;
    char ch;
    tampilan(); // Menampilkan tampilan awal
    getch();    // Menunggu input pertama (untuk melanjutkan program)

    // Menyisipkan kursor (|) pertama kali di awal
    P = createElm('|');
    insertUtama(L, P, stackUndo);

    while (true)
    {
        system("cls"); // Membersihkan layar
        printList(L);  // Menampilkan list huruf
        cout << endl;

        ch = getch(); // Membaca satu karakter tanpa menunggu Enter
        cout << endl;
        // Menangani tombol ESC untuk keluar
        if (ch == 27)
        { // Jika tombol ESC ditekan, keluar dari loop
            break;
        }
        else if (ch == -32)
        {                 // Tombol panah (escape sequence)
            ch = getch(); // Membaca karakter berikutnya untuk arah panah
            if (ch == 77)
            { // Panah kanan (ASCII 77)
                cursorGeserKanan(L);
            }
            else if (ch == 75)
            { // Panah kiri (ASCII 75)
                cursorGeserKiri(L);
            }
            else if (ch == 72)
            {
                cursorGeserAtas(L);
            }
            else if (ch == 80)
            { // Panah bawah (ASCII 80)
                cursorGeserBawah(L);
            }
        }
        else if (ch == 13)
        { // Tombol Enter (ASCII 13)
            P = createElm('\n');
            insertUtama(L, P, stackUndo);
        }
        else if (ch == 26)
        { // Ctrl + Z untuk Undo (ASCII 26)
            undoHuruf(L, stackUndo, stackRedo);
        }
        else if (ch == 25)
        { // Ctrl + Y untuk redo
            redoHuruf(L, stackUndo, stackRedo);
        }
        else if (ch == 24)
        {
            // find text (ctrl+x)
            findOnText(L);
        }
        else if (ch == 8)
        { // backspace
            deleteBefore(L, P, cariCursor(L), stackUndo);
        }
        else if (ch == 7)
        { // Ctrl + G
            system("cls");
            showLegend();
            getch();
        }
        else
        {
            // Masukkan huruf biasa
            P = createElm(ch);
            cout << "Masuk else" << endl;
            insertUtama(L, P, stackUndo);
        }
    }

    setColor(6);
    cout << endl
         << "                                   -- TERIMA KASIH --                                   " << endl;
    setColor(7);
}
