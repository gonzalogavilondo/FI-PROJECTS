#ifndef CUENTAUNIVERSITARIA_H
#define CUENTAUNIVERSITARIA_H
#include "CuentaBancaria.h"
#include "Reloj.h"

class CuentaUniversitaria : public CuentaBancaria
{
    public:
        //Constructores y Destructores
        CuentaUniversitaria(float topeExtr = 100);
        virtual ~CuentaUniversitaria();

        //Setters y Getters
        void setTopeExtrDiaria(float);
        void setExtrRestante(float);
        float getTopeExtrDiaria();
        float getExtrRestante();

        //Métodos de CajaDeAhorro
        virtual CuentaBancaria* clonar();
        virtual bool extraccion(float);

        //Métodos virtuales para usar los operadores de
        //inserción y extracción a través de la clase
        //CuentaBancaria
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);

        //Método para mostrar una cuenta al usuario
        virtual ostream& _mostrarCuenta(ostream& co = cout);

        //Metodo para saber a la hora que sucedio la ultima extraccion
        bool limiteDiario();

    private:
        float topeExtrDiaria;
        float extrRestante;
        Reloj ultimaExtraccion;
};

#endif // CUENTAUNIVERSITARIA_H
