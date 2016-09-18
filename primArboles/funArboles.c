#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "protArboles.h"

void createTree(tree *p)
{
    *p = NULL;
}

int isFullTree(tree *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);
    return aux == NULL;
}

int ifEmptyTree(tree *p)
{
    return *p == NULL;
}

void postOrder(tree *p)
{
    if(*p)
    {
        postOrder(&(*p)->left);
        postOrder(&(*p)->rigth);
        show(&(*p)->info);
    }
}

void preOrder(tree *p)
{
    if(*p)
    {
        show(&(*p)->info);
        preOrder(&(*p)->left);
        preOrder(&(*p)->rigth);
    }
}

void inOrder(tree *p)
{
    if(*p)
    {
        inOrder(&(*p)->left);
        show(&(*p)->info);
        inOrder(&(*p)->rigth);
    }
}

int tidyUp(tree *p,const tInfo *d,int (*compear)(const tInfo*, const tInfo*))
{
    tNode *nue;
    int cmp;

    while(*p)
    {
        cmp = compear(d,&(*p)->info); //postOrden

        if(!cmp)
            return CLAV_DUPL;
        if(cmp < 0)
            p = &(*p)->left;
        else
            p = & (*p)->rigth;
    }
    nue = (tNode*) malloc(sizeof(tNode));
    if(nue == NULL)
        return SIN_MEM;
    nue->info = *d;
    nue->left = NULL;
    nue->rigth = NULL;
    *p = nue;
    return O_K;
}

int compear(const tInfo *d1, const tInfo *d2)
{
    return d1->dni - d2->dni;
}

void removeInPost(tree *p) //preguntar por como remover nodos....
{
    if(*p)
    {
        removeInPost(&(*p)->left);
        removeInPost(&(*p)->rigth);
        free(*p);
    }
}

void removeInPreAndShow(tree *p) //preguntar por como remover nodos....
{
    tNode *left,
          *rigth;
    if(*p)
    {
        left = (*p)->left;
        rigth = (*p)->rigth;
        show(&(*p)->info);
        free(*p);
        removeInPreAndShow(&left);
        removeInPreAndShow(&rigth);
    }
}

int heigthTree(tree *p)
{
    int hL = 0,
        hR = 0;
    if(*p)
    {
        hL += heigthTree(&(*p)->left);
        hR += heigthTree(&(*p)->rigth);

        return hL > hR ? hL + 1 : hR + 1;
    }
    return 0;
}

int ifTreeAvl(tree *p,int (*heigth)(tree*))
{
    if(*p)
    {
        if(abs(heigth(&(*p)->left) - heigth(&(*p)->rigth)) > 1)
            return 0;
        return (ifTreeAvl(&(*p)->left,heigth) && ifTreeAvl(&(*p)->rigth,heigth));
    }
    return 1;
}
int sheetsCounting(tree *p)
{
    if(*p)
    {
        if((*p)->left == (*p)->rigth)
            return 1;
        return sheetsCounting(&(*p)->left) + sheetsCounting(&(*p)->rigth);
    }
    return 0;
}

int balancedTree(tree *p,int h, int c)
{
    if(*p && c != h-1)
    {
        c ++;
        return balancedTree(&(*p)->left,h,c) && balancedTree(&(*p)->rigth,h,c);
    }
    return *p && c != h-1 ? 1 : 0;
}

int nodesCounting(tree *p)
{
    int c;
    if(*p)
    {
        return c = nodesCounting(&(*p)->left) + nodesCounting(&(*p)->rigth) + 1;
    }
    return 0;
}

void show(tInfo *d)
{
    if(d)
    {
        printf("%08ld   %-*s  %-*s  %c    %2d/%2d/%2d     %.2f \n",
                d->dni,
                sizeof(d->surName)-1, d->surName,
                sizeof(d->firstName)-1,d->firstName,
                d->sex,
                d->fec.day,
                d->fec.month,
                d->fec.year,
                d->qualification);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO    FECHA     CALIFICACION\n",sizeof(d->dni),"D.N.I",sizeof(d->surName),"APELLIDO(S)",sizeof(d->firstName),"NOMBRE(S)");
    }
}


void createFilePerson()
{
    FILE *file = fopen(FILE_INFO,"wb");
    tInfo vec[] = {{87143658L, "Allende","Miguel",'M',{12,03,1996},7.5},
                    {46868278L,"Franzoi","Maximiliano",'M',{22,01,1990},4.36},
                    {47896425L,"Merlo","Micaela",'F',{24,02,1990},8.55},
                    {16887451L,"Pagnutti","Jose",'M',{26,04,1992},8.98},
                    {87952123L,"Recalde","Camila",'F',{29,07,1993},5.56},
                    {34562501L,"Solla","Tamara",'F',{13,03,1993},7.29},
                    {16549654L,"Sosa","Federico",'M',{5,03,1993},4.89},
                    {22366985L,"Vizzoni","Daniela",'F',{9,07,1997},6.56}};
    if(file)
        fwrite(vec,1,sizeof(vec),file);

    fclose(file);
}

int openFile(FILE **fp,char *modo,char *archivo,int CON_SIN)
{
    *fp = fopen(archivo,modo);//devuelve una direccion de memoria

    if(!*fp)
    {
        if(CON_SIN_MSJ == CON_SIN)
            fprintf(stderr,"Error-abriendo\"%s\" en modo \"%s\"\n",archivo,modo);

        return 0;
    }
    return 1;
}
