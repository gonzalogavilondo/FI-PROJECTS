#include <iostream>
#include "punto.h"

using namespace std;

int main()
{
    punto pt1(5, 2),
          pt2(2, 3);
    float dist;

    dist = pt1.CalcularDistancia(pt2);   // distancia tiene acceso a los atributos del objeto pt1 (receptor del mensaje)
                                         // y a los atributos del objeto pt2 (objeto argumento).

    cout << "La distancia entre" << pt1 << "y" << pt2 //Esta sobrecargado el operador << y sabe como imprimir los puntos.
         << "es: " << dist << endl << endl;

    // utilizando la funcion friend
    dist = CalcularDistancia(pt1, pt2);    // es menos confusa la forma de llamar a la funcion

    cout << "El nuevo calculo de distancia es: " << dist << "\n\n";

    return 0;
}

