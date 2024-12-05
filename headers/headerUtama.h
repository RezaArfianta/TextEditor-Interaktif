#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;

struct ElmHuruf;
typedef ElmHuruf *adrHuruf;

struct ElmHuruf
{
    char huruf;
    adrHuruf prev;
    adrHuruf next;
};

struct ListHuruf
{
    adrHuruf first;
    adrHuruf last;
};

const int MAXSIZE = 4;
typedef char infotypeS;
typedef int index;
struct Stack
{
    infotypeS info[MAXSIZE];
    index top;
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
void printListSemua(ListHuruf L);
void createList(ListHuruf &L);
adrHuruf createElm(char x);
void insertFirst(ListHuruf &L, adrHuruf P);
void insertLast(ListHuruf &L, adrHuruf P);
void insertAfter(ListHuruf &L, adrHuruf P, adrHuruf pred);
void deleteFirst(ListHuruf &L, adrHuruf P);
void deleteLast(ListHuruf &L, adrHuruf P);
void deleteAfter(ListHuruf &L, adrHuruf P, adrHuruf pred);
void printList(ListHuruf L);
void printHuruf(ListHuruf L);
adrHuruf cariCursor(ListHuruf L);
void cursorGeserKiri(ListHuruf &L);
void cursorGeserKanan(ListHuruf &L);

void createStack(Stack &S);
bool isEmptyS(Stack S);
bool isFullS(Stack S);
void push(Stack &S, char P);
void pop(Stack &stacks, char &P);
infotypeS peek(Stack S);
int sizeS(Stack S);
void printStack(Stack S);

Queue createQueue(Queue Q);
bool isEmptyQ(Queue Q);
void enqueue(Queue &Q, address P);
void dequeue(Queue &Q, address P);
address front(Queue Q);
infotypeQ sizeQ(Queue Q);

void redoHuruf(ListHuruf &kalimat, Stack &stackUndo, Stack &stackRedo);
void funcUndo(ListHuruf &L, Stack &stackUndo, Stack &stackRedo);

#endif // HEADER_H_INCLUDED
