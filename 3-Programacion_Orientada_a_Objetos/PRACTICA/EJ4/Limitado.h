//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_LIMITADO_H
#define EJ4_LIMITADO_H

#include "Contribuyente.h"

class Limitado : public Contribuyente {

private:
    float montoVariable;

public:
    ///Constructor
    Limitado(string nombre = "", tipoDeContribuyente tipo = LIMITADO);

    ///Destructor
    virtual ~Limitado();

    ///Sobrecarga de operadores
    friend ostream& operator<<  (ostream&, Limitado&);

    ///Setters
    void setMontoVariable(float);

    ///Getters
    float getMontoVariable() const;

    ///Metodos polimorficos de la clase Limitado
    virtual float Calculador();
    virtual void print(ostream&);
    virtual void setContribuyente(istream&);

};


#endif //EJ4_LIMITADO_H
