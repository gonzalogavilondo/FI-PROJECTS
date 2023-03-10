#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define FILAS 3
#define COLUMNAS 3
void cargar_matriz (int matriz[FILAS][COLUMNAS], int idx_fil, int idx_columna, int identificador);
void procesar_matriz(int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int idx_fil, int idx_columna, int aux);
void mostrar_resultados(const int matriz[FILAS][COLUMNAS], int idx_fil, int idx_columna, int identificador);// Utilizo el modificador "const" para que la funcion impriir_matriz se encargue solo de imprimir la matriz tal como esta y no modifique nada.

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
