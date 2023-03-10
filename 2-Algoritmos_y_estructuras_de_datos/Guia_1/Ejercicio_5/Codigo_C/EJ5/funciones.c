#include "declaraciones.h"

void cant_suma(void)
{
    char respuesta;
    int contador = 0;
    int res = 0;
    int num[MAXNUM]; //Lo voy a hacer estatico, hasta 20 numeros.
    int interrogacion = 168;
    char c = '0';
    c = (char)interrogacion;


    do
    {
        printf("Ingrese el numero: ");
        scanf("%i", &num[contador]);
        res += num[contador];
        contador += 1;
        printf("%cDesea ingresar otro numero entero? <s/n>: ", c);
        scanf("%s", &respuesta);

    }while(respuesta != 'n');
    system("pause");
    system("cls || clear");
    printf("La cantidad de numeros ingresados por el usuario es: %i\n", contador);
    printf("El resultado de la suma de los numeros ingresados es: %i\n", res);
}
