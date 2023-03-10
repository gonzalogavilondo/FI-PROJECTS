//
// Created by Gonza on 22/11/2021.
//

#include "Extendido.h"

#include <utility>

/**
 * Constructor
 */
Extendido::Extendido(string nombre, tipoDeContribuyente tipo) : Contribuyente(move(nombre), tipo) {
    montoVariable = 0.0;
    montoAdicional = 10;
    montoFijo = 5.0;
}


/**
 * Destructor
 */
Extendido::~Extendido() {
    //dtor
}

/**
 * Sobrecarga de operadores
 */
ostream& operator<< (ostream& co, Extendido& c) {
    c.print(co);

    return co;
}

/**
 * Setters
 */
void Extendido::setMontoVariable(float val) {
    montoVariable = val;
}

void Extendido::setMontoAdicional(float val) {
    montoAdicional = val;
}

/**
 * Getters
 */
float Extendido::getMontoVariable() const {
    return montoVariable;
}

float Extendido::getMontoAdicional() const {
    return montoAdicional;
}

/**
 * Metodos polimorficos de la clase Extendido
 */
float Extendido::Calculador()
{
    float suma = 0.0;
    for(unsigned int i = 0; i < facturas.size(); i++) {
        if(facturas[i].getMonto() > 5000.0) {
            suma += facturas[i].getMonto() * 0.5;
        }
        else {
            suma += facturas[i].getMonto();
        }
        suma += montoAdicional;
    }
    montoVariable = suma;

    return montoVariable;
}

void Extendido::print(ostream& co) {
    co << "/**CONTRIBUYENTE EXTENDIDO**/" << endl
       << "Nombre = " << nombre << endl
       << "Dni = " << dni << endl
       << "ID = " << id << endl
       << "Monto fijo = " << montoFijo << endl
       << "Monto Variable = " << montoVariable << endl
       << "Monto Adicional = " << montoAdicional << endl
       << endl << "/**********FACTURAS**********/" << endl;

    for(size_t i = 0; i < facturas.size(); i++) {
        co << facturas[i] << endl;
    }
}

void Extendido::setContribuyente(istream& ci) {
    ci >> montoVariable;
    ci >> montoAdicional;
}