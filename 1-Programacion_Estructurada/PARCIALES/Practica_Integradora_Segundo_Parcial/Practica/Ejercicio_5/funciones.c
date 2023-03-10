#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

float *recuperar_datos(float *vec, char *archivo_entrada, int *cnt_elementos)
{
    FILE *frb;

    frb = fopen(archivo_entrada, "rb");
    verificar_apertura(frb);
    fseek(frb, 0, SEEK_END);//Mando el cursor al final del archivo.
    fseek(frb, -4, SEEK_CUR); //Desde la posicion actual(final del archivo) me muevo 4 lugares hacia atras, que es donde empieza el entero que me dice la cantidad de elementos.
    fread(cnt_elementos, sizeof(int), 1, frb);
    rewind(frb); //Vuelvo al principio del archivo
    vec = (float*)malloc(*cnt_elementos*sizeof(float)); //Reservo memoria para el vector
    for(int cnt = 0; cnt < *cnt_elementos; cnt++)
    {
        fread(&vec[cnt], sizeof(float), 1, frb);
    }

    //Cerramos el archivo de lectura
    fclose(frb);

    return vec;

}
void verificar_apertura(FILE *archivo)
{
    if(archivo == NULL)
    {
        puts("No se ha podido abrir el archivo.");
        exit(2); //Codigo de error
    }
}
void ordenar_vector(float *vec, int cols)
{
    float aux = 0.0;
    for(int j = 0; j < cols-1; j++)
    {
        if (vec[j] > vec[j+1])
        {
            aux = vec[j];
            vec[j] = vec[j+1];
            vec[j+1] = aux;
        }
    }

}
void imprimir_vector(float *vec, int cols, FILE *salida)
{
    fprintf(salida, "|\t");
    for(int j = 0; j < cols; j++)
    {
        fprintf(salida, "%.2f\t", vec[j]);
    }
    fprintf(salida, "|\n\n");
}
