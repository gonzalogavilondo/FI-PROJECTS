#ifndef BECARIO_H
#define BECARIO_H

#include "empleado.h"
#include "estudiante.h"

class becario : public empleado, public estudiante
{
    public:
        ///Constructores
        becario();
        becario(string, unsigned, fecha,
                string, fecha, int, float,
                string, fecha, float,
                string, int, string, string);

        ///Destructor
        ~becario();

        ///Setters

        //Setters de la clase persona
        void SetName(string);
        void SetDocument(unsigned);
        void SetBirthDate(fecha);
        void SetBirthDate(int, int, int);

        //Setters de la propia clase becario
        void SetTipo(string);
        void SetDuracion(int);
        void SetLaboratorio(string);
        void SetDirector(string);

        ///Getters
        string GetTipo();
        int GetDuracion();
        string GetLaboratorio();
        string GetDirector();

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, const becario&);

    protected:
    private:
        string Tipo;
        int Duracion;
        string Laboratorio;
        string Director;
};

void vPrint(becario &);

#endif // BECARIO_H
