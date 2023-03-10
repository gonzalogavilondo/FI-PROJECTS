#ifndef EMPLEADODISTRIBUCION_H_INCLUDED
#define EMPLEADODISTRIBUCION_H_INCLUDED

#include "Asalariado.h"
class EmpleadoDistribucion: public Asalariado{
//Atributos de instancia
private:
    char region [10];
public:
    //Constructor
    EmpleadoDistribucion(char[], long, int, double, char[]);
    //M�todos de instancia:
    char * getRegion ();
    void setRegion (char[]);
    //Los m�todos redefinidos deben ser declarados en la clase correspondiente
    virtual double getSalario();
};

#endif // EMPLEADODISTRIBUCION_H_INCLUDED
