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

        //Métodos virtuales para usar los operadores de
        //inserción y extracción a través de la clase
        //CuentaBancaria
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);

        //Método para mostrar una cuenta al usuario
        virtual ostream& _mostrarCuenta(ostream& co = cout);
    private:
        float topeDescubierto;

};

#endif // CUENTACORRIENTE_H
