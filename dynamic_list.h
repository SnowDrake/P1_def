/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Picado Liñares, David LOGIN 1: david.picado
 * AUTHOR 2: Otero Agraso, Samuel LOGIN 2: s.agraso
 * GROUP: 1.5
 * DATE: 16 / 03 / 2020
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define LNULL NULL

/* Write your code here... */
typedef struct tNode * tPosL;
struct tNode {
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);
bool copyList(tList L1, tList* L2);
void updateVotes(tNumVotes a, tPosL p, tList* L);
void deleteAtPosition(tPosL p, tList* L);
void deleteList(tList* L);
tPosL findItem(tPartyName name, tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);


#endif
