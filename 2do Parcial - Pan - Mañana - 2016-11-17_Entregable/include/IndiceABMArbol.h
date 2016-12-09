#ifndef INDICE_H
#define INDICE_H


typedef struct
{
	char id_socio[10];
	int nro_reg;
}
t_indice;


int cmp_ind(const void* i1, const void* i2);
int cmp_ind_res(const void* i1, const void* i2);


#endif // INDICE_H
