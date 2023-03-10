//
// Created by Gonza on 22/11/2021.
//

#include "Contribuyente.h"

#include <utility>

/**
 * Constructor
 */
Contribuyente::Contribuyente(string nombre, tipoDeContribuyente tipo) {
    this->nombre = move(nombre);
    this->tipo = tipo;
    this->montoFijo = 5.0;
}

/**
 * Destructor
 */
Contribuyente::~Contribuyente() {
    //dtor
}


/**
 * Sobrecarga de operadores
 */
ostream& operator<< (ostream& co, Contribuyente& c) {
    c.print(co);

    return co;
}

istream& operator>> (istream & ci, Contribuyente& c) {
    if(ci.peek() == '\n') ci.ignore();
    getline(ci, c.nombre);
    getline(ci, c.dni);
    getline(ci, c.id);
    int auxTipo;
    ci >> auxTipo;
    c.tipo = static_cast<tipoDeContribuyente>(auxTipo);
    int cntFacturas;
    ci >> cntFacturas;

    for (int i = 0; i < cntFacturas; i++) {
        Factura aux;
        ci >> aux;
        c.facturas.push_back(aux);
    }
    c.setContribuyente(ci);

    return ci;
}


/**
 * Setters
 */
void Contribuyente::setNombre(string val) {
    nombre = move(val);
}

void Contribuyente::setDni(string val) {
    dni = move(val);
}

void Contribuyente::setMontoFijo(float val) {
    montoFijo = val;
}

void Contribuyente::setTipoDeContribuyente(tipoDeContribuyente val) {
    tipo = val;
}

void Contribuyente::setFacturas(vector<Factura> val) {
    facturas = move(val);
}


/**
 * Getters
 */
string Contribuyente::getNombre() const {
    return nombre;
}

string Contribuyente::getDni() const {
    return dni;
}

float Contribuyente::getMontoFijo() const {
    return montoFijo;
}

tipoDeContribuyente Contribuyente::getTipoDeContribuyente() const {
    return tipo;
}

vector<Factura> Contribuyente::getFacturas() const {
    return facturas;
}

string Contribuyente::getId() {
    return id;
}
