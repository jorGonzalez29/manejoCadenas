#include <stdio.h>
#include "protCola.h"

void createQueue(const tqueue *p)
{
    p->first = NULL;
    p->last = NULL;
}

int queueFull(const tqueue *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);
    return aux == NULL;
}
int queueEmpty(const tqueue *p)
{
    return p->last == NULL;
}

int pushInqueue(const tqueue *p, tInfo *d)
{
    tNode *nue = (tNode*)malloc(sizeof(tNode));

    if(nue == NULL)
        return 0;

    nue->info = *d;
    nue->next = NULL;

    if(p->last == NULL)
        p->first = nue;
    else
        p->last->next = nue;

    p->last = nue;
    return 1;
}
int pullOfQueue(const tqueue *p, tInfo *d)
{
    tNode *aux;
    if(p->last == NULL)
        return 0;
    aux = p->first;
    *d = aux->info;
    p->first = aux->next;
    if(p->first == NULL)
        p->last = NULL;
    free(aux);
    return 1;

}

int showFirstInQueue(const tqueue *p, tInfo *d)
{
    if(p->last == NULL)
        return 0;
    *d = p->first->info;
    return 1;
}

void emptyQueue(const tqueue *p)
{
    tNode *aux;
    while(p->first)
   {
       aux = p->first;
       p->first = aux->next;
       free(aux);
   }
   p->last = NULL;
}
