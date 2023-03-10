//
// Created by Gonza on 22/11/2021.
//

#include "Factura.h"

#include <utility>

/**
 * Constructor
 */
Factura::Factura(string detalleDelServicio, float monto) {
    this->detalleDelServicio = detalleDelServicio;
    this->monto = monto;
    numFactura++;
}

/**
 * Destructor
 */
Factura::~Factura() {
    //dtor
}

/**
 * Sobrecarga de operadores
 */
ostream& operator<< (ostream& co, Factura& c) {
    co << "Detalle del servicio = " << c.detalleDelServicio << endl
       << "Numero de factura = " << c.numFactura << endl
       << "Monto = " << c.monto << endl
       << "Fecha de la factura = " << c.fechaFactura << endl;

    return co;
}

istream& operator>> (istream& ci, Factura& c) {
    if(ci.peek() == '\n') ci.ignore();
    getline(ci, c.detalleDelServicio);
    ci >> c.monto;
    ci >> c.fechaFactura;

    return ci;
}

/**
 * Setters
 */

void Factura::setDetalleDelServicio(string val) {
    detalleDelServicio = std::move(val);
}

void Factura::setNumFactura(int val) {
    numFactura = val;
}

void Factura::setMonto(float val) {
    monto = val;
}

void Factura::setFechaFactura(Fecha val) {
    fechaFactura = val;
}

/**
 * Getters
 */

string Factura::getDetalleDelServicio() {
    return detalleDelServicio;
}

int Factura::getNumFactura() {
    return numFactura;
}

float Factura::getMonto() {
    return monto;
}

Fecha Factura::getFechaFactura() {
    return fechaFactura;
}

