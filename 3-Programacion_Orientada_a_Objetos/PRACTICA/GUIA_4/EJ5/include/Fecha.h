#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;


class Fecha
{
    public:
        ///Constructores
        Fecha(int, int, int a = 2021); // Constructor que inicializa con el año 2021 por default.
        Fecha(); //Constructor que iniciala con la fecha de hoy.

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, Fecha&);

        int GetDay();
        void SetDay(int);
        int GetMonth();
        void SetMonth(int);
        int GetYear();
        void SetYear(int);

    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // FECHA_H
