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

        //Sobrecarga de los operadores de extracci�n e inserci�n
        friend istream& operator >> (istream&, CFigura&);
        friend ostream& operator << (ostream&, CFigura&);

        //M�todos virtuales
        virtual float calcularArea() = 0;
        virtual float calcularPerimetro() = 0;

        //M�todos virtuales llamados en la sobrecarga de los
        //operadores de extracci�n e inserci�n. Queda preparado
        //en caso de que hayan m�s atributos en cada figura.
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
