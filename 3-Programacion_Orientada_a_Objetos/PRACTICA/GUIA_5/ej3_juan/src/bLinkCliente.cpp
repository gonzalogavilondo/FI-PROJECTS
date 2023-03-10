#include "bLinkCliente.h"

bLinkCliente::bLinkCliente(){
    //ctor
}


bLinkCliente::bLinkCliente(Cliente& inCliente){
    cliente = inCliente;
}

bLinkCliente::bLinkCliente(const bLinkCliente& inLC){
    cliente = inLC.cliente;
    for (int i = 0; i < inLC.getSizeCuentasBancarias(); i++){
        CuentaBancaria *auxCuenta = inLC.cuentasCliente[i]->clonar();
        cuentasCliente.push_back(auxCuenta);
    }
}

bLinkCliente::~bLinkCliente(){
    for (int i = 0; i < getSizeCuentasBancarias(); i++){
        delete cuentasCliente[i];
    }
}

void bLinkCliente::setCliente(Cliente& inCliente){
    cliente = inCliente;
}

Cliente& bLinkCliente::getCliente(){
    return cliente;
}

vector <CuentaBancaria*> bLinkCliente::getCuentas(){
    return cuentasCliente;
}

void bLinkCliente::addCuentaBancaria(CuentaBancaria* inCuenta){
    cuentasCliente.push_back(inCuenta);
}

CuentaBancaria* bLinkCliente::getCuentaBancaria(int index){
    if (index >= int(cuentasCliente.size())) return NULL;

    return cuentasCliente[index];
}

int bLinkCliente::getSizeCuentasBancarias() const{
    return cuentasCliente.size();
}
