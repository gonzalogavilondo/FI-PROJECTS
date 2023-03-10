//
// Created by Gonza on 22/11/2021.
//

#include "Fecha.h"
#include <ctime>

/**
* Constructores
*/
Fecha::Fecha() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);
}

Fecha::Fecha(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/**
* Sobrecarga de operadores
*/
ostream& operator<< (ostream& co, Fecha& fe) {
    co << fe.day   << '/'
       << fe.month << '/'
       << fe.year;

    return co;
}

istream& operator>> (istream& ci, Fecha& f) {
    string dd;
    string mm;
    string yy;
    getline(ci, dd, '/' );
    getline(ci, mm, '/' );
    getline(ci, yy);

    f.day = stoi(dd);
    f.month = stoi(mm);
    f.year = stoi(yy);

    return ci;
}

/**
* Getters y setters
*/
int Fecha::getDay() const {
    return day;
}

void Fecha::setDay(int val) {
    day = val;
}

int Fecha::getMonth() const {
    return month;
}

void Fecha::setMonth(int val) {
    month = val;
}

int Fecha::getYear() const {
    return year;
}

void Fecha::setYear(int val) {
    year = val;
}
