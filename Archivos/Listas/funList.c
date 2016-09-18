#include <stdio.h>
#include <string.h>
#include "protList.h"

void createList(List *p)
{
    (*p) = NULL;
}

int fullList(List *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);

    return aux == NULL;
}

int ifListEmpty(List *p)
{
    return *p == NULL;
}

int putAtTheBeginning(const List *p, tInfo *d)
{
    tNode *nue = (tNode*)malloc(sizeof(tNode));

    if(nue == NULL)
        return 0;
    nue->info = *d;
    nue->next = *p;
    *p = nue;

    return 1;
}

int putAtTheEnd(const List *p, tInfo *d)
{
    while(*p)// preguntar (*p)->next no me lo toma
        p = &p->next;

    *p = (tNode*)malloc(sizeof(tNode));
    if(*p == NULL)
        return 0;
    (*p)->info = *d;
    (*p)->next = NULL;
    return 1;
}

int tidy(List *p,tInfo *d,int (*compear)(const tInfo*,const tInfo*),void(*upDate)(tInfo*,tInfo*))
{

    while(*p && compear(&(*p)->info,d) < 0) //ordena de menor a mayor
        p = &(*p)->next;

    if(*p && compear(&(*p)->info,d) == 0)
    {
        upDate(&(*p)->info,d);
        return DUPLICATE_KEY;
    }
    tNode newNode = (*tNode) malloc(sizeof(tNode));
    if(newNode)
    {
        newNode->info = *d;
        newNode->next = *p;
        *p = newNode;
        return O_K;
    }

    return NO_MEMORY;
}

int compearByNameSurnameSexDateDni(const tInfo *d1,const tInfo *d2)
{
//    int cmp = strcmp((d1->firstName,d2->firstName);
//
//    if(cmp)
//        return cmp;
//    cmp = strcmp((d1->surName,d2->surName);
//
//    if(cmp)
//        return cmp;
//    cmp = d1->sex - d2->sex;
//     if(cmp)
//        return cmp;
//     cmp = COMPEARDATE(d1->fec->year,d2->fec->year,d1->fec->month,d2->fec->month,d1->fec->day,d2->fec->day);
//     if(cmp)
//        return cmp;
     return d1->dni - d2->dni;
}

void upDateSalary(tInfo *d1,tInfo *d2)
{
    d1->salary + = d2->salary;
}

void sortByNameSurnameSexDateDni(Lista *p,int (*compear)(const tInfo*,const tInfo*))
{
    int flag = 1;
    List *q;
    tNode *aux;

    if(*p)
    {
        while(flag)
        {
            flag = 0;
            q = p;
            while((*q)->next)
            {
                if(compear(&aux->info,&aux->next->info) > 0) //de menor a mayor
                {
                    flag = 1;
                    aux = *q;
                    *q = aux->next;
                    aux->next = (*q)->next;
                    (*q)->next = aux;
                }
                q = &(*q)->next;
            }
        }
    }
}
