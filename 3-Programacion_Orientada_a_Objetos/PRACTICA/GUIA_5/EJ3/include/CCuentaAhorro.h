#ifndef CCUENTAAHORRO_H
#define CCUENTAAHORRO_H
#include "CCuenta.h"
#include "CFecha.h"
#define MAXEXT 10

class CCuentaAhorro : public CCuenta
{
    public:
        ///Constructor
        CCuentaAhorro(int _numero = 0, double _saldo = 0.0, double _porcentajeDeInteres = 0.0,
                      double _importePorTrans = 0.0, int _transExentas = 0);

        ///Constructor virtual
        CCuentaAhorro* Nuevo();

        ///Constructor de copia virtual
        CCuentaAhorro* Clonar();

        ///Destructor
        virtual ~CCuentaAhorro();

        ///Setters
        bool SetTransacciones(int);
        bool SetImportePorTrans(double); //Establece el importe por transacción. Retorna false si
                                         //el importe es negativo, y true en otro caso
        bool SetTransExentas(int); //Establece el número de transacciones exentas (gratuitas). Retorna false si el número de transacciones es negativo, y
                                   //true en otro caso.

        ///Getters
        int GetTransacciones();
        double GetImportePorTrans();
        int GetTransExentas();

        ///Sobrecarga de operadores
        CCuentaAhorro& operator= (const CCuentaAhorro&);
        friend ostream& operator<< (ostream&, const CCuentaAhorro&);

        ///Metodos propios de la clase CCuentaAhorro
        void DecrementarTransacciones(); // Decrementa en 1 el número de transacciones
        void Ingreso(double);
        void Reintegro(double);
        double Comisiones();
        double Intereses();
        void print(ostream&) const; //Metodo polimorfico para imprimir


    protected:

    private:
        int transacciones;
        double importePorTrans;
        int transExentas;
        int cntExtracciones;
};

#endif // CCUENTAAHORRO_H
