#include "..\headers\headerUtama.h"
#include <iostream>

void redoHuruf(ListHuruf &L, Stack &stackUndo, Stack &stackRedo) {
    char karRedo;
    if (!isEmptyS(stackRedo)) {
        pop(stackRedo, karRedo);
        push(stackUndo, karRedo);

        if (karRedo != '|') {
            adrHuruf P = createElm(karRedo);
            insertLast(L, P);
        }
    }
}