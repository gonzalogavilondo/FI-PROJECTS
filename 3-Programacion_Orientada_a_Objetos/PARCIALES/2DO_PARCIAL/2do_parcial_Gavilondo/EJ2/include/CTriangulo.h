#ifndef CTRIANGULO_H
#define CTRIANGULO_H

#include "CFigura.h"

class CTriangulo : public CFigura
{
    public:
        ///Constructor
        CTriangulo();

        ///Destructor
        virtual ~CTriangulo();

        ///Getters y setters
        float getArea();
        void setArea(float);
        float getPerimetro();
        void setPerimetro(float);

        ///Metodos propios de la clase CTriangulo
        virtual float calcularPerimetro();
        virtual float calcularArea();
        void imprimir(ostream& co = cout);

    protected:

    private:
        float area;
        float perimetro;
};

#endif // CTRIANGULO_H
