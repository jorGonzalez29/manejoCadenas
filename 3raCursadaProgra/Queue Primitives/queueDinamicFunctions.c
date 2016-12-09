#include <stdio.h>
#include "queueDinamicPrototipe.h"

void createQueue(tQueue *q)
{
    q->first = NULL;
    q->last = NULL;
}
int emptyQueue(tQueue *q)
{
    return q->first == NULL;
}
int fullQueue(tQueue *q)
{
    void aux = malloc(sizeof(node));
    free(aux);
    return aux == NULL;
}
int showFirstOnQueue(tQueue *q, info *d)
{
    if(!(q->first))
        return EMPTY_QUEUE;
    *d = q->first->data;
    return O_K;
}
int putOnQueue(tQueue *q, info *d)
{
    node *newNode = (node*) malloc(sizeof(node));

    if(!newNode)
        return FULL_QUEUE;

    newNode->data = *d;
    newNode->next = NULL;
    if(!(q->first))
        q->first = newNode;
    else
        q->last->next = newNode;
    q->last = newNode;
    return O_K;
}
int takeOfQueue(tQueue *q, info *d)
{
    node *aux;
    if(!(q->first))
        return EMPTY_QUEUE;

    aux = q->first;
    *d = aux->data;
    q->first = aux->next;
    if(!(q->first))
        q->last = NULL;
    free(aux);
    return O_K;
}
void clearQueue(tQueue *q)
{
    node *aux;
    while(q->first)
    {
        aux = q->first
        q->first = aux->next;
        free(aux);
    }
    q->last = NULL;
}
