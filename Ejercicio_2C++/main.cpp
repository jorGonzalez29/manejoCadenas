#include <iostream>
#include "Class.h"
using namespace std;

int main()
{
    cout << "\t\t\t\t\t\t" <<"Clase Hora" << endl;
    Fecha fecha = Fecha();
    Fecha fecha2 = Fecha();
    Fecha fecha3 = Fecha();
    cin >> fecha;
    cout<<"La fecha ingresa es:";
    cout<< fecha<<endl;
    fecha2 = fecha ++;
    cout<<"Fecha2:"<<fecha2<<endl;
    cout<<"Fecha:"<<fecha<<endl;
    fecha3 = ++ fecha2;
    cout<<"Fecha3:"<<fecha3 <<endl;
    cout<<"Fecha2:"<<fecha2<<endl;
    cout<<"Suma de dos fechas";
    fecha = fecha2 + fecha3;
    cout<<"Fecha:"<<fecha<<endl;
    return 0;
}
