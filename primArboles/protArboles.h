#ifndef PROTARBOLES_H_INCLUDED
#define PROTARBOLES_H_INCLUDED
#define CON_SIN_MSJ 1
#define O_K 0
#define CLAV_DUPL 1
#define SIN_MEM 2
#define FILE_INFO "persons"
#define compear compear
#define heigth heigthTree

typedef struct
{
    int day,
        month,
        year;
}date;

typedef struct
{
    long dni;
    char surName[50],
         firstName[50],
         sex;
    date fec;
    float qualification;
}person,tInfo;

typedef struct sNode
{
    struct sNode *left;
    tInfo info;
    struct sNode *rigth;
}tNode, *tree;

//manejo arbol
void createTree(tree *p);
int isFullTree(tree *p);
int ifEmptyTree(tree *p);
void postOrder(tree *p);
void preOrder(tree *p);
void inOrder(tree *p);
int tidyUp(tree *p,const tInfo *d,int (*compear)(const tInfo*, const tInfo*));
void removeInPost(tree *p);
void removeInPreAndShow(tree *p);
int heigthTree(tree *p);
int ifTreeAvl(tree *p,int (*heigth)(tree*));
int sheetsCounting(tree *p);
int balancedTree(tree *p,int h, int c);
int nodesCounting(tree *p);
void show(tInfo *d);
int compear(const tInfo *d1, const tInfo *d2);
//manejo archivo
void createFilePerson();
int openFile(FILE **fp,char *modo,char *archivo,int CON_SIN);


#endif // PROTARBOLES_H_INCLUDED
