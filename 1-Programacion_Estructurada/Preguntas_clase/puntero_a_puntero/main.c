#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    int valor = 5;
    int **pDoble; //Puntero a puntero.
    int mat [3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

    pDoble = (int**)malloc(3*sizeof(int*)); // La "matriz" va a estar guardada en el heap en memoria. En este caso es 0x252c60
    *(pDoble + 0) = (int*)&mat[0]; //Esta guardado en el stack, ya que mat esta guardado en el stack. Es decir, es un puntero a un puntero que apunto a una posicion de memoria que esta en el stack.
     /*
     *(pDoble + 0) es equivalente a escribir *pDoble[0] = &mat[0], ya que sabe que el primer puntero seria un vector de otros punteros, donde la primera posicion es el primer puntero.

     */
     *(pDoble + 1) = (int*)&mat[1]; //mat[1] seria fila = 1, que es lo mismo que *(pDoble + 1) ya que es el primer puntero, que seria de las "filas" y arranca en la primera posicion que es el 4.
     *(pDoble + 2) = (int*)&mat[2];

     valor = *(*(pDoble + 1) + 2); // 4 + 2 = 6. El 4 es como dije anteriormente la primera posicion de la fila 1, arranca de ahi.

     printf("Valor es igual a: %i", valor);
     /*
     Deberia ser igual a 6, ya que *(pDoble + 1) seria la segunda fila, la cual le asigna el elemento 1 de la "columna", que en este caso la columna seria el segundo puntero..
     */

    //Liberar espacio reservado en memoria:

    free(pDoble);

    /*
    En este caso no hace falta liberar las filas, ya que estan almacenadas en el stack, porque la matriz estaç
    almacenada en el stack, asi que una vez que termine el programa, se eliminaran automaticamente.
    */
    for(int i = 0; i < 4; i++) //Un for recorriendo las 3 "filas" que seria el primer puntero.
    {
        free(*(pDoble + i)); //Que es lo mismo que poner *pDoble[i]
    }

    return 0;
}
