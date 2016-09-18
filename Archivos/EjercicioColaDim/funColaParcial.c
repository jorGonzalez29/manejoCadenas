#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protColaParcial.h"
//primitivas cola dim
void createQueue(tQueue *p)
{
    p->first = NULL;
    p->last = NULL;
}

int queueEmpty(tQueue *p)
{
    return p->last == NULL;
}

int queueFull(tQueue *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);
    return aux == NULL;
}

int pushingInQueue(tQueue *p, tInfo *d)
{
    tNode *newNode = (tNode*) malloc(sizeof(tNode));
    if(newNode == NULL)
        return 0;
    newNode->info = *d;
    newNode->next = NULL;
    if(p->last == NULL)
        p->first = newNode;
    else
        p->last->next = newNode;

    p->last = newNode;

    return 1;
}

int takeOfQueue(tQueue *p, tInfo *d)
{
    tNode *aux;

    if(p->first == NULL)
        return 0;
    aux = p->first;
    *d = aux->info;
    p->first = aux->next;
    if(p->first == NULL)
        p->last = NULL;
    free(aux);
    return 1;
}

int showFirstInQueue(tQueue *p, tInfo *d)
{
    if(p->first == NULL)
        return 0;
    *d = p->first->info;
    return 1;
}

void emptyQueue(tQueue *p)
{
    tNode *aux;

    while(p->first)
    {
        aux = p->first;
        p->first = aux->next;
        free(aux);
    }
    p->last = NULL;
}
//manejo archivos

int openFile(FILE **fp,char *nameFile,char *mode, int CON_SIN)
{
    *fp = fopen(nameFile,mode);

    if(!(*fp))
    {
        if(CON_SIN)
            fprintf(stderr,"ERROR - Imposible abir archivo %s en modo %s ",nameFile,mode);
        return 0;
    }
    return 1;
}

void showFile(FILE **fp)
{
    long posActual = ftell(*fp);
    tInfo reg;
    rewind(*fp);

    showData(NULL);
    fread(&reg,1,sizeof(tInfo),*fp);
    while(!feof(*fp))
    {
        showData(&reg);
        fread(&reg,1,sizeof(tInfo),*fp);
    }
    fseek(*fp,posActual,SEEK_SET);
}

void showData(tInfo *d)
{
    if(d)
        printf("%ld\n",d->id);
    else
        printf("IDENTIFICACION\n");
}
