#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"
#include "declaraciones_funciones_reales.h"

int main()
{
    float *datos = NULL;
    float promedio = 0.0;
    int cantidad_datos = 0;
    printf("Ingrese la cantidad de datos que desea: ");
    scanf("%i", &cantidad_datos);
    datos = reservar_memoria(cantidad_datos);
    completar_vector(datos, cantidad_datos);
    promedio = calcular_promedio(datos, cantidad_datos);
    printf("-VECTOR RESULTANTE-\n\n");
    imprimir_vector(datos, cantidad_datos);
    printf("El promedio del vector es: %.2f\n", promedio);
    //Liberaramos memoria
    free(datos);

    return 0;
}
