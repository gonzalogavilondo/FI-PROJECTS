#include "CuentaCorriente.h"

//Constructores y Destructores
CuentaCorriente::CuentaCorriente(float topeGiro){
    tipo = CUENTACORRIENTE;
    topeDescubierto = topeGiro;
}

CuentaCorriente::~CuentaCorriente(){
    //dtor
}

//Setters y Getters
void CuentaCorriente::setTopeGiro(float topeGiro){
    topeDescubierto = topeGiro;
}

float CuentaCorriente::getTopeGiro(){
    return topeDescubierto;
}

//Métodos de CuentaCorriente
CuentaBancaria* CuentaCorriente::clonar(){
    CuentaCorriente copia;
    copia.CBU = CBU;
    copia.tipo = tipo;
    copia.saldo = saldo;
    copia.topeDescubierto = topeDescubierto;

    return new CuentaCorriente(copia);
}

bool CuentaCorriente::extraccion(float removeSaldo){
    if (removeSaldo < 0) return false;

    bool exito = false;
    if(removeSaldo <= topeDescubierto + saldo){
        saldo -= removeSaldo;
        exito = true;
    }
    return exito;
}

void CuentaCorriente::setCuenta(istream& ci){
    ci >> topeDescubierto;
}

void CuentaCorriente::printCuenta(ostream& co){
    co << topeDescubierto << endl;
}

ostream& CuentaCorriente::_mostrarCuenta(ostream& co){
    co << "Cantidad maxima de extracciones por mes: "
       << "Ilimitado" << endl;
    co << "Tope de giro en descubierto: " << topeDescubierto
       << endl;

    return co;
}
