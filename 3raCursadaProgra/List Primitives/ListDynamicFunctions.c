#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "ListDynamicPrototipes.h"

void createList(List *l)
{
    (*l) = NULL;
}

int fullList(List *l)
{
    void *aux = malloc(sizeof(node));
    free(aux);
    return aux == NULL;
}

int emptyList(List *l)
{
    return (*l) == NULL;
}

void clearList(List *l)
{
    node *aux;

    while((*l))
    {
        aux = (*l);
        (*l) = aux->next;
        free(aux);
    }
}

int putTheTopOfTheList(List *l, const info *d)
{
    node *newNode = (node*) malloc(sizeof(node));

    if(!newNode)
        return WITHOUT_MEMORY;

    newNode->data = *d;
    newNode->next = (*l);
    (*l) = newNode;

    return O_K;
}

int putAnEndTheList(List *l, const info *d)
{
    node *newNode = (node*) malloc(sizeof(node));

    if(!newNode)
        return WITHOUT_MEMORY;

    while((*l))
        l = &(*l)->next;

    newNode->data = *d;
    newNode->next = NULL;//No le pongo (*l) ya que estaria haciendo un direccionamiento solo para poner NULL.
    (*l) = newNode;
    return O_K;
}

int putInOrder(List *l, const info *d, int (*compear)(const info*, const info*), void (*accumulate)(info*, const info*))
{
    node *newNode;

    while((*l) && compear(&(*l)->data,d) < 0)
        l = &(*l)->next;

    if((*l) && compear(&(*l)->data,d) == 0)
    {
        accumulate(&(*l)->data, d);
        return DUPLICATE_DATA;
    }

    newNode = (node*) malloc(sizeof(node));

    if(!newNode)
        return WITHOUT_MEMORY;
    newNode->data = *d;
    newNode->next = (*l);
    (*l) = newNode;
    return O_K;
}
int compearBuyDni(const info *d1, const info *d2)
{
    return (int)(d1->dni - d2->dni);
}
int compearBuySurNameAndFirstName(const info *d1, const info *d2)
{
    int cmp = strcmp(d1->surName,d2->surName);

    if(!cmp)
        return strcmp(d1->name,d2->name);
    return cmp;
}

void accmulateAverage( info *d1, const info *d2)
{
    d1->average += d2->average;
}

int removeFromList(List *l, const info *d, int (*compear)(const info *, const info *))
{
    node *aux;

    if(!(*l))
        return EMPTY_LIST;

    while((*l) && compear(&(*l)->data, d) != 0)
        l = &(*l)->next;
    if(!(*l))
        return NOT_FOUND;
    aux = (*l);
    (*l) = aux->next;
    free(aux);
    return O_K;
}

int searchNode(List *l, info *d, int (*compear)(const info *, const info *))
{
    if(!(*l))
        return EMPTY_LIST;

    while((*l) && compear(&(*l)->data, d) != 0)
        l = &(*l)->next;
    if(!(*l))
        return NOT_FOUND;
    *d = (*l)->data;
    return O_K;
}

void bubbleSortList(List *l)
{
    List *q = NULL;
    node *aux;
    int change = 1;

    if((*l))
    {
        while(change)
        {
            q = l;
            change = 0;

            while((*q)->next)
            {
                if(compear(&(*q)->data, &(*q)->next->data) > 0)
                {
                    change = 1;
                    aux = (*q);
                    (*q) = aux->next;
                    aux->next = (*q)->next;
                    (*q)->next = aux;
                }
                q = &(*q)->next;
            }
        }
    }
}

void putListInFile(List *l,FILE **fp)
{
    fseek(*fp,0L,SEEK_SET);

    while((*l))
    {
        fwrite(&(*l)->data,1,sizeof(info),*fp);
        l = &(*l)->next;
    }
    fseek(*fp,0L,SEEK_SET);
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
