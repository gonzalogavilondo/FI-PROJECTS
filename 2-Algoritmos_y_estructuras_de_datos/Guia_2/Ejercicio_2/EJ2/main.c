#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //La condicion que vamos a poner es que encuentre al valor condicion (Una vez ingresado por el usuario)
    float condicion = 0.0;

    //Declaramos el vector y demas variables a utilizar
    float *vector = NULL;
    int posicion = 0;
    int cnt_elementos = 0;

    printf("Ingrese la cantidad de elementos del vector: ");
    scanf("%d", &cnt_elementos);

    //Reservo memoria para el vector
    vector = reservar_memoria(cnt_elementos);

    //Pausa y borrado de pantalla
    system("pause");
    system("cls || clear");

    //Rellenamos el vector
    completar_vector(vector, cnt_elementos);

    //Preguntamos al usuario el valor que desee encontrar
    printf("Ingrese el valor que desea encontrar: ");
    scanf("%f", &condicion);

    //Limpiamos pantalla
    system("cls || clear");

    //Llamada a funcion
    posicion = busqueda_secuencial(vector, condicion, cnt_elementos);

    //Impresion de resultados
    printf("\t\t\t-VECTOR-\n\n");
    imprimir_vector(vector, cnt_elementos);
    imprimir(posicion, condicion);

    //Liberamos memoria
    free(vector);


    return 0;
}
