#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

float **reservar_memoria(int fils, int cols);
void completar_matriz(float **matriz, int fils, int cols, char n_Matriz);
void imprimir_matriz(float **matriz, int fils, int cols);
void suma_matrices(float **matriz_A, float **matriz_B, int fils, int cols);
void liberar_memoria(float **matriz, int fils);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
