#ifndef CRECTANGULO_H
#define CRECTANGULO_H
#include "CFigura.h"

class CRectangulo : public CFigura
{
    public:
        ///Constructor
        CRectangulo();

        ///Destructor
        virtual ~CRectangulo();

        ///Getters y setters
        float getArea();
        void setArea(float);
        float getPerimetro();
        void setPerimetro(float);

        ///Metodos propios de la clase CRectangulo
        virtual float calcularPerimetro();
        virtual float calcularArea();
        void imprimir(ostream& co = cout);

    protected:

    private:
        float area;
        float perimetro;
};

#endif // CRECTANGULO_H
