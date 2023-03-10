#ifndef CRECTANGULO_H
#define CRECTANGULO_H
#include "CFigura.h"

class CRectangulo : public CFigura
{
    public:
        CRectangulo();
        ~CRectangulo();

        //Métodos de la clase
        virtual float calcularArea();
        virtual float calcularPerimetro();
        virtual void setFigura(istream&);
        virtual void printFigura(ostream&);

    private:
};

#endif // CRECTANGULO_H
