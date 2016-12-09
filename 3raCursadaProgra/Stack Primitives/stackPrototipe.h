#ifndef STACKPROTOTIPE_H_INCLUDED
#define STACKPROTOTIPE_H_INCLUDED

#include "filePrototipe.h"
#define SIZE_STACK 21
#define EMPTY_STACK 0
#define FULL_STACK 1
#define O_K 2

typedef struct
{
    info Stack[SIZE_STACK];
    int top;
}pile;

void createStack(pile *p);
int emptyStack(pile *p);
int fullStack(pile *p);
int putOnStack(pile *p,info *d);
int takeOfStack(pile *p, info *d);
int showTop(pile *p, info *d);
void cleanStack(pile *p);
#endif // STACKPROTOTIPE_H_INCLUDED
