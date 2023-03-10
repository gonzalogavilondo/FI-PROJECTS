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
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);
    private:
        int cantMaxExtrMens;
};

#endif // CAJADEAHORRO_H
