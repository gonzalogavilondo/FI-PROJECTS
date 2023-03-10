#include "Auto.h"

//Constructores y Destructores
Auto::Auto(){
    esDescapotable = false;
}

Auto::Auto(string pDueno, string pMarca, string pPatente, int pPuertas,
           float pKil, int pCil, bool pEsDes) :
           Vehiculo(pDueno, pMarca, pPatente, pPuertas,
                    pKil, pCil){
    esDescapotable = pEsDes;
}

Auto::~Auto(){
    //dtor
}

//Getters y Setters
void Auto::setEsDescapotable(bool b){
    esDescapotable = b;
}

bool Auto::getEsDescapotable(){
    return esDescapotable;
}

//Sobrecarga de los operadores de extracción e inserción
istream& operator >> (istream& ci, Auto& a){
    a.setVehiculo(ci);

    return ci;
}

ostream& operator << (ostream& co, const Auto& a){
    a.printVehiculo(co);

    return co;
}

//Métodos de "Auto"
void Auto::caracteristicas(){
    cout << "Características de Auto." << endl;
}

void Auto::subir(){
    cout << "Auto subiendo" << endl;
}

void Auto::bajar(){
    cout << "Auto bajando" << endl;
}

void Auto::printVehiculo(ostream& co) const{
    co << "Es descapotable: "
         << ((esDescapotable)? "Si" : "No") << endl;
}

void Auto::setVehiculo(istream& ci){
    ci >> esDescapotable;
}
