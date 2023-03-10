#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void verificar_apertura(FILE *informacion);
int *recuperar_datos(char archivo_entrada[], int *cnt_codigos);
int *combinar(int *entrada_1, int *entrada_2, int *entrada_3, int *cnt_codigos1, int *cnt_codigos2, int *cnt_codigos3);
void menu(int *salida, int cnt_codigost);
void mergesort(int *vector, int low, int high);
void merge(int *vector, int low, int mid, int high);
void quicksort(int *arreglo, int izquierda, int derecha);
int particion(int *arreglo, int izquierda, int derecha);
void intercambiar(int *a, int *b);
void grabar_datos(int *vector, int cnt_codigos, FILE *salida);
void imprimir_datos(int *vector, int cnt_codigos);

#endif // DECLARACIONES_H_INCLUDED
