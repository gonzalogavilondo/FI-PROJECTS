#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"

class estudiante : public persona
{
    public:

        ///Constructores
        estudiante(); //Constructor
        estudiante(string, unsigned, fecha,
                   string, fecha, int, float); //Constructor sobrecargado
        estudiante(string, unsigned, int, int, int,
                   string, int, int, int, int, float); //Constructor sobrecargado

        ///Destructor
        ~estudiante();

        ///Setters

        //Setters de la clase persona, de igual manera, si no estuviesen anda igual el programa, ya que primero va al constructor base
        //El problema es con becario, que no sabe por donde subir, si por empleado o estudiante para llegar a la clase persona
        void SetName(string);
        void SetDocument(unsigned);
        void SetBirthDate(fecha);
        void SetBirthDate(int, int, int);

        //Setters de la propia clase estudiante
        void SetCarrera(string);
        void SetIngreso(fecha);
        void SetIngreso(int, int, int);
        void SetMaterias(int);
        void SetPromedio(float);

        ///Getters
        string GetCarrera();
        fecha& GetFechaIngreso(); //Devuelve una referencia asi puedo devolver en las funciones print y VPrint
                                  //una referencia para sobrecargar al operador de insercion en la fecha.
        int GetMaterias();
        float GetPromedio();

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, const estudiante&);

    private:
    protected:
        string Carrera;
        fecha FechaIngreso;
        int Materias;
        float Promedio;
};

///Forma de imprimir sin sobrecargar
void vPrint(estudiante &);

#endif // ESTUDIANTE_H
