#include <stdio.h>
#include <string.h>

#ifdef STATIC_LIST
#include "static_list.h"
#endif
#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif

void print_list(tList list) {
    tPosL pos;
    tItemL item;

    printf("(");
    if (!isEmptyList(list)) {
        pos = first(list);
        while (pos != LNULL) {
            item = getItem(pos, list);
            printf(" %s numVotes %d", item.partyName, item.numVotes);
            pos = next(pos, list);
        }
    }
    printf(")\n");
}

void crearPartido(tPartyName name, tList *lista) {
    struct tItemL newItem;
    bool check = false;
    if (findItem(name, *lista) != LNULL) {
        printf("No se ha podido introducir el partido.\n");
    }
    else {
        newItem.numVotes = 0;
        strcpy(newItem.partyName, name);
        check = insertItem(newItem, last(*lista), lista);
        if (check == false) {
            printf("No se ha podido crear el partido.\n");
        }
        else {
            printf("Partido creado %s\n", getItem(last(*lista), *lista).partyName);
        }
    }
}

void votarPartido(char name[NAME_LENGTH_LIMIT+1], tList *lista, int *votosTotales, int *votosNulos) {
    tPosL p;
    p = findItem(name, *lista);
    int N = 0; // Variable que incrementa los votos del partido
    if (p == LNULL) {
        printf("+ Error: Vote not possible. %s not found. NULLVOTE\n", name);
        *votosNulos = *votosNulos + 1;
    }
    else {
        N = getItem(p, *lista).numVotes;
        N++;
        updateVotes(N, p, lista);
        printf("* Vote: party %s numvotes %d\n", name, getItem(p, *lista).numVotes);
        *votosTotales = *votosTotales + 1;
    }
}

int main() {
    tList list;
    tPosL pos;
    tItemL item1, item2;

    /* init */
    item1.numVotes = 0;


    /* create */
    createEmptyList(&list);

    print_list(list);
    strcpy(item1.partyName, "party1");
    insertItem(item1, LNULL, &list);
    print_list(list);



    /* insert */
/*
    strcpy(item1.partyName, "party3");
    insertItem(item1, LNULL, &list);
    print_list(list);

    strcpy(item1.partyName, "partymarujita");
    insertItem(item1, LNULL, &list);
    print_list(list);

    strcpy(item1.partyName, "party1");
    insertItem(item1, first(list), &list);
    print_list(list);

    strcpy(item1.partyName, "party5");
    insertItem(item1, LNULL, &list);
    print_list(list);

    strcpy(item1.partyName, "party2");
    insertItem(item1, next(first(list),list), &list);
    print_list(list);

    strcpy(item1.partyName, "party4");
    insertItem(item1, last(list), &list);
    print_list(list);


    /* find */
    /*
    pos = findItem("party33", list);
    if (pos == LNULL) {
        printf("party33 Not found\n");
    }

    pos = findItem("party3", list);
    item2 = getItem(pos, list);
    printf("%s\n", item2.partyName);


    /* update */
    /*
    updateVotes(1, pos, &list);
    item2 = getItem(pos, list);
    printf("%s\n", item2.partyName);
    print_list(list);


    /* remove */
    /*
    deleteAtPosition(next(first(list),list), &list);
    print_list(list);

    deleteAtPosition(previous(last(list),list), &list);
    print_list(list);

    deleteAtPosition(first(list),&list);
    print_list(list);

    deleteAtPosition(last(list),&list);
    print_list(list);

    deleteAtPosition(first(list),&list);
    print_list(list);

    insertItem(item1, LNULL, &list);
    print_list(list); */

}
