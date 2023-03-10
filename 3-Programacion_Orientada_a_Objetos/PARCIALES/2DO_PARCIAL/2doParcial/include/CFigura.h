#ifndef CFIGURA_H
#define CFIGURA_H
#include <iostream>
#include <math.h>
#include "CColor.h"
enum tipoFigura{
    NINGUNA, CIRCULO, RECTANGULO, TRIANGULO
};

class CFigura
{
    public:
        //Constructores y Destructores
        CFigura();
        virtual ~CFigura();

        //Setters y Getters
        tipoFigura strToTipo (string strTipo);
        void setTipo(string);
        void setForeColor(CColor);
        void setBackColor(CColor);
        void setBase(float);
        void setAltura(float);

        string getTipo();
        CColor getForeColor();
        CColor getBackColor();
        float getBase();
        float getAltura();

        //Sobrecarga de los operadores de extracción e inserción
        friend istream& operator >> (istream&, CFigura&);
        friend ostream& operator << (ostream&, CFigura&);

        //Métodos virtuales
        virtual float calcularArea() = 0;
        virtual float calcularPerimetro() = 0;

        //Métodos virtuales llamados en la sobrecarga de los
        //operadores de extracción e inserción. Queda preparado
        //en caso de que hayan más atributos en cada figura.
        virtual void setFigura(istream&) = 0;
        virtual void printFigura(ostream&) = 0;

    protected:
        tipoFigura tipo;
        CColor foreColor;
        CColor backColor;
        float base;
        float altura;
};

#endif // CFIGURA_H
