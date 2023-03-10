#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>
#include <string>
using namespace std;

enum tipoDeCuenta{
    CAJADEAHORRO, CUENTACORRIENTE, CUENTAUNIVERSITARIA
};

class CuentaBancaria
{
    public:
        //Constructores y Destructores
        CuentaBancaria();
        CuentaBancaria(tipoDeCuenta);
        virtual ~CuentaBancaria();

        //Setters y Getters
        void setCBU(string);
        void setTipo(tipoDeCuenta);
        void setSaldo(float);

        string getCBU();
        tipoDeCuenta getTipo();
        float getSaldo();

        //Sobrecarga del operador de extracción e inserción
        friend istream& operator >> (istream&, CuentaBancaria&);
        friend ostream& operator << (ostream&, CuentaBancaria&);

        //Métodos de la clase CuentaBancaria
        virtual CuentaBancaria* clonar() = 0;
        virtual void generadorCBU();
        virtual bool extraccion(float) = 0;
        bool deposito(float);
        virtual void setCuenta(istream&) = 0;
        virtual void printCuenta(ostream&) = 0;
    protected:
        string CBU;
        tipoDeCuenta tipo;
        float saldo;
    private:
};

#endif // CUENTABANCARIA_H
