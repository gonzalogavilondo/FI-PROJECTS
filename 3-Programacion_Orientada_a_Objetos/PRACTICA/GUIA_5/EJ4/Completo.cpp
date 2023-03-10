//
// Created by Gonza on 22/11/2021.
//

#include "Completo.h"

#include <utility>

/**
 * Constructor
 */
Completo::Completo(string nombre, tipoDeContribuyente tipo) : Contribuyente(move(nombre), tipo) {
    montoVariable = 0.0;
    montoFijo = 5.0;
}

/**
 * Destructor
*/
Completo::~Completo() {
    //dtor
}

/**
 * Sobrecarga de operadores
 */
ostream& operator<< (ostream& co, Completo& c) {
    c.print(co);

    return co;
}

/***
    Setters
***/
void Completo::setMontoVariable(float val)
{
    montoVariable = val;
}

/***
    Getter
***/
float Completo::getMontoVariable() const
{
    return montoVariable;
}

/***
    Metodos polimorficos de la clase Completo
***/
float Completo::Calculador() {
    float suma = 0.0;
    for(unsigned int i = 0; i < facturas.size(); i++) {
        if(facturas[i].getMonto() > 5000.0) {
            suma += facturas[i].getMonto() * 0.5;
        }
        else {
            suma += facturas[i].getMonto();
        }
    }
    montoVariable = suma;

    return montoVariable;
}

void Completo::print(ostream& co) {
    co << "/**CONTRIBUYENTE COMPLETO**/" << endl
       << "Nombre = " << nombre << endl
       << "Dni = " << dni << endl
       << "ID = " << id << endl
       << "Monto fijo = " << montoFijo << endl
       << "Monto Variable = " << montoVariable << endl
       << endl << "/**********FACTURAS**********/" << endl;

    for(size_t i = 0; i < facturas.size(); i++) {
        co << facturas[i] << endl;
    }

}

void Completo::setContribuyente(istream& ci) {
    ci >> montoVariable;
}