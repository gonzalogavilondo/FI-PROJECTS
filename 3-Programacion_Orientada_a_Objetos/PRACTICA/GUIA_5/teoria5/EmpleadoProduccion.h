//
// Created by victoria on 4/10/2021.
//

#ifndef POLIMORFISMO_EMPLEADOPRODUCCION_H
#define POLIMORFISMO_EMPLEADOPRODUCCION_H

#include "Asalariado.h"

class EmpleadoProduccion: public Asalariado{
    //Atributos de instancia
private:
    char turno [10];
public:
    //Constructor
    EmpleadoProduccion(char[], long, int, double, char[]);
    //Métodos de instancia:
    char * getTurno ();
    void setTurno (char[]);
    //Los métodos redefinidos deben ser declarados en la clase correspondiente
    virtual double getSalario ();
};


#endif //POLIMORFISMO_EMPLEADOPRODUCCION_H
