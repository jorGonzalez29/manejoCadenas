#include <stdio.h>
#include "stackPrototipe.h"

void createStack(pile *p)
{
    p->top = 0;
}
int emptyStack(pile *p)
{
    return !(p->top);
}
int fullStack(pile *p)
{
    return p->top == SIZE_STACK;
}
int putOnStack(pile *p,info *d)
{
    if(p->top == SIZE_STACK)
        return FULL_STACK;

    p->Stack[p->top] = *d;
    p->top ++;
    return O_K;
}
int takeOfStack(pile *p, info *d)
{
    if(!(p->top))
        return EMPTY_STACK;

    p->top --;
    *d = p->Stack[p->top];
    return O_K;
}
int showTop(pile *p, info *d)
{
    if(!(p->top))
        return EMPTY_STACK;

    *d = p->Stack[p->top - 1];
    return O_K;
}
void cleanStack(pile *p)
{
    p->top = 0;
}
