#include "..\headers\headerUtama.h"

#include <iostream>
using namespace std;

void tampilan(){
    cout << "==============================================" << endl;
    cout << "    Selamat datang di Unyil Kucrit Notepad!" << endl;
    cout << "==============================================" << endl << endl << endl;
    cout << "===== Klik apapun untuk memulai mengetik =====" << endl;
}
void cursorGeserKiri(ListHuruf &L) {
    adrHuruf P = cariCursor(L);
    if (P != nullptr && P->prev != nullptr) {
        char temp = P->prev->huruf;
        P->prev->huruf = P->huruf;
        P->huruf = temp;
    }
}

void cursorGeserKanan(ListHuruf &L) {
    adrHuruf P = cariCursor(L);
    if (P != nullptr && P->next != nullptr) {
        char temp = P->next->huruf;
        P->next->huruf = P->huruf;
        P->huruf = temp;
    }
}


// void handleBackspace(ListHuruf &L) {
//     adrHuruf kursor = cariCursor(L);
//     if (kursor->prev != nullptr) {
//         adrHuruf sebelum = kursor->prev;
//         if (sebelum->prev != nullptr) {
//             sebelum->prev->next = kursor;
//         } else {
//             L.first = kursor;
//         }
//         kursor->prev = sebelum->prev;
//         delete sebelum;
//     }
// }


void createList(ListHuruf &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrHuruf createElm(char x) {
    adrHuruf P = new ElmHuruf;
    P->huruf = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

adrHuruf cariCursor(ListHuruf L) {
    adrHuruf P = L.first;

    while (P != nullptr) {
        if (P->huruf == '|') {
            return P; // Kursor ditemukan
        }
        P = P->next;
    }
    return nullptr; // Tidak mungkin terjadi, tetapi untuk keamanan
}


void insertUtama(ListHuruf &L, adrHuruf P, Stack &stackUndo) {
    adrHuruf kursor = cariCursor(L);

    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        insertBefore(L, P, kursor);
    }
    push(stackUndo, P->huruf, "Insert", kursor);
}

void insertFirst(ListHuruf &L, adrHuruf P) {
    L.first = P;
    L.last = P;

    Stack S;
    
}

void insertBefore(ListHuruf &L, adrHuruf P, adrHuruf pred) {
    // pred itu kursor
    P->prev = pred->prev;
    P->next = pred;
    if (pred->prev != nullptr) {
        pred->prev->next = P;
    } else {
        L.first = P;
    }
    pred->prev = P;
    
}

void printList(ListHuruf L) {
    adrHuruf P = L.first;
    cout << "===========================================" << endl;
    cout << "            UNYIL KUCRIT NOTEPAD       " << endl;
    cout << "===========================================" << endl;
    cout << "Note: Klik Escape untuk keluar dari notepad" << endl << endl;
    while (P != nullptr) {
        if (P->huruf == '\n'){
            // cout << endl;
        }
        cout << P->huruf; // Cetak huruf
        P = P->next;
    }
}

void deleteFirst(ListHuruf &L, adrHuruf &P){
    if (L.first != nullptr){
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
        // L.first->prev = nullptr;
    } else {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deleteLast(ListHuruf &L, adrHuruf &P){
    if (L.first != nullptr){
        P = L.last;
        L.last = L.last->prev;
        P->prev = nullptr;
        L.last->next = nullptr;
    } else {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deleteBefore(ListHuruf &L, adrHuruf &P, adrHuruf pred){
    if (pred->prev != nullptr){
        P = pred->prev;
        if (P->prev == nullptr) {
            L.first = pred;
        } else {
            P->prev->next = pred;
        }
        pred->prev = P->prev;
    }
}

void redoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo) {
    // char karRedo;
    // if (!isEmptyS(stackRedo)) {
    //     pop(stackRedo, karRedo);
    //     push(stackUndo, karRedo);

    //     if (karRedo != '|') {
    //         adrHuruf P = createElm(karRedo);
    //         insertUtama(L, P);
    //     }
    // }
}

void undoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo) {
    char huruf;
    string check;
    adrHuruf cursorUndo, P;
    adrHuruf cursorList = cariCursor(L);
    if (cursorList != L.first){
        pop(stackUndo, huruf, check, cursorUndo);
        //  cout << endl << stackUndo.cek[stackUndo.top] << endl;
        if (check == "Insert"){
            push(stackRedo, huruf, check, cursorUndo);
            cout << endl << huruf << endl;
            if (cursorUndo == cursorList){
                deleteBefore(L, P, cursorList);
            }else{
                deleteBefore(L, P, cursorUndo);
            }
        }else{
            push(stackRedo, huruf, check, cursorUndo);
            insertUtama(L, createElm(huruf), stackUndo);
        }
    }
    
    // char inputAkhir;
    // if (!isEmptyS(stackUndo)) {
    //     pop(stackUndo, inputAkhir);
    //     push(stackRedo, inputAkhir);

    //     if (inputAkhir != '|') {
    //         adrHuruf P;
    //         deleteLast(L, P);
    //     }
    // }
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
    if (!isFullS(S)){
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
