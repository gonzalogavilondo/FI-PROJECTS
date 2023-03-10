#ifndef POLAR_H
#define POLAR_H

#include <iostream>
using namespace std;

#include "complejos.h"
#include "math.h"
#include "fstream"

class polar : public complejo
{
    public:

        ///Constructores
        polar();                                    //Constructor
        polar(complejo&);                           //Constructor de copia
        polar(float, float, bool modo = false);     //Constructor sobrecargado
                                                    //modo = false se le pasa real e imaginaria
                                                    //     = true se le pasa modulo y fase


        ///Getters y setters
        float GetModulo();
        void SetModulo(float);
        float GetFase();
        void SetFase(float);

        ///Funciones para calcular: Modulo y Fase
        float CalModulo(complejo&);
        float CalFase(complejo&);

        ///Funciones para pasar a forma: Polar y Rectangular
        void ToRect();
        void ToPolar();

        ///Sobrecarga del operador de insercion
        friend ostream& operator<< (ostream&, const polar&);

        ///Sobrecarga de operadoradores aritmeticos
        polar operator+ (const polar&);
        polar operator- (const polar&);
        polar operator* (const polar&);
        polar operator/ (const polar&);
        polar friend operator* (double, const polar&);
        double friend operator* (const polar&, const polar&);

        polar& operator+= (polar&);
        polar& operator*= (double);

        ///Sobrecarga del operador de extraccion
        //No hace falta porque sabe como hacer todas las comparaciones, hasta la asignacion.

    protected:

    private:
        float modulo;
        float fase;
};

#endif // POLAR_H
