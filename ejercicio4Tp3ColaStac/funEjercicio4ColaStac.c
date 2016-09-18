#include <stdio.h>
#include "protEjercicio4ColaStac.h"

void createQueue(Queue *q)
{
    q->pri = 0;
    q->ult = q->pri - 1;
    q->cant = 0;
}

int isQueueEmpty(const Queue *q)
{
    return q->cant == 0;
}

int isQueueFull(const Queue *q)
{
    return q->cant == TAM_COLA;
}

int putInQueue(Queue *q, const tInfo *d)
{
    if(q->cant == TAM_COLA)
        return COLA_LLENA;
    ++ q->ult;
    if(q->ult == TAM_COLA)
        q->ult = 0;
    q->info[q->ult] = *d;
    q->cant ++;
    return O_K;
}
int takeOfQueue(Queue *q, tInfo *d)
{
    if(q->cant == 0)
        return COLA_VACIA;
    q->cant --;
    *d = q->info[q->pri ++];
    if(q->pri == TAM_COLA)
        q->pri = 0;
    return O_K;
}
int showFirstInQueue(const Queue *q, tInfo *d)
{
    if(q->cant == 0)
        return COLA_VACIA;
    *d = q->info[q->pri];
    return O_K;
}
void emptyQueue(Queue *q)
{
    q->ult = q->pri - 1;
    q->cant = 0;
}
