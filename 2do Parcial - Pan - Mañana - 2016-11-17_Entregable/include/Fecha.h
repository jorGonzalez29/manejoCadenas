#ifndef FECHA_H
#define FECHA_H

typedef struct
{
	int d;
	int m;
	int a;
}
t_fecha;


int es_fecha_valida(const t_fecha* fecha);
int cant_dias_mes(int mes, int anio);
int es_bisiesto(int anio);
int es_fecha_valida_res(const t_fecha* fecha);
int cant_dias_mes_res(int mes, int anio);
int es_bisiesto_res(int anio);
void ingresarFecha(t_fecha* fecha);


#endif // FECHA_H
