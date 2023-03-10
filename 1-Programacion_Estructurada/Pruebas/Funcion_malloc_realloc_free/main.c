#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * vec_a = NULL; /*Declaro un puntero donde su o sus datos(vector) van a ser de tipo entero
                        y lo inicializo con la posicion de memoria NULL.
                        */
    int * vec_a_6 = NULL; //Otro vector para reallocar en vez de 4, 6 lugares.
    //Asigno bloque de 4 ints.
    vec_a = (int *)malloc(4*sizeof(int));

    /*Estoy casteando el malloc ya que el puntero no es de tipo generico
    (void *vec_a) donde si deberia poner vec_a = malloc(4*sizeof(int));
    pero como es de tipo entero, debo hacer el casteo correspondiente.
    lo que hago aca basicamente es inicializar el puntero con una direccion
    de memoria que me asigne el S.O donde pueda haber la cantidad de memoria
    que yo le pido, en este caso 4 elementos de 4 bytes = 16 bytes, donde haya
    un lugar con 16 bytes disponibles, el vec_a va se va a inicializar en esa direccion de memoria.
    */

    //Condicion de si se inicializo el puntero con una direccion de memoria que tenga los bytes pedidos.
    if(vec_a == NULL)
    {
        printf("La memoria esta llena.\n");
    }
    else
    {
        printf("Se asigno lo requerido en memoria correctamente.\n");
    }

    //Inicializo los elementos
    vec_a[0] = 1;
    vec_a[1] = 2;
    vec_a[2] = 3;
    vec_a[3] = 4;

    //Supongamos que ahora en vez de 4, quiero 6 lugares.

    vec_a_6 = realloc(vec_a, 6*sizeof(int));  //Tengo que guardarlos en algun lugar, en este caso vec_a_6

    //Condicion de si se inicializo el puntero con una direccion de memoria que tenga los bytes pedidos.
    if(vec_a_6 == NULL)
    {
        printf("La memoria esta llena.\n");
    }
    else
    {
        printf("Se asigno lo requerido en memoria correctamente.\n");
    }
    printf("El nuevo vector en el elemento [3]: %d\n", vec_a_6[3]); //Deberia ser 4, ya que inicialice vec_a[3] = 4
    printf("El nuevo vector en el elemento [4]: %d\n", vec_a_6[4]); //Basura, ya que en la posicion contigua no hay ninguna variable declarada, si yo declaro una variable luego del vector de 4 elementos, seguramente va a tener ese valor.

    // Entonces lo que puedo hacer, es asignar en las posiciones 4,5 ya que reserve espacio.

    vec_a_6[4] = 5;
    vec_a_6[5] = 6;
    printf("El nuevo vector en el elemento [4]: %d\n", vec_a_6[4]);
    printf("El nuevo vector en el elemento [5]: %d\n", vec_a_6[5]);

    /*Una vez termine de utilizar todo el programa, el usuario es el responsable de la asignacion de memoria dinamica
      entonces, tenemos que liberar la memoria requerida.
    */

    //Liberamos memoria utilizada:

    free(vec_a);
    free(vec_a_6);

    return 0;
}
