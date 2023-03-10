#ifndef CCIRCULO_H
#define CCIRCULO_H
#include "CFigura.h"
#define PI  3.1415927

class CCirculo : public CFigura
{
    public:
        ///Constructor
        CCirculo();

        ///Destructor
        virtual ~CCirculo();

        ///Getters y setters
        float getRadio(); //EL RADIO SERIA LA "BASE"
        void setRadio(float);
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

#endif // CCIRCULO_H
