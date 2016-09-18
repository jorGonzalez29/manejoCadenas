#include <stdio.h>
#include <string.h>
#include "protListas.h"
#include "protArch.h"

void createList(List *p)
{
    (*p) = NULL;
}
int isListEmpty(List *p)
{
    return (*p) == NULL;
}

int isListFull(List *p)
{
    void *aux = malloc(sizeof(sNode));
    free(aux);

    return aux == NULL;
}

int putInList(List *p, tInfo *d, int (*compear)(const tInfo*,const tInfo*), void (*accumulator)(const tInfo*,const tInfo*))
{
    sNode *newNode;

    while(*p && compear(d, &(*p)->info) < 0)
        p = &(*p)->next;
    if(*p && compear(d, &(*p)->info) == 0)
    {
        accumulator(&(*p)->info, d);
        return CLAV_DUP;
    }
    newNode = (sNode*) malloc(sizeof(sNode));
    if(newNode == NULL)
        return SIN_MEM;

    newNode->info = *d;
    newNode->next = *p;
    *p = newNode;
    return O_K;
}
void deleteNodesDuplicate(List *p, int (*compear)(const tInfo*,const tInfo*))
{
    FILE *fp = fopen(FILEERRORS, "w+b");
    sNode *aux;
    if(fp && *p)
    {
        while(*p && (*p)->next)
        {
                if(compear((*p)->next->info, (*p)->info) == 0)
                {
                    showInfoComercial(&(*p)->info);
                    fwrite(&(*p)->info,1,sizeof(sNode),fp);
                    fseek(fp,0,SEEK_CUR);
                    aux = (*p)->next;
                    (*p)->next = aux->next;
                    free(aux);
                }
            p = &(*p)->next;
        }
        fclose(fp);
    }
    else
        fprintf(stderr,"No se pudo abrir archivo con nombre %s en modo w+b",FILEERRORS);
}
void accumulatorInfo(tInfo *d1, tInfo *d2)
{
    d1->cant += d2->cant;
    if(d1->prec < d2->prec)
        d1->prec = d2->prec;
    if(d1->cost < d2->cost)
        d1->cost = d2->cost;
}

int compearByCodAndDescription(const tInfo *d1, const tInfo *d2)
{
    int cmp = strcmp(d1->codi, d2->codi);

    if(cmp)
        return cmp;

    return strcmp(d1->desc, d2->desc);
}

void emptyList(List *p)
{
    sNode aux;
    while(*p)
    {
        aux = *p;
        p = &aux->next;
        free(aux);
    }
}
