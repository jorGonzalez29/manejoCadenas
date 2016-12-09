#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DynamicPrototypeQueue.h"

void createQueue(Queue *q)
{
    q->first = NULL;
    q->last = NULL;
}

int emptyQueue(Queue *q)
{
    return q->first == NULL;
}

int fullQueue(Queue *q)
{
    void *aux = malloc(sizeof(node));
    free(aux);
    return aux == NULL;
}

int showFirstInQueue(Queue *q, info *d)
{
    if(!(q->first))
        return EMPTY_QUEUE;

    *d = q->first->data;
    return O_K;
}

int putInQueue(Queue *q, const info *d)
{
    node *newNode = (node *) malloc(sizeof(node));

    if(!newNode)
        return FULL_QUEUE;
    newNode->data = *d;
    newNode->next = NULL;
    if(q->first)
        q->last->next = newNode;
    else
        q->first = newNode;

    q->last = newNode;
    return O_K;
}

int takeOfQueue(Queue *q, info *d)
{
    node *aux;

    if(!(q->first))
        return EMPTY_QUEUE;
    aux = q->first;
    *d = aux->data;
    q->first = aux->next;
    if(q->first == NULL)
        q->last = NULL;
    free(aux);
    return O_K;
}

void clearQueue(Queue *q)
{
    node *aux;
    while(q->first)
    {
        aux = q->first;
        q->first = aux->next;
        free(aux);
    }
    q->last = NULL;
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
