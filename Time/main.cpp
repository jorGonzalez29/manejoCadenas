#include <iostream>
#include "ClassTime.h"
using namespace std;

int main()
{
    Time time = Time(),
         time2 = Time(0,40,30),
         time3 = Time(0,20,30);
    cout << "Prueba clase hora" << endl;
    cout << time << endl;
    cout << ++time << endl;
    cout << time ++ << endl;
    cout << time << endl;
    cout << --time << endl;
    cout << time -- << endl;
    cout << time << endl;
    cout << time2 + time3<< endl;
    cout << time2 - time3<< endl;
    time2 += time3;
    cout << time2 << endl;
    time2 -= time3;
    cout << time2 << endl;
    cout << time + 7200 << endl;
    time += 200;
    cout << time << endl;
    if( time2 == time3)
        cout << "Son iguales" << endl;
    else{
        if(time2 > time3)
            cout << time2 << " es mayor que: " << time3 << endl;
        else{
            if(time2 < time3)
                cout << time2 << " es menor que: " << time3 << endl;
        }
    }
    if(time2 != time)
        cout << time2 << " es distinto que: " << time << endl;


    return 0;
}
