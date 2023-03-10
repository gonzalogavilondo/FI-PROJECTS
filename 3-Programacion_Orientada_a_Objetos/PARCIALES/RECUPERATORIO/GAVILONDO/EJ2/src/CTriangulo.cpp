#include "CTriangulo.h"

/***
    Constructor
***/
CTriangulo::CTriangulo()
{
    //ctor
}


/***
    Destructor
***/
CTriangulo::~CTriangulo()
{
    //dtor
}

/***
    Metodos propios de la clase
***/
float CTriangulo::calcularArea()
{
    return ((base*altura) / 2);
}

float CTriangulo::calcularPerimetro()
{
    return 3*(base + altura);
}

void CTriangulo::setFigura(istream& ci)
{
    ci >> base;
    ci.ignore();
    ci >> altura;
}

void CTriangulo::printFigura(ostream& co)
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
