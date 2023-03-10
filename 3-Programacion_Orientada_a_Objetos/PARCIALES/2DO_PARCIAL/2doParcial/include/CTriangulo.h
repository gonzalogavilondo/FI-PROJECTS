#ifndef CTRIANGULO_H
#define CTRIANGULO_H
#include "CFigura.h"

class CTriangulo : public CFigura
{
    public:
        CTriangulo();
        ~CTriangulo();

        //Métodos de la clase
        virtual float calcularArea();
        virtual float calcularPerimetro();
        virtual void setFigura(istream&);
        virtual void printFigura(ostream&);

    private:
};

#endif // CTRIANGULO_H
