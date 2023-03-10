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

        //M�todos de CuentaCorriente
        virtual CuentaBancaria* clonar();
        virtual bool extraccion(float);

        //M�todos virtuales para usar los operadores de
        //inserci�n y extracci�n a trav�s de la clase
        //CuentaBancaria
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);

        //M�todo para mostrar una cuenta al usuario
        virtual ostream& _mostrarCuenta(ostream& co = cout);
    private:
        float topeDescubierto;

};

#endif // CUENTACORRIENTE_H
