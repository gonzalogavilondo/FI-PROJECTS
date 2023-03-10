//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_CONTRIBUYENTE_H
#define EJ4_CONTRIBUYENTE_H

#include <iostream>
#include <vector>
#include <cstring>
#include "Factura.h"

using namespace  std;

enum tipoDeContribuyente {
    LIMITADO, COMPLETO, EXTENDIDO
};

class Contribuyente {

protected:
    ///Atributos
    string nombre;
    string dni;
    tipoDeContribuyente tipo;
    string id;
    float montoFijo;
    vector <Factura> facturas;

public:
    ///Constructor
    Contribuyente(string nombre = "", tipoDeContribuyente tipo = LIMITADO);

    ///Destructor
    virtual ~Contribuyente();

    ///Sobrecarga de operadores
    friend ostream& operator<< (ostream&, Contribuyente&);
    friend istream& operator>> (istream&, Contribuyente&);

    ///Setters
    void setNombre(string);
    void setDni(string);
    void setMontoFijo(float);
    void setTipoDeContribuyente(tipoDeContribuyente);
    void setFacturas(vector<Factura>);

    ///Getters
    string getNombre() const;
    string getDni() const;
    float getMontoFijo() const;
    tipoDeContribuyente getTipoDeContribuyente() const;
    vector<Factura> getFacturas() const;
    string getId();

    ///Metodos polimorficos de la clase contribuyente
    virtual float Calculador() = 0; //Este es el metodo polimorfico, al igualarlo a "0" y a la vez ser virtual, hacemos que la clase sea abstracta.
    virtual void print(ostream&) = 0; //Metodo para poder imprimir de acuerdo al objeto referenciado.
    virtual void setContribuyente(istream&) = 0;

};


#endif //EJ4_CONTRIBUYENTE_H
