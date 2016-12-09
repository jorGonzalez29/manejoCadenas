#ifndef STACKDINAMICPROTOTIPE_H_INCLUDED
#define STACKDINAMICPROTOTIPE_H_INCLUDED

#include "filePrototipe.h"
#define EMPTY_STACK 0
#define FULL_STACK 1
#define O_K 2

typedef struct node
{
    info data;
    struct node *next;
}node, *pile;

void createStack(pile *p);
int emptyStack(pile *p);
int fullStack(pile *p);
int putOnStack(pile *p,info *d);
int takeOfStack(pile *p, info *d);
int showTop(pile *p, info *d);
void cleanStack(pile *p);
#endif // STACKDINAMICPROTOTIPE_H_INCLUDED
