#ifndef SOCIO_H
#define SOCIO_H

#include <Fecha.h>


typedef struct
{
	char id_socio[10];
	long documento;
	char nombre[30];
	t_fecha fch_ing;
	char estado; ///'B' si está dado de baja, 'A' si está activo.
}
t_socio;


void ingresarSocio(t_socio* socio);
void ingresarCodSocio(t_socio* socio);
void mostrarSocio(const t_socio* socio);


#endif // SOCIO_H
