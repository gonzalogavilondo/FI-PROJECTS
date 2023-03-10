#ifndef CCIRCULO_H
#define CCIRCULO_H
#include "CFigura.h"
#define PI 3.141592654


class CCirculo : public CFigura
{
    public:
        ///Constructor
        CCirculo();

        ///Destructor
        ~CCirculo();

        ///Metodos propios de la clase
        virtual float calcularArea();
        virtual float calcularPerimetro();
        virtual void setFigura(istream&);
        virtual void printFigura(ostream&);
};

#endif // CCIRCULO_H
