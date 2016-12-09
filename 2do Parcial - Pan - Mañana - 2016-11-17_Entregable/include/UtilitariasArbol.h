#ifndef UTILITARIASARBOL_H
#define UTILITARIASARBOL_H

#include <stdio.h>
#include <Arbol.h>


void generar_arbol_int(t_arbol* pa);
void generar_arbol_balanceado_int(t_arbol* pa);
void generar_arbol_no_balanceado_int(t_arbol* pa);
void cargar_arbol_indice_patentes(t_arbol* pa, FILE* arch);


#endif // UTILITARIASARBOL_H
