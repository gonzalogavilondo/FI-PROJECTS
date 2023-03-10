#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
using namespace std;

#include "math.h"
class Circulo
{
    public:
        ///Constructor
        Circulo(float initRadio = 0.5); //Constructor por defecto

        ///Destructor
        ~Circulo();

        ///Getters y Setters
        float GetRadio();
        void SetRadio(float);

        ///Sobrecargamos el operador de insercion
        friend ostream& operator<< (ostream&, const Circulo&);

        ///Funciones de Circulo
        float area() const;

    protected:
        float radio;

    private:
};

#endif // CIRCULO_H
