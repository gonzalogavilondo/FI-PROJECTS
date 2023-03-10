#include "CCirculo.h"

/***
    Constructor
***/
CCirculo::CCirculo()
{
    altura = 0.0;
}


/***
    Destructor
***/
CCirculo::~CCirculo()
{
    //dtor
}

/***
    Metodos propios de la clase
***/
float CCirculo::calcularArea()
{
    return (PI*pow(base, 2));
}

float CCirculo::calcularPerimetro()
{
    return (2*PI*base);
}

void CCirculo::setFigura(istream& ci)
{
    ci >> base;
}

void CCirculo::printFigura(ostream& co)
{
    if (typeid(co) == typeid(cout))
    {
        co << "Radio = " << base << ", "
           << "area = " << calcularArea() << " y "
           << "perimetro = " << calcularPerimetro() << endl;
    }
    else
    {
        co << base << endl;
    }
}
