#include "CuentaUniversitaria.h"

//Constructores y Destructores
CuentaUniversitaria::CuentaUniversitaria(float topeExtr){
    tipo = CUENTAUNIVERSITARIA;
    topeExtrDiaria = topeExtr;
}

CuentaUniversitaria::~CuentaUniversitaria(){
    //dtor
}

//Setters y Getters
void CuentaUniversitaria::setTopeExtrDiaria(float topeExtr){
    topeExtrDiaria = topeExtr;
}

void CuentaUniversitaria::setExtrRestante(float inExtrRestante){
    extrRestante = inExtrRestante;
}

float CuentaUniversitaria::getTopeExtrDiaria(){
    return topeExtrDiaria;
}


float CuentaUniversitaria::getExtrRestante(){
    return extrRestante;
}

//Métodos de CuentaUniversitaria
CuentaBancaria* CuentaUniversitaria::clonar(){
    CuentaUniversitaria copia;
    copia.CBU = CBU;
    copia.tipo = tipo;
    copia.saldo = saldo;
    copia.topeExtrDiaria = topeExtrDiaria;
    copia.extrRestante = extrRestante;

    return new CuentaUniversitaria(copia);
}

bool CuentaUniversitaria::extraccion(float removeSaldo){
    if (removeSaldo < 0) return 0;

    bool exito = 0;
    if(saldo - removeSaldo >= 0 &&  removeSaldo <= extrRestante){
        saldo -= removeSaldo;
        extrRestante -= removeSaldo;
        exito = 1;
    }
    return exito;
}

void CuentaUniversitaria::setCuenta(istream& ci){
    ci >> topeExtrDiaria;
}

void CuentaUniversitaria::printCuenta(ostream& co){
    co << "Cantidad maxima de extracciones por dia: "
       << topeExtrDiaria << " pesos" << endl;
    co << "Tope de giro en descubierto: No permitido." << endl;
}
