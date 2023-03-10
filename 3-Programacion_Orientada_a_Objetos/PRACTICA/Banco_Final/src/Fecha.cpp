#include "Fecha.h"
#include <ctime>
#include <string>
#include <string.h>

Fecha::Fecha(){
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);  // No hace falta validar porque es la fecha actual
}

Fecha::Fecha(int dd, int mm, int yy){
    day = dd;
    month = mm;
    year = yy;
}

int Fecha::getDay(){
     return day;
}

void Fecha::setDay(int val){
    if(val >= 1 && val <= 31){
        day = val;
    } else {
        cout << "Ingreso un dia incorrecto" << endl;
        exit(1);
    }
}

int Fecha::getMonth(){
    return month;
}

void Fecha::setMonth(int val){
    if(val >= 1 && val <= 12){
        month = val;
    } else {
        cout << "Ingreso un mes incorrecto" << endl;
        exit(2);
    }
}

int Fecha::getYear(){
     return year;
}

void Fecha::setYear(int val){
     if(val >= 1 && val <= 2021){
        year = val;
    } else {
        cout << "Ingreso un anio incorrecto" << endl;
        exit(3);
    }
}

void Fecha::setFecha(int in_day, int in_month, int in_year){
    setDay(in_day);
    setMonth(in_month);
    setYear(in_year);
    validarFecha();
}


istream& operator >> (istream& ci, Fecha& f){
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

ostream& operator << (ostream& co, Fecha& f){
    co << f.day << "/" << f.month << "/" << f.year;

    return co;
}

void Fecha::ingresarFecha(){
    cout << "Ingrese Fecha" << endl;
    cout << "Dia: ";
    cin >> day;
    cout << "Mes: ";
    cin >> month;
    cout << "Anio: ";
    cin >> year;
}

void Fecha::imprimir_la(){
    cout << "La fecha en LA es: " << day
    << "/" << month << "/" << year << endl;
}

void Fecha::imprimir_us(){
    cout << "La fecha en US es: " << month
    << "/" << day << "/" << year << endl;
}

void Fecha::imprimir_letras(){

}

char *Fecha::mesLetras(){
    string arrayMeses[] = {
            "Enero",
            "Febrero",
            "Marzo",
            "Abril",
            "Mayo",
            "Junio",
            "Julio",
            "Agosto",
            "Septiembre",
            "Octubre",
            "Noviembre",
            "Diciembre"
    };
    char *name = new char();
    strcpy(name, (arrayMeses[month-1]).c_str());
    return name;
}

bool Fecha::validarFecha(){
    return true;
}
