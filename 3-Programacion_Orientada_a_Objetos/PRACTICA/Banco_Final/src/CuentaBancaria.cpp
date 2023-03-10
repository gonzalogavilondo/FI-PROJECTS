#include "CuentaBancaria.h"
#include <random>

//Constructores y Destructores

CuentaBancaria::CuentaBancaria(){
    //ctor
}

CuentaBancaria::CuentaBancaria(tipoDeCuenta inTipo){
    tipo = inTipo;
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

void CuentaBancaria::addTitular(string inIdCliente){
    titulares.push_back(inIdCliente);
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

string CuentaBancaria::getTitular(int index){
    return titulares[index];
}

unsigned CuentaBancaria::getSizeTitulares(){
    return titulares.size();
}

//Sobrecarga del operador de extracción e inserción
istream& operator >> (istream& ci, CuentaBancaria& c){
    int cantTitulares = 0;
    if(ci.peek() == '\n') ci.ignore();
    getline(ci, c.CBU);

    int auxTipo;
    ci >> auxTipo;
    c.tipo = static_cast<tipoDeCuenta>(auxTipo);

    ci >> c.saldo;

    ci >> cantTitulares;
    ci.ignore();
    for (int i = 0; i < cantTitulares; i++){
        string auxId;
        getline(ci, auxId);
        c.titulares.push_back(auxId);
    }

    c.setCuenta(ci);

    return ci;
}

ostream& operator << (ostream& co, CuentaBancaria& c){
    co << c.CBU << endl;
    co << (int)c.tipo << endl;
    co << c.saldo << endl;
    co << c.getSizeTitulares() << endl;
    for (unsigned i = 0; i < c.getSizeTitulares(); i++){
        co << c.titulares[i] << endl;
    }

    c.printCuenta(co);

    return co;
}

ostream& CuentaBancaria::mostrarCuenta(ostream& co){
    co << "CBU: " << CBU << endl;
    switch (tipo){
    case CAJADEAHORRO:
        co << "Caja de Ahorro" << endl;
        break;
    case CUENTACORRIENTE:
        co << "Cuenta Corriente" << endl;
        break;
    case CUENTAUNIVERSITARIA:
        co << "Cuenta Universitaria" << endl;
    }

    co << "Saldo: " << saldo << endl;

    return _mostrarCuenta(co);
}

//Métodos de la clase CuentaBancaria
bool CuentaBancaria::deposito(float addSaldo){
    if (addSaldo < 0) return false;

    saldo += addSaldo;

    return true; //Acá consideraríamos errores del sistema.
}
