#include "declaraciones.h"

int main()
{
    //Declaramos el vector y demas variables a utilizar
    int *vector = NULL;
    int *mult5 = NULL;  //Donde vamos a guardar los numeros que sean multiplos de 5

    int cnt_elementos = 0;
    int cnt_mult5 = 0;

    //Le pedimos al usuario la cantidad de elementos del vector
    printf("Ingrese la cantidad de elementos del vector: ");
    scanf("%d", &cnt_elementos);
    system("pause");
    system("cls|| clear");

    //Reservamos memoria
    vector = reservar_memoria(cnt_elementos);
    mult5 = reservar_memoria(cnt_elementos); //Vamos a asignar memoria como si todos fuesen multiplos de 5, luego vamos a reallocar la memoria que vamos a utilizar.

    //Cargamos el vector
    completar_vector(vector, cnt_elementos);

    //Ordenamos el vector
    ordenar_vector(vector, cnt_elementos);

    //Nos devuelve cuantos numeros son multiplos de 5 y en un vector mult5.
    cnt_mult5 = multiplo_5(vector, mult5, cnt_elementos);

    //Reallocamos memoria
    reallocar_memoria(mult5, cnt_mult5);

    //Imprimimos los resultados
    printf("Los valores multiplos de 5 del vector ingresado son: \n");
    imprimir_vector(mult5, cnt_mult5);

    //Liberamos memoria
    free(vector);
    free(mult5);

    return 0;
}
