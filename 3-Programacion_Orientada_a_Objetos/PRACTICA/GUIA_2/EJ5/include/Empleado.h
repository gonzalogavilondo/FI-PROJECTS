#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Fecha.h"

class Empleado
{
    public:
        Empleado();
        Empleado(string, string, Fecha, Fecha);

        string Getnombres();
        void Setnombres(string val);
        string Getapellidos();
        void Setapellidos(string val);
        Fecha GetfechaContratacion();
        void SetfechaContratacion(Fecha val);
        Fecha GetfechaNacimiento();
        void SetfechaNacimiento(Fecha val);

        //Funciones
        void imprimir();

    protected:

    private:
        string nombres;
        string apellidos;
        Fecha fechaContratacion;
        Fecha fechaNacimiento;
};

#endif // EMPLEADO_H
