#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;

struct Elm;
typedef Elm *adrList;

struct ElmHuruf;
typedef ElmHuruf *adrHuruf;

struct ElmHuruf
{
    char huruf;
    adrHuruf next;
};

struct ListHuruf
{
    adrHuruf first;
};
struct Elm
{
    string info;
    adrList next;
    adrList prev;
    adrHuruf huruf;
};

struct List
{
    adrList first;
    adrList last;
    adrList current;
};

const int MAXSIZE = 4;
typedef adrList infotypeS;
typedef int index;
struct Stack
{
    infotypeS info[MAXSIZE];
    index top;
};

typedef int infotypeQ;
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
void printListSemua(List L);
void createList(List &L);
adrList createElm(string x);
adrList createElm(string x);
void insertFirst(List &L, adrList P);
void insertLast(List &L, adrList P);
void insertAfter(List &L, adrList P, adrList pred);
void deleteFirst(List &L, adrList P);
void deleteLast(List &L, adrList P);
void deleteAfter(List &L, adrList P, adrList pred);
void printList(List L);
void printHuruf(List L);

void createStack(Stack &S);
bool isEmptyS(Stack S);
bool isFullS(Stack S);
void push(Stack &S, List P);
string Pop(Stack &stacks);
infotypeS peek(Stack S);
int sizeS(Stack S);
void printStack(Stack S);

Queue createQueue(Queue Q);
bool isEmptyQ(Queue Q);
void enqueue(Queue &Q, address P);
void dequeue(Queue &Q, address P);
address front(Queue Q);
infotypeQ sizeQ(Queue Q);

void redoHuruf(List &kalimat, Stack &stackUndo, Stack &stackRedo);
void undoHuruf(List &kalimat, Stack &stackUndo, Stack &stackRedo);

#endif // HEADER_H_INCLUDED
