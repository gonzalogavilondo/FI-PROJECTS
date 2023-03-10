//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_FECHA_H
#define EJ4_FECHA_H

#include <iostream>

using namespace std;


class Fecha {

private:
    int day;
    int month;
    int year;

public:
    ///Constructores
    Fecha(int, int, int y = 2021); //Constructor que inicializa con el año 2021
    Fecha(); //Constructor que inicializa con la fecha de hoy

    ///Sobrecarga de operadores
    friend ostream& operator<< (ostream&, Fecha&);
    friend istream& operator>> (istream&, Fecha&);

    ///Getters y setters
    int getDay() const;
    void setDay(int);
    int getMonth() const;
    void setMonth(int);
    int getYear() const;
    void setYear(int);

};


#endif //EJ4_FECHA_H
