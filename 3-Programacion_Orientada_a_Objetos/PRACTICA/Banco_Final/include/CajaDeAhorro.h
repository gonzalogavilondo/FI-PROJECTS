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

        //M�todos de CajaDeAhorro
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
        int cantMaxExtrMens;
};

#endif // CAJADEAHORRO_H
