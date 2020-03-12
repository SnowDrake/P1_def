/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Picado Liñares, David LOGIN 1: david.picado
 * AUTHOR 2: Otero Agraso, Samuel LOGIN 2: s.agraso
 * GROUP: 1.5
 * DATE: 16 / 03 / 2020
 */

#include <stdio.h>
#include "types.h"
#include <string.h>
#include <stdlib.h>

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif
#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef TEST_LIST
#include "list/list.h"
#endif


float devolverParam(char param[NAME_LENGTH_LIMIT+1]) {  // Función usada para convertir un string en un entero
    const char * str = param;
    float x;
    sscanf(param, "%f", &x);
    return x;
}

void print_list_STATS(tList list, char param[NAME_LENGTH_LIMIT+1], tNumVotes votosTotales, tNumVotes votosNulos) {
    tPosL pos;
    tItemL item;

    if (!isEmptyList(list)) {
        pos = first(list);
        while (pos != LNULL) { // Se itera hasta que se llega a la última posición de la lista
            item = getItem(pos, list);
            if (votosTotales == 0) { // Evitar el posible resultado de 0/0 = NaN
                printf("Party %s numvotes %d (0.00%%)\n", item.partyName, item.numVotes);
            }
            else if (votosTotales > 0) { // Denominador mayor que 0
                printf("Party %s numvotes %d (%.2f%%)\n", item.partyName, item.numVotes, ((float)item.numVotes/(float)votosTotales)*100);
            }
            pos = next(pos, list);
        }
    }
    else {
        printf("(Empty list)\n");
    }
    printf("Null votes %d\n", votosNulos);
    printf("Participation: %d votes from %s voters (%.2f%%)\n", votosTotales + votosNulos, param, (((float)votosTotales+(float)votosNulos)/devolverParam(param)*100)); // Uso de la función convertir string a entero
}

void crearPartido(tPartyName name, tList *lista) {
    /*
     * Declaración de una variable auxiliar de tipo tItemL
     * para inicializar el partido a votos 0 y como nombre
     * el valor del string "name"
    */
    struct tItemL newItem;
    newItem.numVotes = 0;
    strcpy(newItem.partyName, name);

    bool check; // Variable booleana de comprobación

    if (findItem(name, *lista) == LNULL) {
        check = insertItem(newItem, LNULL, lista); // Saber si se ha insertado correctamente el partido en la lista
        if (check == true) {
            printf("* New: party %s\n", getItem(findItem(name, *lista), *lista).partyName); // CORRECTO
        }
        else {
            printf("+ Error: New not possible\n"); // ERROR
        }
    }
    else {
        printf("+ Error: New not possible\n"); // El partido ya está en la lista
    }

}

void votarPartido(tPartyName name, tList *lista, tNumVotes *votosTotales, tNumVotes *votosNulos) {
    tPosL p; // Variable auxiliar
    p = findItem(name, *lista);
    int N = 0; // Variable que incrementa los votos del partido
    if (p == LNULL) { // El partido no existe en la lista
        printf("+ Error: Vote not possible. Party %s not found. NULLVOTE\n", name);
        *votosNulos = *votosNulos + 1; // Aumentamos los votos nulos
    }
    else {
        N = getItem(p, *lista).numVotes; // Valor de N a los votos del partido previo a ser votado por la función
        N++; // Incrementamos
        updateVotes(N, p, lista);
        printf("* Vote: party %s numvotes %d\n", name, getItem(p, *lista).numVotes);
        *votosTotales = *votosTotales + 1;
    }
}

void ilegalizarPartido(tPartyName name, tNumVotes *votosNulos, tNumVotes *votosTotales, tList *L) {
    tPosL p;
    p = findItem(name,*L);
    if(p == LNULL)
        printf("+ Error: Illegalize not possible\n"); // El partido no se encuentra en la lista
    else {
        *votosNulos = *votosNulos + getItem(p, *L).numVotes; // Se pasan los votos del partido a los votos nulos totales
        *votosTotales = *votosTotales - getItem(p, *L).numVotes; // Se restan de los votos totales válidos los del partido
        deleteAtPosition(p, L); // Borrado del partido
        printf("* Illegalize: party %s\n", name);
    }
}

void freeList(tList *L) {
    while (!isEmptyList(*L)) {
        deleteAtPosition(first(*L), L);
    }
}

void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1], tList *L, tNumVotes *votosTotales, tNumVotes *votosNulos) {

    switch(command) {
        case 'N': {
            // Creación del partido en la lista
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            crearPartido(param, L);
            break;
        }
        case 'V': {
            // Votar al partido
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            votarPartido(param, L, votosTotales, votosNulos);
            break;
        }
        case 'S': {
            // Estadística de la lista
            printf("********************\n");
            printf("%s %c: totalvoters %s\n", command_number, command, param);
            print_list_STATS(*L, param, *votosTotales, *votosNulos);
            break;
        }
        case 'I': {
            // Ilegalizar partido de la lista
            printf("********************\n");
            printf("%s %c: party %s\n", command_number, command, param);
            ilegalizarPartido(param, votosNulos, votosTotales, L);
            break;
        }
            // Para otros casos
        default: {
            printf("+ Fatal error: %c not avalaible as command\n", command);
            break;
        }
    }
}

void readTasks(char *filename, tList *L) {
    tNumVotes *votosNulos; /*Puntero de tipo tNumVotes para pasar los votos nulos registrados en la lista*/
    tNumVotes *votosTotales; /*Puntero de tipo tNumVotes para pasar los votos totales válido de la lista*/
    votosNulos = malloc(sizeof(tNumVotes));
    votosTotales = malloc(sizeof(tNumVotes));
    *votosNulos = 0;
    *votosTotales = 0;

    FILE *df;
    char command_number[CODE_LENGTH+1], command, param[NAME_LENGTH_LIMIT+1];

    df = fopen(filename, "r");
    if (df != NULL) {
        while (!feof(df)) {
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df,format, command_number, &command, param);
            processCommand(command_number, command, param, L, votosTotales, votosNulos);
        }
        fclose(df);
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    /*
     * Creación de la variable tList
     * e inicialización de la misma
    */

    tList *L;
    createEmptyList(L);


    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, L);

    // Función para liberar la lista de la memoria asociada
    freeList(L);

    return 0;
}