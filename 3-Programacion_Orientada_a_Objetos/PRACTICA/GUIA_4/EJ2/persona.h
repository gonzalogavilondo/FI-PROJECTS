#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>

using namespace std;

class fecha
{
    public:
        int Day;
        int Month;
        int Year;

        ///Constructores
        fecha(int, int, int a = 2021); // Constructor que inicializa con el año 2021 por default.
        fecha(); //Constructor que iniciala con la fecha de hoy.

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, const fecha&);
};

class persona
{
    public:

        ///Constructor por default
        persona(string nombre = "Pedro", unsigned numero = 12345678, fecha ddmmaa = fecha());

        ///Destructor
        ~persona();

        ///Setters
        void SetName(string);
        void SetDocument(unsigned);     // retorna TRUE si el formato es correcto
        void SetBirthDate(fecha);       // chequea la validez de la fecha
        void SetBirthDate(int, int, int);       // chequea la validez de la fecha

        ///Getters
        string GetName();
        unsigned GetDocument();
        fecha& GetBirthDate();

        ///Sobrecarga del operador de insercion para persona
        friend ostream& operator << (ostream&, const persona&);

    private:
    protected:
        string Name;
        unsigned Document;
        fecha BirthDate;
};

void Print(persona &);

#endif // PERSONA_H_INCLUDED
