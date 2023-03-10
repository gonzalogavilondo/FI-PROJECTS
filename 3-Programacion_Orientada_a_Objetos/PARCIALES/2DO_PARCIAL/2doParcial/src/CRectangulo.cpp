#include "CRectangulo.h"

//Constructores y Destructores
CRectangulo::CRectangulo(){
    //ctor
}

CRectangulo::~CRectangulo(){
    //dtor
}

//Métodos de la clase
float CRectangulo::calcularArea(){
    return (base*altura);
}

float CRectangulo::calcularPerimetro(){
    return (2*base + 2*altura);
}

void CRectangulo::setFigura(istream& ci){
    ci >> base;
    ci.ignore();

    ci >> altura;
}

void CRectangulo::printFigura(ostream& co){
    if (typeid(co) == typeid(cout)){
        co << "Base = " << base << ", "
           << "altura = " << altura << ", "
           << "area = " << calcularArea() << " y "
           << "perimetro = " << calcularPerimetro() << endl;
    } else {
        co << base << endl;
    }
}
