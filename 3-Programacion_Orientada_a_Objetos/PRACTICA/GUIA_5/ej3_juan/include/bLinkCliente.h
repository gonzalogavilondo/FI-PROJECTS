#ifndef BLINKCLIENTE_H
#define BLINKCLIENTE_H
#include "Cliente.h"
#include "CuentaBancaria.h"

class bLinkCliente
{
    public:
        //Constructores y Destructores
        bLinkCliente();
        bLinkCliente(Cliente&);
        bLinkCliente(const bLinkCliente&);
        ~bLinkCliente();

        //Setters y Getters
        void setCliente(Cliente&);
        Cliente& getCliente();
        vector <CuentaBancaria*> getCuentas();

        //Métodos de la clase
        void addCuentaBancaria(CuentaBancaria*);
        CuentaBancaria* getCuentaBancaria(int);

        int getSizeCuentasBancarias() const;

    private:
        Cliente cliente;
        vector <CuentaBancaria*> cuentasCliente;

};

#endif // BLINKCLIENTE_H
