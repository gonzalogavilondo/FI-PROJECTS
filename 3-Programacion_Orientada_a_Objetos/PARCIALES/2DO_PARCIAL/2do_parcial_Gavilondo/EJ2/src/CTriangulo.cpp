#include "CTriangulo.h"

CTriangulo::CTriangulo()
{
    base = 0.0;
    altura = 0.0;
}

CTriangulo::~CTriangulo()
{
    //dtor
}

/***
    Getters y setters
***/
float CTriangulo::getArea()
{
    return area;
}

void CTriangulo::setArea(float val)
{
    area = val;
}

float CTriangulo::getPerimetro()
{
    return perimetro;
}

void CTriangulo::setPerimetro(float val)
{
    perimetro = val;
}

/***
    Metodos propios
***/
float CTriangulo::calcularPerimetro()
{
    return 3*(base + altura);
}

float CTriangulo::calcularArea()
{
    return (base*altura/2);
}

void CTriangulo::imprimir(ostream& co)
{
    CFigura::imprimir(co);

    if(typeid(co) == typeid(cout)) //Imprime por consola
    {
        co << "Base = " << base << ", "
           << "Altura = " << altura << ", "
           << "Area = " << area << " y "
           << "Perimetro = " << perimetro;

    }
    else //Imprime por texto.
    {
        co << base << endl
           << altura << endl
           << area << endl
           << perimetro;
    }
}
