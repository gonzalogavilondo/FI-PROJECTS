#include "punto.h"

punto::punto(float coorx, float coory)
{
    x = coorx;
    y = coory;
}

punto::~punto()
{
    //dtor
}

float punto::CalcularDistancia(punto pto)
{
    float d;

    d = sqrt( pow(pto.x-x, 2) + pow(pto.y-y, 2) );

    return d;
}

float punto::Get_x()
{
    return x;
}

float punto::Get_y()
{
    return y;
}

void punto::Set_x(float val)
{
    x = val;
}

void punto::Set_y(float val)
{
    y = val;
}

/***
void punto::Visualizar()
{
    cout << " (" << x << ", " << y << ") ";
}

En vez de hacer esta funcion, hago una funcion amiga para sobrecargar el operador << (indireccion)
para que el cout (en este caso que es lo que vamos a usar como stream de salida) sepa como imprimir
la clase punto.

***/

ostream& operator<< (ostream& co, punto &pto) //Funcion amiga sobrecargando el operador << (indireccion)
{
    co << " (" << pto.x << ", " << pto.y << ") ";

    return co;
}

float CalcularDistancia(punto pt1, punto pt2)
{
    float d;

    d = sqrt( pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2) );

    return d;
}
