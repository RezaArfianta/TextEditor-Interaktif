#include "..\headers\headerUtama.h"
#include "functionUndo.cpp"
#include "functionRedo.cpp"
#include "primitiveStack.cpp"
#include <iostream>
using namespace std;

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

void insertFirst(ListHuruf &L, adrHuruf P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(ListHuruf &L, adrHuruf P) {
    if (L.first != nullptr) {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    } else {
        L.first = P;
        L.last = P;
    }
}

adrHuruf cariCursor(ListHuruf L){
    adrHuruf P = L.first;

    while (P != nullptr){
        if (P->huruf == '|'){
            return P;
        }
    }
    // kalo ga ketemu, walaupun sebenernya pasti ketemu
    P = nullptr;
    return P;
}

void cursorGeserKiri(ListHuruf &L) {
    adrHuruf P = L.first;
    char temp;

    while (P != nullptr) {
        if (P->huruf == '|') {
            if (P->prev != nullptr){
                temp = P->prev->huruf;
                P->prev->huruf = P->huruf;
                P->huruf = temp;
                break;
            }
        }
        P = P->next;
    }
}

void cursorGeserKanan(ListHuruf &L) {
    adrHuruf P = L.first;
    char temp;

    while (P != nullptr) {
        if (P->huruf == '|') {
            if (P->next != nullptr){
                temp = P->next->huruf;
                P->next->huruf = P->huruf;
                P->huruf = temp;
                break;        
            }
        }
        P = P->next;
    }
}

void insertAfter(ListHuruf &L, adrHuruf P, adrHuruf pred) {
    if (pred != nullptr) {
        P->next = pred->next;
        P->prev = pred;
        if (pred->next != nullptr) {
            pred->next->prev = P;
        }
        pred->next = P;
        if (pred == L.last) {
            L.last = P;
        }
    }
}

void printList(ListHuruf L) {
    if (L.first == nullptr){
        cout << "Koniciwa Nii-San kyaa :3\n" << endl;
    }else{
        cout << "Koniciwa Nii-San kyaa :3\n" << endl;
        adrHuruf P = L.first;
        while (P != nullptr) {
            cout << P->huruf;
            P = P->next;
        }
    }
    
}

void deleteFirst(ListHuruf &L, adrHuruf P){
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

void deleteLast(ListHuruf &L, adrHuruf P){
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

void deleteAfter(ListHuruf &L, adrHuruf P, adrHuruf pred){
    if (L.first != nullptr){
        P = pred->next;
        pred->next= P->next;
        // P->next->prev = pred;
        // P->prev = nullptr;
        P->next = nullptr;
    } else {
        L.first = nullptr;
        L.last = nullptr;
    }
}