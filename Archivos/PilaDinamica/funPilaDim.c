#include <stdio.h>
#include "protPilaDim.h"

void createStack(tPile *p)
{
    *p = NULL;
}

int fullStack(tPile *p)
{
    tPile newNode = (tPile)malloc(sizeof(tNode)); // con tNode no m lo tomaba
    free(newNode);

    return newNode == NULL;
}

int pushingOnStack(tPile *p, tInfo *d)
{
    tPile newNode = (tPile)malloc(sizeof(tNode));
    if(newNode == NULL)
        return 0;
    newNode->info = *d;
    newNode->next = *p;
    *p = newNode;

    return 1;
}

int showTop(tPile *p, tInfo *d)
{
    if(*p == NULL)
        return 0;
    *d = (*p)->info;//ojo mirar
    return 1;
}

int takeOfStack(tPile *p, tInfo *d)
{
    tNode *auxNode;
    if(*p == NULL)
        return 0;
    auxNode = *p; //para poder liberar la memoria
    *d = (*p)->info;
    *p = (*p)->next;//preguntar bien punteros
    free(auxNode);
    return 1;
}

int ifEmptyStack(tPile *p)
{
    return *p == NULL;
}

void emptyStack(tPile *p,tInfo *d)
{
    tNode  *auxNode;

    while(*p)
    {
        auxNode = *p;
        *p = (*p)->next;
        free(auxNode);
    }
}
