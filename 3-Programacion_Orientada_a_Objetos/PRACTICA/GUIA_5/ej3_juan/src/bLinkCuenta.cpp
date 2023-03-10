#include "bLinkCuenta.h"

bLinkCuenta::bLinkCuenta(){

}

bLinkCuenta::bLinkCuenta(const bLinkCuenta& inLC){
    cuenta = inLC.cuenta->clonar();
    for (int i = 0; i < inLC.getSizeTitulares(); i++){
        addTitular(inLC.getTitular(i));
    }
}

bLinkCuenta::~bLinkCuenta(){
//    for (int i = 0; i < getSizeTitulares(); i++){
//        delete titularesCuenta[i];
//    }
}

void bLinkCuenta::setCuenta(CuentaBancaria* inCuenta){
    cuenta = inCuenta;
}

CuentaBancaria* bLinkCuenta::getCuenta(){
    return cuenta;
}

vector <Cliente*> bLinkCuenta::getTitulares(){
    return titularesCuenta;
}

void bLinkCuenta::addTitular(Cliente& inCliente){
    titularesCuenta.push_back(&inCliente);
}

Cliente& bLinkCuenta::getTitular(int index) const{
    return *titularesCuenta[index];
}

int bLinkCuenta::getSizeTitulares() const{
    return titularesCuenta.size();
}
