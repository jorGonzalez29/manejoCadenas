#include <stdio.h>
#include <stdlib.h>
#include "protEjercicio4ColaDim.h"

void createQueue(Queue *q)
{
    q->first = NULL;
    q->last = NULL;
}

int isQueueEmpty(const Queue *q)
{
    return q->first == NULL;
}

int isQueueFull(const Queue *q)
{
    void *aux = malloc(sizeof(sNode));
    free(aux);

    return aux == NULL;
}

int putInQueue(Queue *q, const tInfo *d)
{
    sNode *newNode = (sNode*) malloc(sizeof(sNode));
    if(newNode == NULL)
        return COLA_LLENA;

    newNode->info = *d;
    newNode->next = NULL;

    if(q->first == NULL)
    {
        q->first = newNode;
        q->last = newNode;
    }
    else
    {
        q->last->next = newNode;
        q->last = newNode;
    }

    return O_K;
}

int takeOfQueue(Queue *q, tInfo *d)
{
    if(q->first == NULL)
        return COLA_VACIA;
    sNode *aux;
    aux = q->first;
    *d = aux->info;
    q->first = aux->next;
    free(aux);
    return O_K;
}

int showFirstInQueue(const Queue *q, tInfo *d)
{
    if(q->first == NULL)
        return COLA_VACIA;
    *d = q->first->info;
    return O_K;
}

void emptyQueue(Queue *q)
{
    if(q->first == NULL)
    {
        sNode *aux;
        while(q->first != NULL)
        {
            aux = q->first;
            q->first = aux->next;
            free(aux);
        }
        q->last = NULL;
    }
}
