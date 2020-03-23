/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Picado Liñares, David LOGIN 1: david.picado
 * AUTHOR 2: Otero Agraso, Samuel LOGIN 2: s.agraso
 * GROUP: 1.5
 * DATE: 16 / 03 / 2020
 */

#include "static_list.h"


void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}
bool isEmptyList(tList L) {
    return (L.lastPos == LNULL);
}
tPosL first(tList L) {
    return 0;
}
tPosL last(tList L) {
    return L.lastPos;
}
tPosL next(tPosL p, tList L) {
    if (p == L.lastPos) {
        return LNULL;
    }
    else {
        return ++p;
    }
}
tPosL previous(tPosL p, tList L) {
    return --p;
}
bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;
    if (L->lastPos == MAX - 1) { // Lista completa
        return false;
    }
    else {
        L->lastPos++;
        if (p == LNULL) {
            L->data[L->lastPos] = d;
        }
        else {
            for (i = L->lastPos;i >= p + 1; --i) {
                L->data[i] = L->data[i-1];
            }
            L->data[p] = d;
        }
    }
    return true;
}
void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;
    L->lastPos--;
    for (i = p;i <= L->lastPos; ++i) {
        L->data[i] = L->data[i+1];
    }
}
tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}
tPosL findItem(tPartyName name, tList L) {
    tPosL p = LNULL;
    if (L.lastPos == LNULL) {
        return LNULL;
    }
    else {
        for (int i = 0; (i < MAX); ++i) {
            if (strcmp(name, L.data[i].partyName) == 0) { // Uso de strcmp para comparar dos strings
                p = i;
            }
        }
    }
    return p;
}
bool copyList(tList L1, tList* L2) {
    tPosL p;
    for (p = 0;p <= L1.lastPos ; ++p) {
        L2->data[p] = L1.data[p];
    }
    L2->lastPos = L1.lastPos;
    return true;
}
void deleteList(tList* L) {
    while (L->lastPos != LNULL) {
        L->lastPos = LNULL; // El array seguirá estando en memoria
    }
}
void updateVotes(tNumVotes a, tPosL p, tList* L) {
    L->data[p].numVotes = a;
}






