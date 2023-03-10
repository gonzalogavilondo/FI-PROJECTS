#include "CuentaBancaria.h"
#include <random>

//Constructores y Destructores

CuentaBancaria::CuentaBancaria(){
    this->generadorCBU();
    saldo = 0.0;
}

CuentaBancaria::CuentaBancaria(tipoDeCuenta inTipo){
    this->generadorCBU();
    tipo = inTipo;
    saldo = 0.0;
}

CuentaBancaria::~CuentaBancaria(){
    //dtor
}

//Setters y Getters
void CuentaBancaria::setCBU(string inCBU){
    CBU = inCBU;
}

void CuentaBancaria::setTipo(tipoDeCuenta inTipo){
    tipo = inTipo;
}

void CuentaBancaria::setSaldo(float inSaldo){
    saldo = inSaldo;
}

string CuentaBancaria::getCBU(){
    return CBU;
}

tipoDeCuenta CuentaBancaria::getTipo(){
    return tipo;
}

float CuentaBancaria::getSaldo(){
    return saldo;
}

//Sobrecarga del operador de extracción e inserción
istream& operator >> (istream& ci, CuentaBancaria& c){
    getline(ci, c.CBU);

    int auxTipo;
    ci >> auxTipo;
    c.tipo = static_cast<tipoDeCuenta>(auxTipo);

    ci >> c.saldo;

    c.setCuenta(ci);

    return ci;
}

ostream& operator << (ostream& co, CuentaBancaria& c){

    switch (c.tipo){
    case CAJADEAHORRO:
        co << "Caja de Ahorro" << endl;
        break;
    case CUENTACORRIENTE:
        co << "Cuenta Corriente" << endl;
        break;
    case CUENTAUNIVERSITARIA:
        co << "Cuenta Universitaria" << endl;
    }


    co << "CBU: " << c.CBU << endl;
    co << "Saldo: " << c.saldo << endl;
    c.printCuenta(co);

    return co;
}

//Métodos de la clase CuentaBancaria
void CuentaBancaria::generadorCBU(){
    for (int i = 0; i < 22; i++){
        string aux = to_string(rand()%11);
        CBU.push_back(aux[0]);
    }
}

bool CuentaBancaria::deposito(float addSaldo){
    if (addSaldo < 0) return 0;

    saldo += addSaldo;

    return true; //Acá consideraríamos errores del sistema.
}
