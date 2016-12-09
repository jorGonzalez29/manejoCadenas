#ifndef ACCIONESMENU_H
#define ACCIONESMENU_H

#include <stdio.h>
#include <Arbol.h>
#include <Socio.h>


int alta(t_socio* socio, FILE* archSocios, t_arbol* indice);
int alta_res(t_socio* socio, FILE* archSocios, t_arbol* indice);
int baja(t_socio* socio, FILE* archSocios, t_arbol* indice);
int baja_res(t_socio* socio, FILE* archSocios, t_arbol* indice);
void ver(FILE* archSocios);


#endif // ACCIONESMENU_H
