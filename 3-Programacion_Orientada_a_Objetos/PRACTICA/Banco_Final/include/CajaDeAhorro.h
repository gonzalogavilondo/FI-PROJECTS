#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H
#include "CuentaBancaria.h"

class CajaDeAhorro : public CuentaBancaria
{
    public:
        //Constructores y Destructores
        CajaDeAhorro(int cantMax = 20);
        virtual ~CajaDeAhorro();

        //Setters y Getters
        void setcantMaxExtr(int);
        int getcantMaxExtr();

        //Métodos de CajaDeAhorro
        virtual CuentaBancaria* clonar();
        virtual bool extraccion(float);

        //Métodos virtuales para usar los operadores de
        //inserción y extracción a través de la clase
        //CuentaBancaria
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);

        //Método para mostrar una cuenta al usuario
        virtual ostream& _mostrarCuenta(ostream& co = cout);
    private:
        int cantMaxExtrMens;
};

#endif // CAJADEAHORRO_H
