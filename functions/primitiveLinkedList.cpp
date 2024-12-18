#include "headerUtama.h"
#include <conio.h>
#include <iostream>
using namespace std;

void tampilan()
{
    cout << "==============================================" << endl;
    cout << "    Selamat datang di Unyil Kucrit Notepad!" << endl;
    cout << "==============================================" << endl
         << endl
         << endl;
    cout << "===== Klik apapun untuk memulai mengetik =====" << endl;
}

void cursorGeserKiri(ListHuruf &L)
{
    adrHuruf P = cariCursor(L); // Temukan posisi kursor
    if (P != nullptr && P->prev != nullptr)
    {                             // Pastikan ada elemen sebelum kursor
        adrHuruf temp = P->prev;  // Elemen sebelum kursor
        adrHuruf Pnext = P->next; // Elemen setelah kursor

        // Mengubah posisi kursor
        P->prev = temp->prev; // Kursor sekarang mengarah ke elemen sebelum 'temp'
        P->next = temp;       // Kursor sekarang menjadi elemen setelah 'temp'

        if (temp->prev != nullptr)
        {
            temp->prev->next = P; // Menghubungkan elemen sebelumnya (temp->prev) dengan kursor (P)
        }
        else
        {
            L.first = P; // Jika 'temp' adalah elemen pertama, perbarui pointer first
        }
        cout << temp->prev->huruf << " Temp->prev sebelum" << endl; // Ubah prev untuk elemen sebelumnya agar mengarah ke kursor
        adrHuruf kursor = cariCursor(L);
        cout << "Address P: " << P << endl;
        cout << "Address temp->prev->next: " << temp->prev->next << endl;
        temp->prev = temp->prev->next;
        cout << "Address temp->prev: " << temp->prev << endl;
        cout << temp->prev->huruf << " Temp->prev sesudah" << endl; // Ubah prev untuk elemen sebelumnya agar mengarah ke kursor

        temp->next = Pnext;

        //        if (P->next != nullptr) {
        //            P->next->prev = temp;  // Menghubungkan elemen setelah kursor dengan 'temp'
        //        }
        if (Pnext != nullptr)
        {
            Pnext->prev = temp; // Jika ada elemen sebelum P, elemen tersebut mengarah ke temp
        }
        else
        {
            L.last = temp; // Jika P adalah elemen pertama, update pointer first
        }
    }
}

void cursorGeserKanan(ListHuruf &L)
{
    // adrHuruf P = cariCursor(L);
    // if (P != nullptr && P->next != nullptr) {
    //     char temp = P->next->huruf;
    //     P->next->huruf = P->huruf;
    //     P->huruf = temp;
    // }
    // adrHuruf P = cariCursor(L);
    // if (P!= nullptr && P->prev != nullptr){
    //     adrHuruf temp = P->next;
    //     adrHuruf Pprev = P->prev;

    //     P->next = temp->next;
    //     P->prev = temp;

    //     if (temp->next != nullptr){
    //         temp->next->prev = P;
    //     }else{
    //         L.last = P;
    //     }
    //     temp->next = P;
    //     temp->prev = Pprev;
    //     if (P->prev != nullptr){
    //         P->prev->next = temp;
    //     }
    // }
    adrHuruf P = cariCursor(L); // Temukan posisi kursor
    if (P != nullptr && P->next != nullptr)
    {                             // Pastikan ada elemen setelah kursor
        adrHuruf temp = P->next;  // Elemen setelah kursor
        adrHuruf Pprev = P->prev; // Elemen sebelum kursor

        // Mengubah pointer kursor (P) untuk bergerak ke kanan
        P->next = temp->next; // Kursor sekarang akan mengarah ke elemen setelah temp
        P->prev = temp;       // P sekarang menjadi elemen sebelumnya bagi temp

        if (temp->next != nullptr)
        {
            temp->next->prev = P; // Elemen setelah temp (jika ada) sekarang menunjuk ke P
        }
        else
        {
            L.last = P; // Jika temp adalah elemen terakhir, update pointer last
        }

        // Mengubah pointer temp untuk mengarah ke kursor
        temp->next = P; // Temp sekarang menjadi elemen setelah kursor
        cout << temp->next->huruf << "Kursor next pada geserKanan" << endl;
        temp->prev = Pprev; // Temp mengarah ke elemen sebelumnya kursor

        if (Pprev != nullptr)
        {
            Pprev->next = temp; // Jika ada elemen sebelum P, elemen tersebut mengarah ke temp
        }
        else
        {
            L.first = temp; // Jika P adalah elemen pertama, update pointer first
        }
    }
}

void createList(ListHuruf &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

adrHuruf createElm(char x)
{
    adrHuruf P = new ElmHuruf;
    P->huruf = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

adrHuruf cariCursor(ListHuruf L)
{
    adrHuruf P = L.first;

    while (P != nullptr)
    {
        if (P->huruf == '|')
        {
            return P; // Kursor ditemukan
        }
        P = P->next;
    }
    return nullptr; // Tidak mungkin terjadi, tetapi untuk keamanan
}

void insertUtama(ListHuruf &L, adrHuruf P, Stack &stackUndo)
{
    adrHuruf kursor = cariCursor(L);
    if (kursor != nullptr)
    {
        if (kursor->prev != nullptr)
        {
            cout << "kursor prev insert utama: " << kursor->prev->huruf << endl;
        }
    }

    if (L.first == nullptr)
    {
        insertFirst(L, P);
    }
    else
    {
        insertBefore(L, P, kursor);
    }
    push(stackUndo, P->huruf, "Insert", P);
    // cout << kursor << endl;
}

void insertFirst(ListHuruf &L, adrHuruf P)
{
    L.first = P;
    L.last = P;
}

void insertBefore(ListHuruf &L, adrHuruf P, adrHuruf pred)
{
    // pred itu kursor
    adrHuruf kursor = cariCursor(L);
    if (kursor != nullptr)
    {
        if (kursor->prev != nullptr)
        {
            cout << "kursor prev insert before: " << kursor->prev->huruf << endl;
            if (P->prev == nullptr)
            {
                cout << "P prev: Null" << endl;
            }
            else
            {
                cout << "P: " << P->huruf << endl;
            }
        }
    }
    if (pred->prev != nullptr)
    {
        // Jika elemen sebelumnya ada, kita atur hubungan antara elemen tersebut dan elemen baru
        P->prev = pred->prev; // P akan menunjuk ke elemen sebelum kursor
        P->next = pred;       // P menjadi elemen sebelum kursor

        pred->prev->next = P; // Elemen sebelum kursor (pred->prev) harus mengarah ke P
    }
    else
    {
        // Jika pred adalah elemen pertama, berarti P menjadi elemen pertama
        P->prev = nullptr;
        P->next = pred;
        L.first = P; // P menjadi elemen pertama
    }
    pred->prev = P; // Kursor (pred) harus menunjuk ke P
}

void printList(ListHuruf L)
{
    adrHuruf P = L.first;
    cout << "===========================================" << endl;
    cout << "            UNYIL KUCRIT NOTEPAD       " << endl;
    cout << "===========================================" << endl;
    cout << "Note: Klik Escape untuk keluar dari notepad" << endl
         << endl;
    adrHuruf X = cariCursor(L);
    if (X->prev != nullptr)
    {
        cout << "Kursor prev di printlist " << X->prev->huruf << endl;
    }

    while (P != nullptr)
    {
        if (P->huruf == '\n')
        {
            // cout << endl;
        }
        cout << P->huruf; // Cetak huruf
        P = P->next;
    }
}

void deleteFirst(ListHuruf &L, adrHuruf &P)
{
    if (L.first != nullptr)
    {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        // L.first->prev = nullptr;
    }
    else
    {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deleteLast(ListHuruf &L, adrHuruf &P)
{
    if (L.first != nullptr)
    {
        P = L.last;
        L.last = L.last->prev;
        P->prev = nullptr;
        L.last->next = nullptr;
    }
    else
    {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deleteBefore(ListHuruf &L, adrHuruf &P, adrHuruf pred, Stack &stackUndo)
{
    if (pred->prev != nullptr)
    {
        P = pred->prev;
        if (P->prev == nullptr)
        {
            L.first = pred;
        }
        else
        {
            P->prev->next = pred;
        }
        pred->prev = P->prev;
        push(stackUndo, P->huruf, "Delete", P);
    }
}

// char temp = P->prev->huruf;
// P->prev->huruf = P->huruf;
// P->huruf = temp;

void deletePointer(ListHuruf &L, adrHuruf &P, adrHuruf &pred)
{
    if (pred != nullptr)
    {
        P = pred;
        if (P->prev != nullptr)
        {
            cout << "Next " << P->prev->huruf << " = " << P->huruf << endl;
            P->prev->next = P->next;
        }
        else
        {
            L.first = P->next;
            L.first->prev = nullptr;
        }

        if (P->next != nullptr)
        {
            P->next->prev = P->prev;
        }
        else
        {
            cout << L.last->huruf << " = " << P->prev->huruf << endl;
            L.last = P->prev;
        }
    }
}

void redoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo)
{
    adrHuruf kursor, p;
    char P;
    string cek;
    if (!isEmptyS(stackRedo))
    {
        pop(stackRedo, P, cek, kursor);
        if (cek == "Insert")
        {
            push(stackUndo, P, cek, kursor);
            if (kursor->prev != nullptr)
            {
                kursor->prev->next = kursor;
            }
            else
            {
                L.first->prev = kursor;
                L.first = kursor;
            }
            if (kursor->next != nullptr)
            {
                kursor->next->prev = kursor;
            }
            else
            {
                L.last->next = kursor;
                L.last = kursor;
            }
        }
        else if (cek == "Delete")
        {
            push(stackUndo, P, cek, kursor);
            deletePointer(L, p, kursor);
        }
    }
}

void undoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo)
{
    char huruf;
    string check;
    adrHuruf cursorUndo, P;
    adrHuruf cursorList = cariCursor(L);

    if (!isEmptyS(stackUndo))
    {
        pop(stackUndo, huruf, check, cursorUndo);
        if (check == "Insert")
        {
            if (cursorUndo->huruf != '|')
            {
                push(stackRedo, huruf, check, cursorUndo);
                cout << "Kusor undo: " << cursorUndo << " " << cursorUndo->huruf << endl;
                deletePointer(L, P, cursorUndo);
                cout << "P: " << P << " " << P->huruf << endl;
            }

            // if (cursorList == cursorUndo){
            //     deleteBefore(L, P, cursorList);
            // }else{
            //     // cout << cursorUndo->next << " " << cursorUndo->next->huruf << endl;
            //     // deleteBefore(L, P, cursorUndo);
            //     // adrHuruf temp = cursorUndo->prev;
            //     deletePointer(L, P, cursorUndo);

            // }
        }
        else if (check == "Delete")
        {
            push(stackRedo, huruf, check, cursorUndo);
            cout << "Undo Delete: " << huruf << endl;
            // insert
            if (cursorUndo->prev != nullptr)
            {
                cursorUndo->prev->next = cursorUndo;
            }
            else
            {
                L.first->prev = cursorUndo;
                L.first = cursorUndo;
            }
            if (cursorUndo->next != nullptr)
            {
                cursorUndo->next->prev = cursorUndo;
            }
            else
            {
                L.last->next = cursorUndo;
                L.last = cursorUndo;
            }

            // insertUtama(L, createElm(huruf), stackUndo);
        }
    }
}

void createStack(Stack &S)
{
    S.top = 0;
};

bool isEmptyS(Stack S)
{
    return S.top == 0;
}

bool isFullS(Stack S)
{
    return S.top == MAXSIZE;
}

void push(Stack &S, char P, string cek, adrHuruf cursor)
{
    if (!isFullS(S))
    {
        S.info[S.top] = P;
        S.cek[S.top] = cek;
        S.cursor[S.top] = cursor;
        S.top++;
    }
}

void pop(Stack &S, char &P, string &cek, adrHuruf &cursor)
{
    if (!isEmptyS(S))
    {
        S.top--;
        P = S.info[S.top];
        cek = S.cek[S.top];
        cursor = S.cursor[S.top];
    }
}

infotypeS peek(Stack S)
{
    if (!isEmptyS)
    {
        return S.info[S.top];
    }
    else
    {
        return 'c';
    }
}

int sizeS(Stack S)
{
    return S.top;
}

void debug(ListHuruf L)
{
    adrHuruf P = L.first;
    while (P != nullptr)
    {
        if (P->huruf == '\n')
        {
            // cout << endl;
        }
        if (P->prev != nullptr && P->next != nullptr)
        {
            cout << "Elemen: " << P->huruf << " Prev: " << P->prev->huruf << " Next: " << P->next->huruf << endl; // Cetak huruf
        }
        else if (P->prev == nullptr && P->next == nullptr)
        {
            cout << "Elemen: " << P->huruf << " Prev: NULL" << " Next: NULL" << endl; // Cetak huruf
        }
        else if (P->prev == nullptr)
        {
            cout << "Elemen: " << P->huruf << " Prev: NULL" << " Next: " << P->next->huruf << endl;
        }
        else
        {
            cout << "Elemen: " << P->huruf << " Prev: " << P->prev->huruf << " Next: NULL" << endl;
        }
        P = P->next;
    }
    adrHuruf awal, akhir;
    awal = L.first;
    akhir = L.last;
    while (awal != nullptr)
    {
        cout << awal->huruf << " ";
        awal = awal->next;
    }
    cout << endl;
    while (akhir != nullptr)
    {
        cout << akhir->huruf << " ";
        akhir = akhir->prev;
    }
}

void insertAfter(ListHuruf &L, adrHuruf P, adrHuruf pred)
{
    P->prev = pred;
    if (pred->next != nullptr)
    {
        P->next = pred->next;
        pred->next->prev = P;
        pred->next = P;
    }
    else
    {
        pred->next = P;
    }
}

void stringToLL(ListHuruf &StringList, string text)
{
    if (text[0] == '\0')
    { // Handle empty string or null pointer
        nullptr;
    }
    else
    {
        // tidak menggunakan insert utama, namun manual insert saja//

        adrHuruf current;
        StringList.first = createElm(text[0]);
        current = StringList.first;
        // Iterate through the string and create nodes for each character

        for (int i = 1; i < text.length(); ++i)
        {
            current->next = createElm(text[i]);
            current = current->next;
        }
    }
}

void findOnText(ListHuruf L)
{
    ListHuruf findText;
    adrHuruf LNav, findNav, LNavTemp;
    string text;
    int totalFind = 0;
    int LCounter = 0;
    int findCounter = 0;
    // bool check = false;

    // insert kata/kalimat
    cout << "Cari kata/kalimat pada text editor: ";
    cin >> text;
    createList(findText);
    stringToLL(findText, text);
    // navigasi searching
    LNav = L.first;
    LNavTemp = L.first;
    findNav = findText.first;
    while (LNavTemp != nullptr)
    {
        // Reset pointer LNav dan findNav setiap iterasi utama
        LNav = LNavTemp;
        findNav = findText.first;

        LCounter = 0;
        findCounter = 0;

        while (findNav != nullptr && LNav != nullptr)
        {
            findCounter++;
            if (LNav->huruf == findNav->huruf)
            {
                LCounter++;
            }
            LNav = LNav->next;
            findNav = findNav->next;
        }

        // Periksa apakah kata yang dicari cocok
        if (LCounter == findCounter)
        {
            totalFind++;
        }

        // Lanjut ke node berikutnya
        LNavTemp = LNavTemp->next;
    }
    if (totalFind == 0)
    {
        cout << "'" << text << "' TIDAK ditemukan" << endl;
    }
    else
    {
        cout << "sebanyak " << totalFind << " '" << text << "' ditemukan pada text" << endl;
    }
    char ch;
    cout << "Press Enter to continue typing or Press Ctrl+G to replace!" << endl;
    while (true)
    {
        ch = getch();
        cout << int(ch) << endl;
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            replaceText(L, text);
            break;
        }
        else
        {
            cout << "Invalid input. Press Enter or Ctrl+G!" << endl;
        }
    }
    // replaceText(L, text);
}

void replaceText(ListHuruf &L, string text)
{
    ListHuruf findText;
    string rText;
    adrHuruf LNav, findNav, LNavTemp, RNavFirst;

    int totalFind = 0;
    int LCounter = 0;
    int findCounter = 0;

    createList(findText);
    stringToLL(findText, text);

    cout << "Replace menjadi: ";
    cin >> rText;
    // navigasi searching
    LNav = L.first;
    LNavTemp = L.first;
    findNav = findText.first;
    while (LNavTemp != nullptr)
    {
        // Reset pointer LNav dan findNav setiap iterasi utama
        LNav = LNavTemp;
        findNav = findText.first;
        RNavFirst = LNav;
        LCounter = 0;
        findCounter = 0;

        while (findNav != nullptr && LNav != nullptr)
        {
            findCounter++;
            if (LNav->huruf == findNav->huruf)
            {
                LCounter++;
            }
            LNav = LNav->next;
            findNav = findNav->next;
        }

        // Periksa apakah kata yang dicari cocok
        if (LCounter == findCounter)
        {
            int i;
            LNav = RNavFirst;
            for (i = 0; i < findCounter; i++)
            {
                // mengubah dan replace info sebuah Elm
                LNav->huruf = rText[i];
                LNav = LNav->next;
            }
            // mundur karena kelebihan
            LNav = LNav->prev;

            // menambah karakter apabila yang ingin di replace lebih pendek hurufnya
            if (findCounter < rText.length())
            {
                cout << "LINE 324" << endl;

                for (i = findCounter; i < rText.length(); i++)
                {
                    adrHuruf X;
                    X = createElm(rText[i]);
                    insertAfter(L, X, LNav);
                    LNav = X;
                }
            }
        }

        // Lanjut ke node berikutnya
        LNavTemp = LNavTemp->next;
    }
}
