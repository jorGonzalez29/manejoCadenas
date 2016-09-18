#ifndef PROTARBOLES_H_INCLUDED
#define PROTARBOLES_H_INCLUDED
#define nameFile "archivoInfo"
#define nameFileUpdate "archivoActualizado"
#define MSJ "Ingrese_una_opcion \n A-Agregar_info \n B-Buscar_en_arbol \n C-Mostrar_en_orden \n D-Mostrar_en_posorden \n E-Mostrar_en_preorden \n F-Cantidad_de_hojas \n G-Cantidad_de_nodos \n H-Si_es_completo \n I-Si_es_AVL \n J-Si_es_balanceado \n L-Cerrar \n"
#define OPTION "ABCDEFGHIJL"
#define compear compearByDni
#define CLAV_DUP 1
#define SIN_MEM 2
#define O_K 0
#define CON_SIN_MSJ 1
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
    float salary;
}employee, tInfo;

typedef struct sNode
{
    struct sNode *rigth;
    long dni;
    long reg;
    struct sNode *left;
}tNode,*Arbol;
//Funciones archivo
void createFile();
int openFile(FILE **fp, char *mod, char *File, int CON_MSJ);
void showFile(FILE **fp);
void showInfo(tInfo *d);
void putAtTheEnd(FILE **fp,tInfo *d);
char menuOption(char *msj, char *option);
void newInfo(tInfo *d);
//Funciones arbol
void createTree(Arbol *p);
int isTreeEmpty(Arbol *p);
int isTreeFull(Arbol *p);
int putInTree(Arbol *p,tInfo *d,int *cont, int (*compear)(long*,long*));
int compearByDni(long *d1, long *d2);
int searchInTree(Arbol *p, tInfo *d, int(*compear)(long*,long*));
void order(Arbol *p,FILE **fp);
void preOrder(Arbol *p,FILE **fp);
void posOrder(Arbol *p,FILE **fp);
void showInfoByKey(FILE **fp, int key);
void emptyTree(Arbol *p);//en posOrden
int countingNodes(Arbol *p);
int sheetsCounting(Arbol *p);
int heigthTree(Arbol *p);
int completeTree(Arbol *p);
int balancedTree(Arbol *p);
int isAVL(Arbol *p);
#endif // PROTARBOLES_H_INCLUDED
