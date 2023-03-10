#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

int main()
{
    int matriz1[FILAS][COLUMNAS] = {{0}};
    int matriz2[FILAS][COLUMNAS] = {{0}};
    int idx_fila = 0;
    int idx_columna = 0;
    int aux = 0;
    //Cargar valores de la matriz
    cargar_matriz(matriz1, idx_fila, idx_columna, 1);
    cargar_matriz(matriz2, idx_fila, idx_columna, 2);
    //Una pausa y borrado de pantalla
    system("pause");
    system("cls || clear"); //El borrado de pantalla para linux es clear.
    //Procesar la matriz
    procesar_matriz(matriz1, matriz2, idx_fila, idx_columna, aux);
    //Mostrar resultados
    mostrar_resultados((const int (*)[COLUMNAS])matriz1, idx_fila, idx_columna, 1);
    mostrar_resultados((const int (*)[COLUMNAS])matriz2, idx_fila, idx_columna, 2);


    return 0;
}
