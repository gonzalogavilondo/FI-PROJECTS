#include "declaraciones.h"
/*
Calcular la suma de los n primeros números naturales de forma recursiva y no recursiva,
siendo n un parámetro ingresado por el usuario.
*/
int main()
{
    int n = 0;
    int suma_nr = 0;
    int suma_r = 0;

    //Pedir la cantidad de numeros naturales
    printf("Ingrese la cantidad de numeros naturales que quiere sumar: ");
    scanf("%d", &n);

    //Llamar a las funciones suma recursiva y no recursiva.
    suma_nr = add_nr(n);
    suma_r = add_r(n);

    //Imprimir resultados
    printf("\nSuma no recursiva de los %d primeros numeros naturales: %d\n", n, suma_nr);
    printf("\nSuma recursiva de los %d primeros numeros naturales: %d", n, suma_r);

    return 0;
}
