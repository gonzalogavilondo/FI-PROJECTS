#include "CCirculo.h"

CCirculo::CCirculo()
{
    base = 0.0;
}

CCirculo::~CCirculo()
{
    //dtor
}

/***
    Getters y setters
***/
float CCirculo::getRadio()
{
     return base;
}

void CCirculo::setRadio(float val)
{
     base = val;
}

float CCirculo::getArea()
{
    return area;
}

void CCirculo::setArea(float val)
{
    area = val;
}

float CCirculo::getPerimetro()
{
    return perimetro;
}

void CCirculo::setPerimetro(float val)
{
    perimetro = val;
}

/***
    Metodos propios
***/
float CCirculo::calcularPerimetro()
{
    return (2*PI*base);
}

float CCirculo::calcularArea()
{
    return (PI*base*base);
}

void CCirculo::imprimir(ostream& co)
{
    CFigura::imprimir(co);

    if(typeid(co) == typeid(cout)) //Imprime por consola
    {
        co << "Radio = " << base << ", "
           << "Area = " << area << " y "
           << "Perimetro = " << perimetro;

    }
    else //Imprime por texto.
    {
        co << base << endl
           << area << endl
           << perimetro;
    }

}
