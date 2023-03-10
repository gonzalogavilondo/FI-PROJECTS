#include "CRectangulo.h"

/***
    Constructor
***/
CRectangulo::CRectangulo()
{
    //ctor
}


/***
    Destructor
***/
CRectangulo::~CRectangulo()
{
    //dtor
}

/***
    Metodos propios de la clase
***/
float CRectangulo::calcularArea()
{
    return (base*altura);
}

float CRectangulo::calcularPerimetro()
{
    return (2*base + 2*altura);
}

void CRectangulo::setFigura(istream& ci)
{
    ci >> base;
    ci.ignore();
    ci >> altura;
}

void CRectangulo::printFigura(ostream& co)
{
    if (typeid(co) == typeid(cout))
    {
        co << "Base = " << base << ", "
           << "altura = " << altura << ", "
           << "area = " << calcularArea() << " y "
           << "perimetro = " << calcularPerimetro() << endl;
    }
    else
    {
        co << base << ';'
           << altura << endl;
    }
}
