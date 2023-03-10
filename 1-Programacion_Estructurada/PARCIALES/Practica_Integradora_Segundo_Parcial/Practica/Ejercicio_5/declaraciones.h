#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

float *recuperar_datos(float *vec, char *archivo_entrada, int *cnt_elementos);
void verificar_apertura(FILE *archivo);
void ordenar_vector(float *vec, int cols);
void imprimir_vector(float *vec, int cols, FILE *salida);


#endif // DECLARACIONES_H_INCLUDED
