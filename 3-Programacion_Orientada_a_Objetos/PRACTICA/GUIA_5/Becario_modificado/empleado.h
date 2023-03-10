#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"

class empleado : virtual public persona
{
    public:
        ///Constructores
        empleado();
        empleado(string, unsigned, fecha,
                 string, fecha, float); //Constructor sobrecargado
        empleado(string, unsigned, int, int, int,
                 string, int, int, int, float); //Constructor sobrecargado

        ///Destructor
        ~empleado();

        ///Setters
        void SetName(string);
        void SetDocument(unsigned);
        void SetBirthDate(fecha);
        void SetBirthDate(int, int, int);

        //Setters de la propia clase empleado
        void SetCategoria(string);
        void SetIngreso(fecha);
        void SetIngreso(int, int, int);
        void SetSueldo(float);

        ///Getters
        string GetCategoria();
        fecha& FechaGetIngreso(); //Devuelve una referencia para poder imprimir vPrint utilizando al fecha sobrecargada
        float GetSueldo();

        ///Sobrecargar el operador de insercion
        friend ostream& operator<< (ostream&, const empleado&);

    private:
    protected:
        string Categoria;
        fecha FechaIngreso;
        float Sueldo;
};

void vPrint(empleado &);

#endif // EMPLEADO_H
