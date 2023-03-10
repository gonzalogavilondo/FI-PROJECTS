#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int, int, int);

        //Setters y getters
        int getDay();
        void setDay(int);
        int getMonth();
        void setMonth(int);
        int getYear();
        void setYear(int);
        int getFecha();
        void setFecha(int, int, int);

        //Funciones

        friend istream& operator >> (istream&, Fecha&);
        friend ostream& operator << (ostream&, Fecha&);

        void ingresarFecha();
        void imprimir_la();
        void imprimir_us();
        void imprimir_letras();
        char* mesLetras();
        bool validarFecha();
    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // FECHA_H
