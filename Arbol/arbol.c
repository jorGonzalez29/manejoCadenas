#include "arbol.h"

void crearArbol(t_arbol *p)
{
    *p = NULL;
}

int menu(void)
{
    int op = 0;
    do
    {
        printf("\n\n\"MENU DE OPCIONES - ARBOLES BINARIOS\"\n");
        printf("\n\t  1 - Cargar Nodo al Arbol, ITERATIVA."
               "\n\t  2 - Cargar Nodo al Arbol, RECURSIVA."
               "\n\t  3 - Mostrar informacion -->"
               "\n\t  4 - Conocer la altura del Arbol."
               "\n\t  5 - Muestra NODOS - HOJA."
               "\n\t  6 - Muestra NODOS - NO HOJA."
               "\n\t  7 - NODOS con solo HIJOS POR IZQUIEDA."
               "\n\t  8 - NODOS con HIJOS POR IZQUIERDA."
               "\n\t  9 - Es AVL ?"
               "\n\t 10 - Es Balanceado ?"
               "\n\t 11 - Eliminar todos los nodos del Arbol."
               "\n\t 12 - Podar hasta altura determinada. "
               "\n\t 13 - Grabar Arbol en archivo en PRE/IN/POST ORDEN."
               "\n\n\t  0 - Salir."
               "\n\nEleccion: ");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
    }while(op < 0 || op > 13);
    return op;
}

int subMenu(void)
{
    int op;
    do
    {
        printf("\"MOSTRAR INFORMACION\""
               "\n\t 1 - PREORDEN"
               "\n\t 2 - INORDEN"
               "\n\t 3 - POSTORDEN"
               "\n\nEleccion: ");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
    }while(op < 1 || op > 3);
    return op;
}

int cargarInfo(t_info* d)
{
    printf("\nCARGA DE DATOS\n\nLegajo: ");
    fflush(stdin);
    scanf("%[^\n]", d->legajo);

    printf("\nApellido y nombre: ");
    fflush(stdin);
    scanf("%[^\n]", d->apyn);

    printf("\nCargo: ");
    fflush(stdin);
    scanf("%[^\n]", d->cargo);

    printf("\nFecha de alta: ");
    printf("\nDia: ");
    scanf("%d", &(d->fecAlta.dd));
    printf("\nMes: ");
    scanf("%d", &(d->fecAlta.mm));
    printf("\nAnio: ");
    scanf("%d", &(d->fecAlta.aaaa));

    printf("\nFecha de baja: ");
    printf("\nDia: ");
    scanf("%d", &(d->fecBaja.dd));
    printf("\nMes: ");
    scanf("%d", &(d->fecBaja.mm));
    printf("\nAnio: ");
    scanf("%d", &(d->fecBaja.aaaa));

    return 1;
}

int cargarArbolIterativa(t_arbol* p, const t_info* d, int(*comparaCad)(const char*, const char*))
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(nue == NULL)
    {
        printf("SIN_MEMORIA. \n");
        return 0;
    }
    nue->dato = *d;
    nue->izq = NULL;
    nue->der = NULL;
    while(*p)
    {
        int res = comparaCad((*p)->dato.legajo, d->legajo);
        if(res < 0)
            p = &(*p)->der;
        else
            if(res > 0)
                p = &(*p)->izq;
            else
            {
                printf("Duplicados. No se inserta nodo.\n");
                return 0;
            }
    }
    *p = nue;
    return 1;
}

int comparaCadenas(const char* cad1, const char* cad2)
{
    if(strcmpi(cad1, cad2) > 0)
        return 1;
    else
        if(strcmpi(cad1, cad2) < 0)
            return -1;
    return 0;
}

int cargarArbolRecursiva(t_arbol* p, const t_info* d, int (*comparaCad)(const char*, const char*))
{
    if(*p == NULL)
    {
        t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
        if(nue == NULL)
        {
            printf("\nSIN_MEMORIA.\n");
            return(0);
        }
        else
        {
            nue->dato = *d;
            nue->izq = NULL;
            nue->der = NULL;
            *p = nue;
            return 1;
        }
    }
    else
    {
        int res = comparaCad((*p)->dato.legajo, d->legajo);
        if(res < 0)
        {
            printf("\n\n\tPaso por derecha. ");
            cargarArbolRecursiva(&(*p)->der, d, comparaCad);

        }
        else
            if(res > 0)
            {
                printf("\n\n\tPaso por izquierda. ");
                cargarArbolRecursiva(&(*p)->izq, d, comparaCad);

            }
            else
            {
                printf("Duplicados. No se inserta nodo.\n");
                return 0;
            }
    }
    return 0;
}

void recorrerInOrden(const t_arbol* p)
{
    if(*p != NULL)
    {
        recorrerInOrden(&(*p)->izq);
        printf("\t%s", (*p)->dato.legajo);
        recorrerInOrden(&(*p)->der);
    }
}

void recorrerPostOrden(const t_arbol* p)
{
    if(*p != NULL)
    {
        recorrerPostOrden(&(*p)->izq);
        recorrerPostOrden(&(*p)->der);
        printf("\t%s", (*p)->dato.legajo);
    }
}

void recorrerPreOrden(const t_arbol* p)
{
    if(*p != NULL)
    {
        printf("\t%s", (*p)->dato.legajo);
        recorrerPreOrden(&(*p)->izq);
        recorrerPreOrden(&(*p)->der);
    }
}

int esAVL(const t_arbol* p)
{
    if(*p)
    {
        if(ABSOLUTO(altura(&(*p)->izq) - altura(&(*p)->der)) > 1)
            return 0;
        return esAVL(&(*p)->izq) && esAVL(&(*p)->der);
    }
    return 1;
}

int altura(const t_arbol* p)
{
    if(*p == NULL)
        return 0;
    return 1 + (maximo(altura(&(*p)->izq), altura(&(*p)->der)));
}

int maximo(int a, int b)
{
    return a >= b ? a : b;
}

int balancedTree(const t_arbol* p,int h, int c)
{
    if(*p && c != h-1)
    {
        c ++;
        return balancedTree(&(*p)->izq,h,c) && balancedTree(&(*p)->der,h,c);
    }
    return *p && c != h-1 ? 1 : 0;
}

int esCompleto(const t_arbol* p)
{
    int h = altura(p);
    return verSiEsCompleto(p, h);
}

int verSiEsCompleto(const t_arbol* p, int h)
{
    if(*p)
    {
        return verSiEsCompleto(&(*p)->izq, h - 1) && verSiEsCompleto(&(*p)->der, h - 1);
    }
    return h == 0;
}

int esCompleto2(const t_arbol* p)
{
    if(*p)
    {
        if(altura(p) == 1)
            return 1;
        return esCompleto2(&(*p)->izq) && esCompleto2(&(*p)->der);
    }
    return 0;
}

int contarNodos(const t_arbol* p)
{
    if(*p)
    {
        return contarNodos(&(*p)->izq) + contarNodos(&(*p)->der) + 1;
    }
    return 0;
}

int contarNodosHastaNivel(const t_arbol* p, int nivel)
{
    if(*p)
    {
        if(nivel == 1)
            return 1;
        return contarNodosHastaNivel(&(*p)->izq, nivel - 1) +
               contarNodosHastaNivel(&(*p)->der, nivel - 1) + 1;
    }
    return 0;
}

void eliminarArbol(t_arbol* p)
{
    if(*p)
    {
        eliminarArbol(&(*p)->izq);
        eliminarArbol(&(*p)->der);
        free(*p);
        *p = NULL;
    }
}

int eliminarYContar(t_arbol* p)
{
    if(*p)
    {
        int cant = eliminarYContar(&(*p)->izq) + eliminarYContar(&(*p)->der);
        free(*p);
        *p = NULL;
        return cant + 1;
    }
    return 0;
}

int eliminarContarYMostrar(t_arbol* p, void (*mostrar)(const t_info*, FILE*), FILE* fp, int EN_PRE_POS)
{
    if(*p)
    {
        int cant;
        if(EN_PRE_POS == PREORDEN)
            mostrar(&(*p)->dato, fp);

        cant = eliminarContarYMostrar(&(*p)->izq, mostrar, fp, EN_PRE_POS);
        if(EN_PRE_POS == ENORDEN)
            mostrar(&(*p)->dato, fp);

        cant = eliminarContarYMostrar(&(*p)->der, mostrar, fp, EN_PRE_POS);
        if(EN_PRE_POS == POSTORDEN)
            mostrar(&(*p)->dato, fp);

        free(*p);
        *p = NULL;
        return cant + 1;
    }
    return 0;
}

void mostrarInfo(const t_info* d, FILE* fp)
{
    if(d)
    {
        fprintf(fp, "\n%-*s %-*s %-*s %02d/%02d/%04d %02d/%02d/%04d",
                    sizeof(d->legajo) - 1, d->legajo,
                    sizeof(d->apyn) - 1, d->apyn,
                    sizeof(d->cargo) - 1, d->cargo,
                    d->fecAlta.dd, d->fecAlta.mm, d->fecAlta.aaaa,
                    d->fecBaja.dd, d->fecBaja.mm, d->fecBaja.aaaa);
    }
}

void podarHastaNivel(t_arbol* p, int nivel)
{
    if(*p)
    {
        if(nivel == 0)
            eliminarArbol(p);
        else
        {
            podarHastaNivel(&(*p)->izq, nivel - 1);
            podarHastaNivel(&(*p)->der, nivel - 1);
        }
    }
}

void mostrarNodosHoja(const t_arbol* p)
{
    if(*p)
    {
        if((*p)->izq == NULL && (*p)->der == NULL)
            mostrarInfo(&(*p)->dato, stdout);
        mostrarNodosHoja(&(*p)->izq);
        mostrarNodosHoja(&(*p)->der);
    }
}

void mostrarNodosNoHoja(const t_arbol* p)
{
    if(*p)
    {
        if((*p)->izq != NULL || (*p)->der != NULL)
            mostrarInfo(&(*p)->dato, stdout);
        mostrarNodosNoHoja(&(*p)->izq);
        mostrarNodosNoHoja(&(*p)->der);
    }
}

void mostrarNodosConSoloHijosPorIzquierda(const t_arbol* p)
{
    if(*p)
    {
        if((*p)->izq != NULL && (*p)->der == NULL)
            mostrarInfo(&(*p)->dato, stdout);
        mostrarNodosConSoloHijosPorIzquierda(&(*p)->izq);
        mostrarNodosConSoloHijosPorIzquierda(&(*p)->der);
    }
}

void mostrarNodosConHijosPorIzquierda(const t_arbol* p)
{
    if(*p)
    {
        if((*p)->izq != NULL)
            mostrarInfo(&(*p)->dato, stdout);
        mostrarNodosConHijosPorIzquierda(&(*p)->izq);
        mostrarNodosConHijosPorIzquierda(&(*p)->der);
    }
}

int grabarArbolEnArchivo(const t_arbol* p, int(*grabarNodoEnArchivo)(const t_info* , FILE*), FILE* fp, int EN_PRE_POS)
{
    if(*p)
    {
        if(EN_PRE_POS == PREORDEN)
            grabarNodoEnArchivo(&(*p)->dato, fp);

        grabarArbolEnArchivo(&(*p)->izq, grabarNodoEnArchivo, fp, EN_PRE_POS);
        if(EN_PRE_POS == ENORDEN)
            grabarNodoEnArchivo(&(*p)->dato, fp);

        grabarArbolEnArchivo(&(*p)->der, grabarNodoEnArchivo, fp, EN_PRE_POS);
        if(EN_PRE_POS == POSTORDEN)
            grabarNodoEnArchivo(&(*p)->dato, fp);
        return 1;
    }
    return 0;
}

int guardarNodoEnArchivo(const t_info* d, FILE* fp)
{
    if(d)
    {
        fprintf(fp, "%-*s %-*s %-*s %02d/%02d/%04d %02d/%02d/%04d\n",
                sizeof(d->legajo), d->legajo,
                sizeof(d->apyn), d->apyn,
                sizeof(d->cargo), d->cargo,
                d->fecAlta.dd, d->fecAlta.mm,d->fecAlta.aaaa,
                d->fecBaja.dd, d->fecBaja.mm, d->fecBaja.aaaa);
        return 1;
    }
    return 0;
}

int abrirArchivo(FILE** fp, char* nombArchivo, char* modo, int msj)
{
    *fp = fopen(nombArchivo, modo);
    if(!*fp)
    {
        if(msj)
            printf("\nError al abrir el archivo. ");
        return 0;
    }
    return 1;
}
