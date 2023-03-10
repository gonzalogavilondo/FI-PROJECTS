#ifndef CFIGURA_H
#define CFIGURA_H

#include "CColor.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum tipoDeFigura
{
    Rectangulo = 0, Circulo = 1, Triangulo = 2
};

class CFigura
{
    public:
        ///Constructor
        CFigura();

        ///Destructor
        virtual ~CFigura();

        ///Getters y setters
        CColor getFore_color();
        void setFore_color(CColor);
        CColor getBack_color();
        void setBack_color(CColor);
        tipoDeFigura getTipoDeFigura();
        void setTipoDeFigura(tipoDeFigura);
        float getBase();
        void setBase(float);
        float getAltura();
        void setAltura(float);

        ///Metodos propios de la clase CFigura
        virtual float calcularPerimetro() = 0;
        virtual float calcularArea() = 0;
        void imprimir(ostream& co = cout);

    protected:
        CColor fore_color;
        CColor back_color;
        float base;
        float altura;
        tipoDeFigura tipo;

};

#endif // CFIGURA_H
