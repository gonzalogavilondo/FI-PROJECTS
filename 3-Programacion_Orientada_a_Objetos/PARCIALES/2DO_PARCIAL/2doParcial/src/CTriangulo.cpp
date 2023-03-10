#include "CTriangulo.h"

//Constructores y Destructores
CTriangulo::CTriangulo(){
    //ctor
}

CTriangulo::~CTriangulo(){
    //dtor
}

//Métodos de la clase
float CTriangulo::calcularArea(){
    return ((base*altura)/2);
}

float CTriangulo::calcularPerimetro(){
    float hip = sqrt(pow(base, 2)+pow(altura, 2));

    return (base+altura+hip);
}

void CTriangulo::setFigura(istream& ci){
    ci >> base;
    ci.ignore();

    ci >> altura;
}

void CTriangulo::printFigura(ostream& co){
    if (typeid(co) == typeid(cout)){
        co << "Base = " << base << ", "
           << "altura = " << altura << ", "
           << "area = " << calcularArea() << " y "
           << "perimetro = " << calcularPerimetro() << endl;
    } else {
        co << base << endl;
    }
}
