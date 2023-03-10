#ifndef DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_REALES_H_INCLUDED

#define FILSMAX 50
#define COLSMAX 50
void mostrar_matriz (int filas, int columnas, const float matriz[COLSMAX][COLSMAX]);
void completar_matriz (int filas, int columnas, float matriz[FILSMAX][COLSMAX], char nombreMatriz);
void suma_matriz (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
void resta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
void multiplicar_matrices (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX]);
void limpiar_matriz(int filas, int columnas, float matriz[FILSMAX][COLSMAX]);
void cargar_filas_columnas(int *filas, int *columnas);
void div_escalar(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
void traspuesta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
void multiplicar_filas_matriz (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX]);
float multiplicar_escalar_matrices(int i, int j, int filas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX]);
float multiplicar_escalar_matriz (int i, int j, int filas, const float matriz_2[FILSMAX][COLSMAX]);

#endif // DECLARACIONES_FUNCIONES_REALES_H_INCLUDED
