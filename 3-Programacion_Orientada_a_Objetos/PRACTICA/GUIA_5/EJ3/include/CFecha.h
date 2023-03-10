#ifndef CFECHA_H
#define CFECHA_H
#include <iostream>

using namespace std;


class CFecha
{
    public:
        ///Constructores
        CFecha(int, int, int a = 2021); // Constructor que inicializa con el año 2021 por default.
        CFecha(); //Constructor que iniciala con la fecha de hoy.

        ///Sobrecarga del operador de insercion
        friend ostream& operator << (ostream&, CFecha&);

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

#endif // CFECHA_H
