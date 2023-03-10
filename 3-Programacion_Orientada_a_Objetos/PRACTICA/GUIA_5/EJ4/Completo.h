//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_COMPLETO_H
#define EJ4_COMPLETO_H

#include "Contribuyente.h"

class Completo : public Contribuyente {

private:
    float montoVariable;

public:
    ///Constructor
    Completo(string nombre = "", tipoDeContribuyente tipo = LIMITADO);

    ///Destructor
    virtual ~Completo();

    ///Sobrecarga de operadores
    friend ostream& operator<< (ostream&, Completo&);

    ///Setters
    void setMontoVariable(float);

    ///Getters
    float getMontoVariable() const;

    ///Metodos polimorficos
    virtual float Calculador();
    virtual void print(ostream&);
    virtual void setContribuyente(istream&);

};


#endif //EJ4_COMPLETO_H
