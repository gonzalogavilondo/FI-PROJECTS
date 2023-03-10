#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <declaraciones_funciones.h>

int main()
{
    int *vec = NULL;
    int cant_elementos = 0;

    printf("Digite el numero de elementos: ");
    scanf("%i", &cant_elementos);
    vec = reservar_memoria(cant_elementos);
    completar_vector(vec, cant_elementos);
    printf("\t-ORDENAMIENTO DEL VECTOR-\n");
    ordenar_vector(vec, cant_elementos);
    printf("\n\nFORMA ASCENDENTE\n\n");
    imprimir_vector(vec, cant_elementos);
    printf("\n\nFORMA DESCENDENTE\n\n");
    imprimir_descendente(vec, cant_elementos);
    //Liberamos memoria:
    free(vec);

    return 0;
}
