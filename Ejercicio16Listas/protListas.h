#ifndef PROTLISTAS_H_INCLUDED
#define PROTLISTAS_H_INCLUDED
#define compear compearByCodAndDescription
#define accumulator accumulatorInfo
#define CLAV_DUP 1
#define SIN_MEM 2
#define O_K 0
typedef struct
{
    int day,
        month,
        year;
}date;

typedef struct
{
    char codi[10],
         desc[50],
         prov[26];
    fecha fcom,
          fvta;
    float prec,
          cost;
    int cant;
}producto,tInfo;

typedef struct sNode
{
    tInfo info;
    struct sNode *next;
}sNode, *List;

void createList(List *p);
int isListEmpty(List *p);
int isListFull(List *p);
int putInList(List *p, tInfo *d, int (*compear)(const tInfo*,const tInfo*), void (*accumulator)(const tInfo*,const tInfo*));
void deleteNodesDuplicate(List *p, int (*compear)(const tInfo*,const tInfo*));
void accumulatorInfo(tInfo *d1, tInfo *d2);
int compearByCodAndDescription(const tInfo *d1, const tInfo *d2);
void emptyList(List *p);

#endif // PROTLISTAS_H_INCLUDED
