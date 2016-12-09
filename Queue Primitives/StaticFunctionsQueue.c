#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "StaticPototypeQueue.h"

void createQueue(Queue *q)
{
    q->first = rand() % TAM_QUEUE;
    q->last = q->first - 1;
    q->quantity = 0;
}

int emptyQueue(Queue *q)
{
    return q->quantity == 0;
}

int fullQueue(Queue *q)
{
    return q->quantity == TAM_QUEUE;
}

int showFirstInQueue(Queue *q, info *d)
{
    if(!(q->quantity))
        return EMPTY_QUEUE;

    *d = q->vecQueue[q->first];
    return O_K;
}

int putInQueue(Queue *q, const info *d)
{
    if(q->quantity == TAM_QUEUE)
        return FULL_QUEUE;

    q->quantity ++;
    q->last ++;
    if(q->last == TAM_QUEUE)
        q->last = 0;
    q->vecQueue[q->last] = *d;
    return O_K;
}

int takeOfQueue(Queue *q, info *d)
{
    if(!(q->quantity))
        return EMPTY_QUEUE;
    q->quantity --;
    *d = q->vecQueue[q->first];
    q->first ++;
    if(q->first == TAM_QUEUE)
        q->first = 0;
    return O_K;
}

void clearQueue(Queue *q)
{
    q->last = q->first - 1;
    q->quantity = 0;
}

int menu(char *msj, char *options)
{
    char op;
    int b = 0;
    puts(msj);

    do
    {
        if(b)
            puts("Opcion incorrecta, vuelva a ingresar...");
        b = 1;
        fflush(stdin);
        scanf("%c", &op);
        op = tolower(op);
    }while(!strchr(options, op));
    return op;
}
