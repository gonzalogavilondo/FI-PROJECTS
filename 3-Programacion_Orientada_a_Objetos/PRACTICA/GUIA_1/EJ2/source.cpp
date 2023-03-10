#include "header.h"

void permutarREF(int &a, int &b)     // los argumentos son referencias
{                                 // se modifican los valores de a y b
    int temp;

    temp = a;           // no hace falta utilizar
    a = b;              // el operador indirecci�n (*)
    b = temp;
}

void permutarPTR(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
