#ifndef CCUENTACORRIENTE_H
#define CCUENTACORRIENTE_H
#include "CCuenta.h"
#include "CFecha.h"

class CCuentaCorriente : public CCuenta
{
    public:
        ///Constructor
        CCuentaCorriente(int _numero = 0, double _saldo = 0.0, double _porcentajeDeInteres = 0.0,
                         double _cuotaMantenimiento = 0.0, double _topeGire = 0.0); //Constructor con todos los parametros, los de la clase base y luego el de esta clase.

        ///Constructor virtual
        CCuentaCorriente* Nuevo();

        ///Constructor de copia virtual
        CCuentaCorriente* Clonar();

        ///Destructor
        virtual ~CCuentaCorriente();

        ///Setters
        bool SetCuotaMantenimiento(double); //Establece la cuota de mantenimiento de la cuenta.
                                            //Retorna false si la cantidad es negativa, y true en otro caso.
        bool SetTopeGire(double);

        ///Getters
        double GetCuotaMantenimiento(); //Devuelve la cuota de mantenimiento de la cuenta.
        double GetTopeGire();

        ///Sobrecarga de operadores
        CCuentaCorriente& operator= (const CCuentaCorriente&);
        friend ostream& operator<< (ostream&, const CCuentaCorriente&);

        ///Metodos de la propia clase CCuentaCorriente
        void Reintegro(double); //Metodo que tengo que redefinir para una caja de ahorro.

        double Comisiones(); //Método que se ejecuta los días 1 de cada mes para cobrar el
                            //importe correspondiente al mantenimiento de la cuenta.

        double Intereses(); //Método que permite calcular el importe correspondiente a
                            //los intereses/mes producidos, los cuales serán abonados los
                            //días 1 de cada mes.

        void print(ostream&) const; //Metodo polimorfico para imprimir


    protected:

    private:
        double cuotaMantenimiento;
        double topeGire;
};

#endif // CCUENTACORRIENTE_H
