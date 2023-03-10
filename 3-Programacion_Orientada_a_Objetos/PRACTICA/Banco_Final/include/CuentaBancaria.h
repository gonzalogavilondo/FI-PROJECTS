#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <iostream>
#include <vector>
#include <string>
#include "Fecha.h"

using namespace std;

enum tipoDeCuenta{
    CAJADEAHORRO = 0, CUENTACORRIENTE = 1, CUENTAUNIVERSITARIA = 2
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
        void addTitular(string);

        string getCBU();
        tipoDeCuenta getTipo();
        float getSaldo();
        string getTitular(int);
        unsigned getSizeTitulares();

        //Sobrecarga del operador de extracci�n e inserci�n
        friend istream& operator >> (istream&, CuentaBancaria&);
        friend ostream& operator << (ostream&, CuentaBancaria&);

        //M�todos de la clase CuentaBancaria
        virtual CuentaBancaria* clonar() = 0;
        virtual bool extraccion(float) = 0;
        bool deposito(float);

        //M�todos virtuales llamados en la sobrecarga de los
        //operadores de extracci�n e inserci�n
        virtual void setCuenta(istream&) = 0;
        virtual void printCuenta(ostream&) = 0;

        //M�todo para mostrar una cuenta al usuario
        ostream& mostrarCuenta(ostream& co = cout);

        //M�todo para mostrar la informaci�n de las clases
        //heredadas
        virtual ostream& _mostrarCuenta(ostream& co = cout) = 0;


    protected:
        string CBU;
        tipoDeCuenta tipo;
        float saldo;
        vector<string> titulares;
    private:
};

#endif // CUENTABANCARIA_H
