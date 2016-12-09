#include<stdio.h>
#include <stdlib.h>
#include "stackDinamicPrototipe.h"

void createStack(pile *p)
{
    (*p) = NULL;
}
int emptyStack(pile *p)
{
    return (*p) == NULL;
}
int fullStack(pile *p)
{
    void *aux =  malloc(sizeof(node));
    free(aux);
    return aux == NULL;
}
int putOnStack(pile *p,info *d)
{
    node *newNode = (node*) malloc(sizeof(node));
    if(!newNode)
        return FULL_STACK;

    newNode->data = *d;
    newNode->next = (*p);
    (*p) = newNode;
    return O_K;
}
int takeOfStack(pile *p, info *d)
{
    //TODO: puedo sacar aux
    node *aux;
    if(!(*p))
        return EMPTY_STACK;

    aux = (*p);
    *d = aux->data;
    (*p) = aux->next;
    free(aux);
    return O_K;
}
int showTop(pile *p, info *d)
{
    if(!(*p))
        return EMPTY_STACK;

    *d = (*p)->data;
    return O_K;
}
void cleanStack(pile *p)
{
    node *aux;
    while((*p))
    {
        aux = (*p);
        (*p) = aux->next;
        free(aux);
    }
}
