#include "listas.h"

void crearLista(t_lista* p)
{
    *p = NULL;
}

int listaLlena(const t_lista* p)
{
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}

int listaVacia(const t_lista* p)
{
    return *p == NULL;
}

int insertarAlPrincipio(t_lista* p, const t_info* d)
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->datos = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int insertarAlFinal(t_lista* p, const t_info* d)
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    while(*p)
    {
        p = &(*p)->sig; //p no es la lista, *p es la lista, p es un puntero a t_lista, es decir doble puntero a t_nodo
    }
    nue->datos = *d;
    nue->sig = NULL;
    *p = nue;
    return 0;
}

int insertarEnOrdenPorDni(t_lista* p, t_info* d, t_cmp funcComp)
{
    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    while(!listaLlena(p) && *p && funcComp(&((*p)->datos), d) < 0) //pase dos punteros a t_info
    {
        p = &(*p)->sig;
    }
    nue->datos = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int insertarEnOrdenPorDni2(t_lista* p, t_info* d, t_cmp funcComp)
{
    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    while(!listaLlena(p) && *p && funcComp(&((*p)->datos).dni, &(d->dni)) < 0)//pase dos punteros a int
    {
        p = &(*p)->sig;
    }
    nue->datos = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int insertarEnOrdenPorApyn(t_lista* p, t_info* d, t_cmp funcComp)
{
    t_nodo* nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    while(!listaLlena(p) && *p && funcComp(((*p)->datos).apyn, d->apyn) < 0)//pase dos punteros a char
    {
        p = &(*p)->sig;
    }
    nue->datos = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int comparaDNI(const void* d1, const void* d2)
{
    if(((const t_info*)d1)->dni > ((const t_info*)d2)->dni)
        {printf("retorna 1");
        return 1;}
    else
        if(((const t_info*)d1)->dni < ((const t_info*)d2)->dni)
            {printf("retorna -1");
            return -1;}
        else
            {printf("retorna 0");
            return 0;}
}

int comparaDNI2(const void* dni1, const void* dni2)
{
    if((const int*)dni1 > (const int*)dni2)
        {printf("retorna 1");
        return 1;}
    else
        if((const int*)dni1 < (const int*)dni2)
            {printf("retorna -1");
            return -1;}
        else
            {printf("retorna 0");
            return 0;}
}

int comparaApyn(const void* a1, const void* a2)
{
    int res = strcmpi((const char*)a1, (const char*) a2);
    if(res > 0)
       return 1;
    else
        if(res < 0)
            return -1;
        else
            return 0;
}

int contarNodos(t_lista* p)
{
    int cantNodos = 0;
    while(*p)
    {
        cantNodos++;
        p = &(*p)->sig;
    }
    return cantNodos;
}

void imprimirLista(t_lista* p)
{
    t_info auxDeLectura;
    printf("\nLa lista es: ");
    while(*p)
    {
        auxDeLectura = (*p)->datos;
        printf("\n%-30s\t%d\t%c\t%.2f",
               auxDeLectura.apyn,
               auxDeLectura.dni,
               auxDeLectura.sexo,
               auxDeLectura.sueldo);
        p = &(*p)->sig;
    }
}
