#include "CRectangulo.h"

CRectangulo::CRectangulo()
{
    base = 0.0;
    altura = 0.0;
}

CRectangulo::~CRectangulo()
{
    //dtor
}


/***
    Getters y setters
***/

float CRectangulo::getArea()
{
    return area;
}

void CRectangulo::setArea(float val)
{
    area = val;
}

float CRectangulo::getPerimetro()
{
    return perimetro;
}

void CRectangulo::setPerimetro(float val)
{
    perimetro = val;
}


/***
    Metodos propios
***/
float CRectangulo::calcularPerimetro()
{
    return (2*base + 2*altura);
}

float CRectangulo::calcularArea()
{
    return (base*altura);
}

void CRectangulo::imprimir(ostream& co)
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
