#include <stdio.h>
#include <stdlib.h>
#include "queueStaticPrototipe.h"

void createQueue(tQueue *q)
{
    q->first = rand() % SIZE_QUEUE;
    q->last = q->first - 1;
    q->quantity = 0;
}
int emptyQueue(tQueue *q)
{
    return q->quantity;
}
int fullQueue(tQueue *q)
{
    return q->quantity == SIZE_QUEUE;
}
int showFirstOnQueue(tQueue *q, info *d)
{
    if(!(q->quantity))
        return EMPTY_QUEUE;
    *d = q->Queue[q->first];
    return O_K;
}
int putOnQueue(tQueue *q, info *d)
{
    if(q->quantity == SIZE_QUEUE)
        return FULL_QUEUE;

    q->quantity ++;
    q->last ++;
    if(q->last == SIZE_QUEUE)
        q->last = 0;
    q->Queue[q->last] = *d;
    return O_K;
}
int takeOfQueue(tQueue *q, info *d)
{
    if(!(q->quantity))
        return EMPTY_QUEUE;
    *d = q->Queue[q->first];
    q->first ++;
    q->quantity --;
    if(q->first == SIZE_QUEUE)
        q->first = 0;
    return O_K;
}
void clearQueue(tQueue *q)
{
    q->quantity = 0;
    q->last = q->first - 1;
}
