#ifndef BLINKCUENTA_H
#define BLINKCUENTA_H
#include "Cliente.h"
#include "CuentaBancaria.h"

class bLinkCuenta
{
    public:
        bLinkCuenta();
        bLinkCuenta(const bLinkCuenta&);
        ~bLinkCuenta();

        void setCuenta(CuentaBancaria*);
        CuentaBancaria* getCuenta();
        vector <Cliente*> getTitulares();

        void addTitular(Cliente&);
        Cliente& getTitular(int) const;

        int getSizeTitulares() const;

    private:
        CuentaBancaria* cuenta;
        vector <Cliente*> titularesCuenta;
};

#endif // BLINKCUENTA_H
