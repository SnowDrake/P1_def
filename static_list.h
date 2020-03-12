/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Picado Liñares, David LOGIN 1: david.picado
 * AUTHOR 2: Otero Agraso, Samuel LOGIN 2: s.agraso
 * GROUP: 1.5
 * DATE: 16 / 03 / 2020
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include "list/list.h"

#define LNULL -1
#define MAX 25



typedef int tPosL;

typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
}tList;



void createEmptyList(tList* L);
/*
 * Objetivo: Crear una lista vacía
 * Entrada: Una lista tipo tList
 * Salida: La lista inicializada
 * Postcondición: La lista inicializada no presenta elementos
*/
bool insertItem(tItemL d, tPosL p, tList* L);
/*
 * Objetivo: Si la posición es nula (LNULL) se inserta el elemento en la última
 * posición de la lista. En caso contrario, se inserta en la posición anterior a la
 * posición dada
 * Entrada:
 *    tItemL d: Contenido del elemento principal a insertar
 *    tPosl p: Posición para la inserción
 *    tList *L: Lista donde escribimos el elemento
 * Salida: La lista tList *L tras haber insertado el elemento.
 * A su vez se devuelve un booleano que verifica si se ha insertado correctamente el elemento
 * Precondición: Que la lista haya sido inicializada
 * Postcondición: La posición de los elementos de la lista puede haberse modificado
*/
bool copyList(tList L1, tList* L2);
/*
 * Objetivo: Copiar el contenido de una lista en otra
 * Entrada:
 *    tList L1: Lista que vamos a copiar
 *    tList L2*: Lista donde se hará la copia
 * Salida:
 *    tList L2*: Copia de la lista L1
 *    Booleano que devuelva si se ha podido copiar la lista
 * Precondición: Ambas listas han de ser inicializadas. La lista L2* puede o no estar vacía.
*/
void updateVotes(tNumVotes a, tPosL p, tList* L);
/*
 * Objetivo: Modificar los votos del elemento situado en la posición dada.
 * Entradas:
 *    tNumVotes a: Valor de los votos que se quieran añadir a los correspondientes del partido
 *    tPosL p: Posición deseada donde se encuentra el elemento a ser modificado
 *    tList *L: Lista pasada para ser modificada
 * Salida: La lista tList *L tras haber modificado los votos del elemento correspondiente
 * Precondición: La lista ha de estar inicializada. La posición tPosL ha de ser válida en la lista
 * Postcondición: El orden de los elementos no se verá afectado
*/
void deleteAtPosition(tPosL p, tList* L);
/*
 * Objetivo: Elimina de la lista un elemento dado una posición
 * Entradas:
 *    tPosL p: Posición del elemento a ser eliminado
 *    tList *L: Lista a ser modificada
 * Salida: La lista tras haber sido modificada
 * Precondición: tPosL p es una posición válida de la lista
 * Postcondición: Las posiciones de los elementos de la lista pueden haber variado
*/
void deleteList(tList* L);
/*
 * Objetivo: Elimina todos los elementos de la lista
 * Entrada: tList *L a ser borrada
 * Salida: La lista vacía
 * Precondición: Lista inicializada
*/
tPosL findItem(tPartyName name, tList L);
/*
 * Objetivo: Devuelve la posición del primer elemento de la lista cuyo nombre de partido sea igual al indicado
 * Entrada:
 *    tPartyName name: Nombre del partido a ser buscado
 *    tList L: Lista donde se buscará el partido
 * Salida: Una posición, si se diese encontrado el partido se devuelve la posición en la lista.
 * En caso contrario se devuelve LNULL.
 * Precondición: La lista tList L ha de ser inicializada
*/
bool isEmptyList(tList L);
/*
 * Objetivo: Determinar si la lista está vacía
 * Entrada: Una lista L de tipo tList
 * Salida: Booleano determinando el objetivo
 * Precondición: La lista ha de estar previamente inicializada
*/
tItemL getItem(tPosL p, tList L);
/*
 * Objetivo: Devuelve el contenido de un elemento de la lista
 * Entradas:
 *    tPosL p: Posición del elemento a ser encontrado
 *    tList L: Lista donde encontrar el elemento
 * Salida: Se devolverá un tItemL procedente de la lista asociado a la posición aaportada
 * Precondición: La posición del elemento a ser buscado siempre será una válida en la lista,
 * y la lista ha de estar inicializada
*/
tPosL first(tList L);
/*
 * Objetivo: Devolver la primera posición de la lista
 * Entrada: Una lista L de tipo tList
 * Salida: La posición de tipo tPosL del primer elemento de la lista
 * Precondición: La lista no puede estar vacía y debe haber sido inicializada previamente
*/
tPosL last(tList L);
/*
 * Objetivo: Devuelve la posición del último elemento de la lista
 * Entrada: Una lista L de tipo tList
 * Salida: La posición tPosL del último elemento de la lista
 * Precondición: La lista ha de estar inicializada y no puede estar vacía
*/
tPosL previous(tPosL p, tList L);
/*
 * Objetivo: Devuelve la posición del elemento correspondiente a el de la posición dada
 * Entradas:
 *    tPosL p: Posición del elemento actual
 *    tList L: Lista en donde encontrar el elemento previo
 * Salida: La posición del elemento previo o nulo si tPosL p es el primer elemento de la lista
 * Precondición: tPosL p es una posición válida de la lista y la lista está inicializada
*/
tPosL next(tPosL p, tList L);
/*
 * Objetivo: Devuelve la posición del elemento siguiente a el de la posición dada
 * Entradas:
 *    tPosL p: Posición del elemento actual
 *    tList L: Lista en donde encontrar el elemento siguiente
 * Salida: La posición del elemento siguiente o nulo si tPosL p es el último elemento de la lista
 * Precondición: tPosL p es una posición válida de la lista, y la lista ha de estar inicializada
*/

#endif
