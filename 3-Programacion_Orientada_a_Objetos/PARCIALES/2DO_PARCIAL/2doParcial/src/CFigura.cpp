#include "CFigura.h"

//Constructores y Destructores
CFigura::CFigura(){
    base = 0;
    altura = 0;
    tipo = NINGUNA;
}

CFigura::~CFigura(){

}

//Setters y Getters
tipoFigura CFigura::strToTipo (string strTipo){
    tipoFigura retTipo = NINGUNA;

    if (strTipo == "Circulo") retTipo = CIRCULO;
    if (strTipo == "Rectangulo") retTipo = RECTANGULO;
    if (strTipo == "Triangulo") retTipo = TRIANGULO;

    return retTipo;
}

void CFigura::setTipo(string strTipo){
    tipo = strToTipo(strTipo);
}

void CFigura::setForeColor(CColor inColor){
    foreColor = inColor;
}

void CFigura::setBackColor(CColor inColor){
    backColor = inColor;
}

void CFigura::setBase(float inBase){
    base = inBase;
}

void CFigura::setAltura(float inAltura){
    altura = inAltura;
}

string CFigura::getTipo(){
    string strTipo;

    switch (tipo){
    case CIRCULO:
        strTipo = "Circulo";
        break;
    case RECTANGULO:
        strTipo = "Rectangulo";
        break;
    case TRIANGULO:
        strTipo = "Triangulo";
        break;
    default:
        strTipo = "Ninguna";
    }

    return strTipo;
}

CColor CFigura::getForeColor(){
    return foreColor;
}

CColor CFigura::getBackColor(){
    return backColor;
}

float CFigura::getBase(){
    return base;
}

float CFigura::getAltura(){
    return altura;
}

//Sobrecarga de los operadores de extracción e inserción
istream& operator >> (istream& ci, CFigura& fig){

    ci >> fig.foreColor;
    ci.ignore();

    ci >> fig.backColor;
    ci.ignore();

    fig.setFigura(ci);

    return ci;
}

ostream& operator << (ostream& co, CFigura& fig){
    if (typeid(co) == typeid(cout)){
        co << "Soy un " << fig.getTipo()
           << " con color " << fig.foreColor
           << " sobre " << fig.backColor << "\n\t\t";
    } else {
        co << fig.getTipo() << ';'
           << fig.foreColor << ';'
           << fig.backColor << ';';
    }

    fig.printFigura(co);

    return co;
}
