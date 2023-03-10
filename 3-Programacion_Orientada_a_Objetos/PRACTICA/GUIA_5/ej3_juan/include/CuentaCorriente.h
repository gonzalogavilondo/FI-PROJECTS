#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "CuentaBancaria.h"
#include <cmath>

class CuentaCorriente : public CuentaBancaria
{
    public:
        //Constructores y Destructores
        CuentaCorriente(float topGiro = 5000);
        virtual ~CuentaCorriente();

        //Setters y Getters
        void setTopeGiro(float);
        float getTopeGiro();

        //Métodos de CuentaCorriente
        virtual CuentaBancaria* clonar();
        virtual bool extraccion(float);
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);
    private:
        float topeDescubierto;

};

#endif // CUENTACORRIENTE_H
