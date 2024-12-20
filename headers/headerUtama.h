#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <windows.h>
using namespace std;

struct ElmHuruf;
typedef ElmHuruf *adrHuruf;

struct ElmHuruf {
    char huruf;
    char prevChar; // Karakter asli sebelum menjadi kursor
    adrHuruf next;
    adrHuruf prev;
};


struct ListHuruf
{
    adrHuruf first;
    adrHuruf last;
};

const int MAXSIZE = 9999;
typedef char infotypeS;
typedef int index;
struct Stack
{
    string cek[MAXSIZE];
    adrHuruf cursor[MAXSIZE];
    infotypeS info[MAXSIZE];
    index top = 0;
};

typedef char infotypeQ;
struct ElmQueue;
typedef ElmQueue *address;

struct ElmQueue
{
    infotypeQ info;
    address next;
    address prev;
};

struct Queue
{
    address head;
    address tail;
};

struct ElmBaris;
typedef ElmBaris *adrBaris;

struct ElmBaris {
    char baris;
    char prevBar;
    adrBaris next;
    adrBaris prev;
};

struct ListBaris {
    adrBaris first;
    adrBaris last;
};

void tampilan();
void printList(ListHuruf L);
void showLegend();
void setColor(int color);

void createList(ListHuruf &L);
adrHuruf createElm(char x);

void insertUtama(ListHuruf &L, adrHuruf P, Stack &stackUndo);
void insertFirst(ListHuruf &L, adrHuruf P);
void insertBefore(ListHuruf &L, adrHuruf P, adrHuruf pred);
void insertAfter(ListHuruf &L, adrHuruf P, adrHuruf pred);

void deleteFirst(ListHuruf &L, adrHuruf P);
void deleteLast(ListHuruf &L, adrHuruf P);
void deleteBefore(ListHuruf &L, adrHuruf &P, adrHuruf pred, Stack &stackUndo);
void deletePointer(ListHuruf &L, adrHuruf &P, adrHuruf &pred);

void stringToLL(ListHuruf &StringList, string text);
void findOnText(ListHuruf L);
void replaceText(ListHuruf &L, string text);

void printHuruf(ListHuruf L);
adrHuruf cariCursor(ListHuruf L);
void cursorGeserKiri(ListHuruf &L);
void cursorGeserKanan(ListHuruf &L);
void cursorGeserAtas(ListHuruf &L);
void cursorGeserBawah(ListHuruf &L);
int hitungSlashNNAIK(adrHuruf kursor);
int hitungSlashNBAWAH(adrHuruf kursor);

void createStack(Stack &S);
bool isEmptyS(Stack S);
bool isFullS(Stack S);
void push(Stack &S, char P, string cek, adrHuruf cursor);
void pop(Stack &S, char &P, string &cek, adrHuruf &cursor);
infotypeS peek(Stack S);
int sizeS(Stack S);
void printStack(Stack S);


void redoHuruf(ListHuruf &kalimat, Stack &stackUndo, Stack &stackRedo);
void undoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo);
void debug(ListHuruf L);

#endif // HEADER_H_INCLUDED
