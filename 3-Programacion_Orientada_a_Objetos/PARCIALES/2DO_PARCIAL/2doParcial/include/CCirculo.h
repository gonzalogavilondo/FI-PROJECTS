#ifndef CCIRCULO_H
#define CCIRCULO_H
#include "CFigura.h"
#define PI 3.141592654

//Nota: El círculo se considera una figura con base = radio
//      y altura = 0.

class CCirculo : public CFigura
{
    public:
        //Constructores y Destructores
        CCirculo();
        ~CCirculo();

        //Métodos de la clase
        virtual float calcularArea();
        virtual float calcularPerimetro();
        virtual void setFigura(istream&);
        virtual void printFigura(ostream&);
};

#endif // CCIRCULO_H
