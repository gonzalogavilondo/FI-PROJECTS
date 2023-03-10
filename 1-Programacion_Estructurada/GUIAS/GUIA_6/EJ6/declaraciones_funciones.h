#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

void completar_matriz (int filas, int columnas, float **matriz);
void mostrar_matriz (int filas, int columnas, float **matriz);
float **reservar_memoria(int fils, int cols);
void liberar_memoria(float **matriz, int fils);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
