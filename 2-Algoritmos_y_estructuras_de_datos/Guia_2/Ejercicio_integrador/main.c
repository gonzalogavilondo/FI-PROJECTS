#include "declaraciones.h"
/*
En una empresa de comunicaciones cuentan con un generador de “headers” para un protocolo
de comunicaciones. Las cabeceras son generadas a partir de matrices cuadradas que tienen un
total de 36 valores dados para coordenadas específicas i,j. Sólo aquellas matrices en las que se
tiene valor cero para los elementos de coordenadas i>j, son las aceptadas para obtener un
“header”.
Para que dos dispositivos pueden iniciar comunicación deben verificar que sus “headers”
tengan 3 elementos iguales en la misma posición cuando están ordenados. Por cuestiones de
seguridad cada dispositivo tiene el header desordenado.
Realizar un algoritmo que verifique la compatibilidad de dos dispositivos cuyos valores de
coincidencia son 1, 7, 23.

*/
int main()
{
    //Declarar las dos matrices triangulares con valores genericos.
    int A[FILS][COLS] = {{1, 8, 2, 3, 4, 24},{0, 14, 10, 11, 12, 13},{0, 0, 7, 15, 16, 17},{0, 0, 0, 18, 27, 20},{0, 0, 0, 0, 21, 31},{0, 0, 0, 0, 0, 23}};
    int B[FILS][COLS] = {{10, 12, 7, 4, 1, 8},{0, 9, 11, 5, 20, 14},{0, 0, 17, 2, 18, 19},{0, 0, 0, 23, 29, 13},{0, 0, 0, 0, 30, 28},{0, 0, 0, 0, 0, 16}};
    int A_vec[LONGMAX] = {0};
    int B_vec[LONGMAX] = {0};
    int condicion[3] = {1, 7, 23};
    int posicion[3] = {0};


    //Verificar si las matrices son triangulares.
    verificar_matriz(A, 'A');
    verificar_matriz(B, 'B');

    //Mapear las matrices
    mapear_matriz(A, A_vec);
    mapear_matriz(B, B_vec);

    //Ordenar los vectores con el metodo de insercion
    OrdInsercion(A_vec);
    OrdInsercion(B_vec);

    //Verificar la coincidencia de los 3 elementos(1,7,23) mediante una busqueda secuencial
    busqueda_secuencial(A_vec, B_vec, condicion, posicion);

    //Imprimir resultados
    printf("-VECTOR A ORDENADO-\n\n");
    imprimir_vector(A_vec);
    printf("-VECTOR B ORDENADO-\n\n");
    imprimir_vector(B_vec);
    imprimir(posicion, condicion);

    return 0;
}
/******************************************************************************************************
EXPLICACION DE VARIAS COSAS HECHAS

Declaramos las matrices(headers) que vamos a utilizar y comparar. Sabemos que por el enunciado
las matrices son de 6x6, por ese motivo lo haremos de forma estatica ya que sabemos la cantidad
de memoria que vamos a requerir.
Las posiciones en las cuales los elementos de la matriz valen '0' es cuando i>j, es decir estamos
frente a una matriz triangular superior.

      j
   i  0 1 2 3 4 5
   0| a b c d e f |
   1| 0 g h i j k |
   2| 0 0 l m n ñ |
   3| 0 0 0 o p q |
   4| 0 0 0 0 r s |
   5| 0 0 0 0 0 t |

Luego, para declarar el vector:

En general, si la matriz es de nxn, se requieren n2 posiciones de memoria para guardar la matriz completa,
pero solamente 1+2+3+...+n = n(n+1)/2 posiciones para guardar los datos de la matriz triangular -> 6*(6+1)/2 = 42/2 = 21 lugares.
Por eso, LONGMAX = 21.

*******************************************************************************************************/
