#include "..\headers\headerUtama.h"
#include <iostream>
using namespace std;

Queue createQueue(Queue Q)
{
    Q.head = Q.tail = nullptr;
    return Q;
}

bool isEmptyQ(Queue Q)
{
    return Q.head;
}

void enqueue(Queue &Q, address P)
{

    if (isEmptyQ(Q))
    {
        Q.head = Q.tail = P;
    }
    else
    {
        P->prev = Q.tail;
        Q.tail->next = P;
        Q.tail = P;
    }
}

void dequeue(Queue &Q, address P)
{
    P = Q.head;
    if (!isEmptyQ)
    {
        if (Q.head != Q.tail)
        {
            Q.head = P->next;
            P->next = nullptr;
            Q.head->prev = nullptr;
        }
        else
        {
            Q.head = Q.tail = nullptr;
        }
    }
}

address front(Queue Q)
{
    address P;

    P = nullptr;
    if (!isEmptyQ(Q))
    {
        P = Q.head;
    }
    return P;
}

infotypeQ sizeQ(Queue Q)
{
    infotypeQ result;
    address P;

    result = 0;
    P = Q.head;
    while (P != nullptr)
    {
        result++;
        P = P->next;
    }
    return result;
}