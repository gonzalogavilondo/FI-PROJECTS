//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_EXTENDIDO_H
#define EJ4_EXTENDIDO_H

#include "Contribuyente.h"

class Extendido : public Contribuyente {

private:
    float montoVariable;
    float montoAdicional;

public:
    ///Contructor
    Extendido(string nombre = "", tipoDeContribuyente tipo = LIMITADO);

    ///Destructor
    virtual ~Extendido();

    ///Sobrecarga de operadores
    friend ostream& operator<< (ostream&, Extendido&);

    ///Setters
    void setMontoVariable(float);
    void setMontoAdicional(float);

    ///Getters
    float getMontoVariable() const;
    float getMontoAdicional() const;

    ///Metodos polimorficos de la clase Extendido
    virtual float Calculador();
    virtual void print(ostream&);
    virtual void setContribuyente(istream&);

};


#endif //EJ4_EXTENDIDO_H
