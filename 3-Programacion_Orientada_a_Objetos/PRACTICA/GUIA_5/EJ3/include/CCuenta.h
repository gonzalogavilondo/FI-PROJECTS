#ifndef CCUENTA_H
#define CCUENTA_H
#include <iostream>
#include <string.h>

using namespace std;

class CCuenta
{
    public:
        ///Constructor
        CCuenta(int _numero = 0, double _saldo = 0.0, double _porcentajeDeInteres = 0.0);

        ///Constructor virtual
        virtual CCuenta* Nuevo() = 0;

        ///Constructor de copia virtual
        virtual CCuenta* Clonar() = 0;

        ///Destructor
        virtual ~CCuenta();

        ///Setters
        bool SetNumero(int); //Almacena el número de la cuenta. Retorna false si la cuenta es una cadena vacía, y true en otro caso.
        void SetSaldo(double); //Almacena el saldo de la cuenta
        bool SetTipoDeInteres(double);

        ///Getters
        int GetNumero();
        double GetSaldo();
        double GetTipoDeInteres();

        ///Sobrecarga de operadores
        CCuenta& operator= (const CCuenta&);
        friend ostream& operator<< (ostream&, const CCuenta&);

        ///Metodos propios de la clase CCuenta
        bool Ingreso(double); //Es un método que tiene un parámetro cantidad de tipo
                              //double que añade la cantidad especificada al saldo actual
                              //de la cuenta. Retorna false si la cantidad es negativa, y true en otro caso.

        virtual void Reintegro(double) = 0; //Es un método que tiene que ser redefinido en cada clase, ya que el tipo de extraccion
                                            //de cuenta de ahorro con una cuenta corriente son diferentes, una tiene un tope de giro y otra no.

        virtual double Comisiones() = 0;
        virtual double Intereses() = 0;

        virtual void print(ostream&)const = 0; //Metodo para poder imprimir de acuerdo al objeto referenciado.


    protected:
        int numero;
        double saldo;
        double porcentajeDeInteres; //Es el porcentaje de interes que se le agrega al saldo que tiene en ese momento por tener la plata en el banco

    private:
};

#endif // CCUENTA_H
