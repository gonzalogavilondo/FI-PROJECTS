#include "Camioneta.h"

//Constructores y Destructores
Camioneta::Camioneta(){
    tara = 0;
    carga = 0;
}

Camioneta::Camioneta(string pDueno, string pMarca, string pPatente, int pPuertas,
           float pKil, int pCil, float pTara, float pCarga) :
           Vehiculo(pDueno, pMarca, pPatente, pPuertas,
                    pKil, pCil){
    tara = pTara;
    carga = pCarga;
}

Camioneta::~Camioneta(){
    //dtor
}

//Setters y Getters
void Camioneta::setTara(float ta){
    tara = ta;
}

void Camioneta::setCarga(float ca){
    carga = ca;
}

float Camioneta::getTara(){
    return tara;
}

float Camioneta::getCarga(){
    return carga;
}

//Sobrecarga de los operadores de extracción e inserción
istream& operator >> (istream& ci, Camioneta& c){
    c.setVehiculo(ci);
    return ci;
}

ostream& operator << (ostream& co, const Camioneta& c){
    c.printVehiculo(co);

    return co;
}

//Métodos de la clase "Camioneta"
void Camioneta::caracteristicas(){
    cout << "Características de Camioneta." << endl;
}

void Camioneta::cargar(float addCarga){
    carga += addCarga;
}

void Camioneta::printVehiculo(ostream& co) const{
    co << "Tara: " << tara << endl;
    co << "Carga: " << carga << endl;
}

void Camioneta::setVehiculo(istream& ci){
    ci >> tara;
    ci >> carga;
}
