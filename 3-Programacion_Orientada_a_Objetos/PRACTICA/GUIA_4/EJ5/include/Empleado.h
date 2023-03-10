#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string.h>
#include "Fecha.h"

class Empleado
{
    public:
        ///Constructores
        Empleado();

        ///Destructor
        ~Empleado();

        ///Getters y setters
        string GetNombre();
        void SetNombre(string);
        string GetTelefono();
        void SetTelefono(string);
        string GetMail();
        void SetCategoria(string);
        string GetCategoria();
        void SetMail(string);
        Fecha GetIngreso();
        void SetIngreso(Fecha);
        float GetSalario();
        void SetSalario(float);
        int GetCntHijos();
        void SetCntHijos(int);
        bool GetCasado();
        void SetCasado(bool);

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, Empleado&);

    protected:
        string nombre;
        string telefono;
        string mail;
        string categoria;
        Fecha ingreso;
        float salario;
        int cntHijos;
        bool casado;

    private:
};

#endif // EMPLEADO_H
