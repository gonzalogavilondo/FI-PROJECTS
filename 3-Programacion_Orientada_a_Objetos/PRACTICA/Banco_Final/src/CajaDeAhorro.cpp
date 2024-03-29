#include "CajaDeAhorro.h"

//Constructores y Destructores
CajaDeAhorro::CajaDeAhorro(int cantMax){
    tipo = CAJADEAHORRO;
    cantMaxExtrMens = cantMax;
}

CajaDeAhorro::~CajaDeAhorro(){
    //dtor
}

//Setters y Getters
void CajaDeAhorro::setcantMaxExtr(int cantMax){
    cantMaxExtrMens = cantMax;
}

int CajaDeAhorro::getcantMaxExtr(){
    return cantMaxExtrMens;
}

//M�todos de CajaDeAhorro
CuentaBancaria* CajaDeAhorro::clonar(){
    CajaDeAhorro copia;
    copia.CBU = CBU;
    copia.tipo = tipo;
    copia.saldo = saldo;
    copia.cantMaxExtrMens = cantMaxExtrMens;

    return new CajaDeAhorro(copia);
}

bool CajaDeAhorro::extraccion(float removeSaldo){
    if (removeSaldo < 0) return false;

    Fecha hoy = Fecha(); //Inicializo con la fecha de hoy.
    if(hoy.getDay() == 1) cantMaxExtrMens = 20; // Actualizo el valor todos los dias 1 de cada mes.

    bool exito = false;
    if(saldo - removeSaldo >= 0 && cantMaxExtrMens > 0){
        saldo -= removeSaldo;
        cantMaxExtrMens--;
        exito = true;
    }
    return exito;
}

void CajaDeAhorro::setCuenta(istream& ci){
    ci >> cantMaxExtrMens;
}

void CajaDeAhorro::printCuenta(ostream& co){
    co << cantMaxExtrMens << endl;
}

ostream& CajaDeAhorro::_mostrarCuenta(ostream& co){
    co << "Cantidad maxima de extracciones por mes: "
       << cantMaxExtrMens << endl;
    co << "Tope de giro en descubierto: No permitido" << endl;

    return co;
}
