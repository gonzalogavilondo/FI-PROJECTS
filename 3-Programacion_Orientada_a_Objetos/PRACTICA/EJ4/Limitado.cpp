//
// Created by Gonza on 22/11/2021.
//

#include "Limitado.h"

#include <utility>
/**
 * Constructor
 */
Limitado::Limitado(string nombre, tipoDeContribuyente tipo) : Contribuyente(move(nombre),tipo) {
    montoVariable = 0.0;
}


/**
 * Destructor
 */
Limitado::~Limitado() {
    //dtor
}

/**
 * Sobrecarga de operadores
 */
ostream& operator<< (ostream& co, Limitado& c) {
    c.print(co);

    return co;
}

/**
 * Setters
 */
void Limitado::setMontoVariable(float val) {
    montoVariable = val;
}

/**
 * Getters
 */
float Limitado::getMontoVariable() const {
    return montoVariable;
}

/**
 * Metodos polimorficos de la clase Limitado
 */
float Limitado::Calculador() {
    float suma = 0.0;
    for(unsigned int i = 0; i < facturas.size(); i++) {
        suma += facturas[i].getMonto();
    }
    montoVariable = suma * 0.005;

    return montoVariable;
}

void Limitado::print(ostream& co) {
    co << "/**CONTRIBUYENTE LIMITADO**/" << endl
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

void Limitado::setContribuyente(istream& ci) {
    ci >> montoVariable;
}