#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "headers\headerUtama.h"
#include "functions\primitiveLinkedList.cpp"
#include "functions\functionRedo.cpp"
#include "functions\primitiveQueue.cpp"
#include "functions\functionUndo.cpp"
#include "functions\primitiveStack.cpp"

using namespace std;

int main()
{

    ListHuruf L;
    createList(L);

    adrHuruf P, posisiCursor;
    char ch;

   // Menyisipkan kursor (|) pertama kali di awal
    // P = createElm('|');
    // insertFirst(L, P);

    while (true) {
        system("cls");  // Membersihkan layar
        printList(L);
        ch = getch();  // Membaca satu karakter tanpa menunggu Enter

        if (ch == 27) {  // Jika tombol ESC ditekan, keluar dari loop
            break;
        } else if (ch == 8) {  // Tombol BACKSPACE untuk hapus
            posisiCursor = cariCursor(L);
            // Jika cursor berada di elm pertama, dia tidak melakukan apa apa 
            if (posisiCursor->prev == nullptr) { 
                // kalo ga diisi apa apa gimana? error ga
                // gua mikir kalo kondisi posisiCursor->prev->prev == nullptr berada di if, bukan di else if,
                // dia punya kemungkinan error kalo posisi cursor di elm pertama, soalnya jadinya 
                // (posisiCursor->prev) = null, brati jadi null->prev maka error;
                
            }else if (posisiCursor->prev->prev == nullptr){ // Delete first
                deleteFirst(L,P);
                // push undo (P)
            }else if (posisiCursor->next == nullptr){ // Delete last
                deleteLast(L, P);
                // push undo (P)
            }else{
                // deleteBefore(L, P, posisiCursor);
                // push undo (P)
            }
        } else if (ch == 13) {  // Tombol ENTER (baris baru)
            // ini tolong dipikirin lagi misal enternya di tengah2 kalimat atau awal kalimat
            P = createElm('\n');
            posisiCursor = cariCursor(L);
            if (posisiCursor->prev == nullptr){
                insertFirst(L, P);
            }
            insertLast(L, P);
        } else if (ch == 91) {  // Tombol '[' (geser kursor kiri)
            // gatau dicoba pake arrow tetep belum berhasil
            cursorGeserKiri(L);
        } else if (ch == 93) {  // Tombol ']' (geser kursor kanan)
            // gatau dicoba pake arrow tetep belum berhasil
            cursorGeserKanan(L);
        } else {  // untuk insert (belum dipikirin semua kondisinya, misal insert ditengah dll)
            deleteLast(L, P);
            // push ke undo
            P = createElm(ch);
            insertLast(L, P);
            P = createElm('|');
            insertLast(L, P);
        }

    }
    
    cout << endl << "Terima kasih telah menggunakan notepad kami ^^" << endl;
}