#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "spanish");
    int anio = 0;
    printf("Escriba un a�o: ");
    scanf("%i", &anio);
    if ((anio%100 != 0) && (anio%400 != 0) && (anio%4 == 0))
    {
        printf("El a�o %i es bisiesto.", anio);
    }
    else
    {
        printf("El a�o %i no es bisiesto.", anio);
    }
    return 0;
}
