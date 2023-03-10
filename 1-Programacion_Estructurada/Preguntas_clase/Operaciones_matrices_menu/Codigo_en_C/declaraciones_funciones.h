#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

void cargar_filas_columnas(int *filas, int *columnas);
void mostrar_matriz (int filas, int columnas, const float matriz[COLSMAX][COLSMAX]);
void completar_matriz (int filas, int columnas, float matriz[FILSMAX][COLSMAX], char nombreMatriz);
void inicializar_matriz(int filas, int columnas, float matriz[FILSMAX][COLSMAX]);
void condicion_opcion(int opcion, int *filas1, int *columnas1, int *filas2, int *columnas2);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
