#include "..\headers\headerUtama.h"
#include <iostream>

void funcUndo(ListHuruf &L, Stack &stackUndo, Stack &stackRedo) {
    char inputAkhir;
    if (!isEmptyS(stackUndo)) {
        pop(stackUndo, inputAkhir);
        push(stackRedo, inputAkhir);

        if (inputAkhir != '|') {
            adrHuruf P;
            deleteLast(L, P);
        }
    }
}
