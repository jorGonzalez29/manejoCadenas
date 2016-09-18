#include<iostream>
#include "Class.h"
using namespace std;
Fecha :: Fecha (int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}
int Fecha :: EsBisiesto (int aaaa){
    if(aaaa % 4 == 0 && (aaaa % 100 != 0 || aaaa % 400 == 0))
        return 1;
    return 0;
}

ostream& operator << (ostream &salida, const Fecha &obj){
    salida << obj.dia <<'/'<< obj.mes <<'/'<< obj.anio;

    return salida;
}
istream& operator >> (istream &entrada, Fecha &obj){
    cout << "Ingrese fecha:"<<endl;
    entrada >> obj.dia >> obj.mes >> obj.anio;

    return entrada;
}
Fecha Fecha :: operator ++ (int){
    Fecha aux = Fecha(dia,mes,anio);
    dia ++;
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||mes == 10 || mes == 12 && dia > 31) || (mes == 4 || mes == 6 || mes == 9 || mes == 11 && dia > 30)){
        dia = 1;
        mes ++;
        if(mes > 12){
            mes = 1;
            anio ++;
        }
    }
    if(mes == 2){
        if(EsBisiesto(anio)){
            if(dia > 29){
                dia = 1;
                mes ++;
                if(mes > 12){
                    mes = 1;
                    anio ++;
                }
            }
        }
        if(dia > 28)
        {
            dia = 1;
            mes ++;
            if(mes > 12){
                mes = 1;
                anio ++;
            }
        }

    }
    return aux;
}
Fecha& Fecha :: operator ++ (){
    dia ++;
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||mes == 10 || mes == 12 && dia > 31) || (mes == 4 || mes == 6 || mes == 9 || mes == 11 && dia > 30)){
        dia = 1;
        mes ++;
        if(mes > 12){
            mes = 1;
            anio ++;
        }
    }
    if(mes == 2){
        if(EsBisiesto(anio)){
            if(dia > 29){
                dia = 1;
                mes ++;
                if(mes > 12){
                    mes = 1;
                    anio ++;
                }
            }
        }

        if(dia > 28)
        {
            dia = 1;
            mes ++;
            if(mes > 12){
                mes = 1;
                anio ++;
            }
        }


    }
    return *this;
}
Fecha Fecha :: operator + (const Fecha &obj)const{

    Fecha aux = Fecha(dia,mes,anio);
    int diasMes[][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                               {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    aux.dia += obj.dia;
    if(aux.dia > diasMes[EsBisiesto(aux.anio)][aux.mes]){
        aux.dia -= diasMes[EsBisiesto(aux.anio)][aux.mes];
        aux.mes ++;
        if(aux.mes > 12){
            aux.mes = 1;
            aux.anio ++;
        }
    }
    aux.mes += obj.mes;
    if(aux.mes > 12)
    {
        aux.mes -= 12;
        aux.anio ++;
    }
    aux.anio += obj.anio;
    return aux;
}
