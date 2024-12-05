// #include "..\headers\headerUtama.h"
// #include <iostream>

// using namespace std;

// void createStack(Stack &S)
// {
//     S.top = 0;
// };

// bool isEmptyS(Stack S)
// {
//     return S.top == 0;
// }

// bool isFullS(Stack S)
// {
//     return S.top == MAXSIZE;
// }

// void push(Stack &S, char P)
// {
//     // if (S.top == MAXSIZE - 1)
//     // { // kondisi buat kalau stack penuh
//     //     cout << "Stack penuh, tidak dapat menambah state!" << endl;
//     //     return;
//     // }

//     // // periksa state nya kosong atau engga
//     // if (P.last == nullptr)
//     // {
//     //     cout << "Tidak ada state (current) pada list untuk ditambahkan ke stack!" << endl;
//     //     return;
//     // }

//     S.info[S.top] = P; // Simpan pointer ke elemen current dari List
//     S.top++;

//     // cout << "State '" << P.current->info << "' berhasil ditambahkan ke stack." << endl;
// }

// void pop(Stack &S, char &P)
// {
//     // if (!isFullS)
//     // {
//     //     P.first = S.info[S.top--];
//     //     S.top--;
//     // }
//     P = S.info[S.top];
//     S.top--;
// }

// infotypeS peek(Stack S)
// {
//     if (!isEmptyS)
//     {
//         return S.info[S.top];
//     }
//     else
//     {
//         return 'c';
//     }
// }

// int sizeS(Stack S)
// {
//     return S.top;
// }
