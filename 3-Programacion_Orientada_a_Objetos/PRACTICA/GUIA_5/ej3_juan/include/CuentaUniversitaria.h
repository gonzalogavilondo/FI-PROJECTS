#ifndef CUENTAUNIVERSITARIA_H
#define CUENTAUNIVERSITARIA_H
#include "CuentaBancaria.h"

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
        virtual void setCuenta(istream&);
        virtual void printCuenta(ostream&);
    private:
        float topeExtrDiaria;
        float extrRestante;
};

#endif // CUENTAUNIVERSITARIA_H
