#include "declaraciones.h"
/*
El valor de la función potencia x^n, se puede definir recursivamente como: x^n=1 si n = 0.
x^n=x*x^(n-1) si n >=1.
Implementar una función potencia que calcule recursivamente el valor x^n donde los
parámetros de entrada son x y n.

*/
int main()
{
    int x, n, resultado;

    //Pedimos los datos al usuario
    printf("Ingrese el valor a elevar: ");
    scanf("%d", &x);
    printf("Ingrese la potencia a la cual va a elevar: ");
    scanf("%d", &n);

    //Llamamos a la funcion potencia
    resultado = funcion_potencia(x, n);

    //Imprimimos resultado
    printf("El resultado de %d a la %d es: %d", x, n, resultado);

    return 0;
}
