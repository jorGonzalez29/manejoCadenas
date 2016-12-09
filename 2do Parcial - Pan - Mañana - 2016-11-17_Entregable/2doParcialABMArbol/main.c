#include <stdio.h>
#include <stdlib.h>
#include <Defs.h>
#include <Arbol.h>
#include <Menu.h>
#include <Socio.h>
#include <AccionesMenu.h>
#include <TipoTDA.h>
#include <MainABMArbol.h>



int main()
{
	char opcion;
	char mOpciones[][30] = {"ABVLS", "Alta", "Baja", "Ver Archivo", "Ver Arbol", "Salir"};
	char titulo[] = "ABM Socios";
	FILE* archSocios;
	t_arbol indice;


	archSocios = fopen("../Archivos_ABMArbol/Socios.dat", "r+b");

	if(!archSocios)
	{
		puts("Error abriendo el archivo");
		return ERROR_ARCHIVO;
	}


	crear_arbol_res(&indice);

	cargar_arbol_de_archivo_ordenado_res(&indice, "../Archivos_ABMArbol/Socios.idx", /*cmp_ind*/cmp_ind_res);


    opcion = menu(mOpciones, titulo);
    while(opcion != 'S')
	{
		system("cls");

		switch(opcion)
		{
			case 'A': opcAlta(archSocios, &indice); break;
			case 'B': opcBaja(archSocios, &indice); break;
			case 'V': opcVer(archSocios, &indice); break;
			case 'L': opcVerArbol(&indice); break;
		}

		pausa("");

		opcion = menu(mOpciones, titulo);
	}


	grabar_arbol_en_archivo_ordenado_res(&indice, "../Archivos_ABMArbol/Socios.idx");

	///vaciar_arbol(&indice);
	vaciar_arbol_res(&indice);

    return 0;
}



void opcAlta(FILE* archSocios, t_arbol* indice)
{
	t_socio socio;
	int resp;

	ingresarSocio(&socio);

	resp = alta(&socio, archSocios, indice);
	///resp = alta_res(&socio, archSocios, indice);

	mostrarCodigo(resp); ///Muestra el mensaje correspondiente a cada código de retorno, ej: DUPLICADO: "Código duplicado".
}



void opcBaja(FILE* archSocios, t_arbol* indice)
{
	t_socio socio;
	int resp;

	ingresarCodSocio(&socio);

	///resp = baja(&socio, archSocios, indice);
	resp = baja_res(&socio, archSocios, indice);

	mostrarCodigo(resp); ///Muestra el mensaje correspondiente a cada código de retorno, ej: DUPLICADO: "Código duplicado".
}



void opcVer(FILE* archSocios, t_arbol* indice)
{
	ver(archSocios);
}



void opcVerArbol(const t_arbol* pa)
{
	arbolGrafico(pa, mostrarClave);
}



void mostrarCodigo(int codigo)
{
	switch(codigo)
	{
		case SIN_MEM: puts("Sin memoria"); break;
		case DUPLICADO: puts("Codigo duplicado"); break;
		case NO_EXISTE: puts("El codigo no existe"); break;
		case TODO_OK: puts("Operacion exitosa"); break;
		default: puts("Codigo de retorno no contemplado (Utilizo los codigos proporcionados en el archivo defines.h?)"); break;
	}
}



void mostrarClave(const void* pv)
{
    t_dato* etiq = (t_dato*)pv;

    printf("%-10s", etiq->id_socio);
}
