#ifndef LISTDYNAMICPROTOTIPES_H_INCLUDED
#define LISTDYNAMICPROTOTIPES_H_INCLUDED
#include "prototypeFile.h"
#define WITHOUT_MEMORY 0
#define O_K 1
#define DUPLICATE_DATA 2
#define EMPTY_LIST 3
#define NOT_FOUND 4
#define compear compearBuyDni
#define accumulate accmulateAverage
#define MESS "Ingrese una opcion: \nB-Ordenar lista\nC-Remover nodo\nD-Ver nodo\nF-Poner al principio de la lista\nG-Poner al final de la lista\nH-Poner en orden\nI-FIN\nOpcion:"
#define OPTIONS "bcdfghi"

typedef struct node
{
    info data;
    struct node *next;
}node, *List;

/** primitive functions list **/

void createList(List *l);
int fullList(List *l);
int emptyList(List *l);
void clearList(List *l);
int putTheTopOfTheList(List *l, const info *d);
int putAnEndTheList(List *l, const info *d);
int putInOrder(List *l, const info *d, int (*compear)(const info*, const info*), void (*accumulate)(info*, const info*));
int compearBuyDni(const info *d1, const info *d2);
int compearBuySurNameAndFirstName(const info *d1, const info *d2);
void accmulateAverage(info *d1, const info *d2);
int removeFromList(List *l, const info *d, int (*compear)(const info *, const info *));
int searchNode(List *l, info *d, int (*compear)(const info *, const info *));
void putListInFile(List *l,FILE **fp);
void bubbleSortList(List *l);

/** menu functions **/
int menu(char *msj, char *options);

#endif // LISTDYNAMICPROTOTIPES_H_INCLUDED
