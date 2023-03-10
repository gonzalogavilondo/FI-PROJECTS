//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_FACTURA_H
#define EJ4_FACTURA_H

#include <cstring>
#include "Fecha.h"

class Factura {

private:
    string detalleDelServicio;
    static int numFactura;
    float monto;
    Fecha fechaFactura;

public:
    ///Constructor
    Factura(string detalleDelServicio = "", float monto = 0.0);

    ///Destructor
    virtual ~Factura();

    ///Sobrecarga de operadores
    friend ostream& operator<< (ostream&, Factura&);
    friend istream& operator>> (istream&, Factura&);

    ///Setters
    void setDetalleDelServicio(string);
    static void setNumFactura(int);
    void setMonto(float);
    void setFechaFactura(Fecha);

    ///Getters
    string getDetalleDelServicio();
    static int getNumFactura();
    float getMonto();
    Fecha getFechaFactura();
};


#endif //EJ4_FACTURA_H
