#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char apyn[30];
    int dni;
    char sexo;
    float sueldo;
}t_info;

typedef struct s_nodo
{
    t_info datos;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp) (const void* d1, const void* d2);
/*
mostrar
grabar
eliminar
recorrer lista y grabar en archivo
ordenar lista
insertar en orden
reemplazar posicion
*/

void crearLista(t_lista* p);
int listaLlena(const t_lista* p);
int listaVacia(const t_lista* p);
int insertarAlPrincipio(t_lista* p, const t_info* d);
int insertarAlFinal(t_lista* p, const t_info* d);
int insertarEnOrdenPorDni(t_lista* p, t_info* d, t_cmp funcComp);
int insertarEnOrdenPorDni2(t_lista* p, t_info* d, t_cmp funcComp);
int insertarEnOrdenPorApyn(t_lista* p, t_info* d, t_cmp funcComp);
int comparaDNI(const void* d1, const void* d2);
int comparaDNI2(const void* dni1, const void* dni2);
int comparaApyn(const void* a1, const void* a2);
int contarNodos(t_lista* p);




void imprimirLista(t_lista* p);

#endif // LISTAS_H_INCLUDED
