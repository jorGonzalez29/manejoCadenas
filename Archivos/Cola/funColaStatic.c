#include <stdio.h>
#include <time.h>
#include "protColaStatic.h"
//Primitivas de cola estatica
void createTrain(const tqueue *p)
{
    p->first = rand() % TAM_COLA; //Me devuelve valores pseudos aleatorios entre 0 y 4
    p->last = p->first - 1;
    p->quantity = 0;
}

int queueFull(const tqueue *p)
{
    return TAM_COLA == p->quantity;
}
int queueEmpty(const tqueue *p)
{
    return p->quantity == 0;
}

int pushInqueue(const tqueue *p, tInfo *d)
{
    if(p->quantity == TAM_COLA)
        return 0;
    p->last ++;
    p->quantity ++;
    if(p->last == TAM_COLA)
        p->last = 0;
    p->train[p->last] = *d;

    return 1;
}
int pullOfQueue(const tqueue *p, tInfo *d)
{
    if(p->quantity == 0)
        return 0;
    *d = p->train[p->first];
    p->quantity --;
    p->first ++;
    if(p->first == TAM_COLA)
        p->first = 0;
    return 1;
}

int showFirstInQueue(const tqueue *p, tInfo *d)
{
    if(p->quantity == 0)
        return 0;

    *d = p->train[p->first];

    return 1;
}

void emptyQueue(const tqueue *p)
{
    p->quantity = 0;
    p->last = p->first - 1;
}











