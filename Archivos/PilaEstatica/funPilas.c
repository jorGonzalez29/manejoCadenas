#include <stdio.h>
#include "protPilaEstatic.h"

void createStack(tPile *p)
{
    p->top = 0;
}

int fullStack(tPile *p)
{
    return p->top == TAM_PILA;
}

int pushingOnStack(tPile *p, tInfo *d)
{
    if(p->top == TAM_PILA)
        return 0;

    p->pila[p->top] = *d;
    p->top ++;

    return 1;
}

int showTop(tPile *p, tInfo *d)
{
    if(p->top == 0)
        return 0;
    *d = p->pila[p->top - 1];
    return 1;
}

int takeOfStack(tPile *p, tInfo *d)
{
    if(p->top == 0)
        return 0;

    p->top --;
    *d = p->pila[p->top];

    return 1;
}

int ifEmptyStack(tPile *p)
{
    return p->top == 0;
}

void emptyStack(tPile *p)
{
    p->top = 0;
}
