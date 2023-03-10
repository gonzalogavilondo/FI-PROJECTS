#include <iostream>
#include "Vehiculo.h"
#include <stdio.h>
#include <locale.h>

using namespace std;

void intercambiar(int*, int*);
void intercambiar(int* a, int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void intercambiarcpp(int&, int&);
void intercambiarcpp(int& a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}


int main()
{
    setlocale(LC_ALL, "spanish");
    // Puntero y referencias
    int x, *p;
    p = &x;
    *p = 5;
    printf("El valor de x es: %d \n", x);

    int &r = x;
    r = 6;
    printf("El valor de x nuevo es: %d \n", x);

    int a = 5;
    int b = 2;
    intercambiar(&a ,&b);
    printf("El valor de a es %d y el valor de b es %d \n", a, b);

    intercambiarcpp(a,b);
    printf("El valor original de a es %d y el valor original de b es %d \n", a, b);
    // Conversion de tipos
    float s;
    s = (float)a /b;
    printf("%.1f \n", s);
    s = float(a)/b;
    cout << s << endl;

    // Objeto por referencia, en heap
    Vehiculo* unAuto = new Vehiculo("Chevrolet", 4, 105900, 1.6);
    unAuto->acelerar();
    printf("%.2f \n", unAuto->valor_patente);

    // Objeto por valor, en stack
    Vehiculo otroAuto = Vehiculo("Peugeot", 4, 115200, 1.8);
    otroAuto.acelerar();
    otroAuto.frenar();
    printf("%.2f \n", otroAuto.valor_patente);

    otroAuto.valor_patente = 1000.00;

    printf("%.2f \n", otroAuto.valor_patente);
    printf("%.2f \n", unAuto->valor_patente);


    return 0;
}
