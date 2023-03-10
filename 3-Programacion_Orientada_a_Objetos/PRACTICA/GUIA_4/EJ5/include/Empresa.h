#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string.h>
#include "Fecha.h"
#include "Temporario.h"
#include "Permanente.h"
#include "Gerente.h"

using namespace std;

class Empresa
{
    public:
        ///Constructores
        Empresa();

        ///Destructor
        ~Empresa();

        ///Getters y Setters
        string GetNombre();
        void SetNombre(string);
        Fecha GetInicioActividades();
        void SetInicioActividades(Fecha);
        int GetCntEmpleadosTemp();
        void SetCntEmpleadosTemp(int);
        int GetCntEmpleadosPerm();
        void SetCntEmpleadosPerm(int);
        int GetCntEmpleadosGer();
        void SetCntEmpleadosGer(int);

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, Empresa&);

        ///Metodos de Empresa
        float MontoTotal();
        Empleado& ContratarEmpleado(Empleado&);
        Empresa& SetEmpresa(Empresa&);

    protected:
        string nombre;
        Fecha inicioActividades;
        int cntEmpleadosTemp;
        int cntEmpleadosPerm;
        int cntEmpleadosGer;
        Temporario *temporarios;
        Permanente *permanentes;
        Gerente *gerentes;

    private:
};
#endif // EMPRESA_H
