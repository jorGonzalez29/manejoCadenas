#include "listas.h"

int main()
{
    t_lista lista;
    t_info auxDeCarga;
    char op;
    crearLista(&lista);
    printf("\nCarga de datos en la lista. ");
    printf("\nDesea cargar datos en la lista ? S/N: ");
    fflush(stdin);
    scanf("%c", &op);
    while(op == 'S' && !listaLlena(&lista))
    {
        printf("\nNombre y apellido: ");
        fflush(stdin);
        scanf("%[^\n]", auxDeCarga.apyn);

        printf("\nDNI: ");
        scanf("%d", &auxDeCarga.dni);

        printf("\nSexo (M/F): ");
        fflush(stdin);
        scanf("%c", &auxDeCarga.sexo);

        printf("\nSueldo: ");
        scanf("%f", &auxDeCarga.sueldo);

        insertarEnOrdenPorDni2(&lista, &auxDeCarga, comparaApyn);

        printf("\nDesea cargar datos en la lista? S/N: ");
        fflush(stdin);
        scanf("%c", &op);
    }

    printf("\nFIN DE CARGA DE DATOS.");

    imprimirLista(&lista);

    printf("\n\nLa lista tiene: %d nodos.", contarNodos(&lista));

    system("pause");

    return 0;
}
