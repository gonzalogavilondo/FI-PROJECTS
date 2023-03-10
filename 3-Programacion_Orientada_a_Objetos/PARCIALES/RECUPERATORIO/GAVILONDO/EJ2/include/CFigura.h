#ifndef CFIGURA_H
#define CFIGURA_H
#include <iostream>
#include <math.h>
#include "CColor.h"


class CFigura
{
    public:
        ///Constructor
        CFigura();

        ///Destructor
        virtual ~CFigura();

        ///Setters
        void setTipo(string);
        void setForeColor(CColor);
        void setBackColor(CColor);
        void setBase(float);
        void setAltura(float);

        ///Getters
        string getTipo();
        CColor getForeColor();
        CColor getBackColor();
        float getBase();
        float getAltura();

        ///Sobrecarga de operadores
        friend ostream& operator << (ostream&, CFigura&);
        friend istream& operator >> (istream&, CFigura&);

        ///Métodos virtuales llamados en la sobrecarga de los operadores
        virtual void setFigura(istream&) = 0;
        virtual void printFigura(ostream&) = 0;

        ///Métodos virtuales puros
        virtual float calcularArea() = 0;
        virtual float calcularPerimetro() = 0;


    protected:
        string tipoDeFigura;
        CColor foreColor;
        CColor backColor;
        float base;
        float altura;
};

#endif // CFIGURA_H
