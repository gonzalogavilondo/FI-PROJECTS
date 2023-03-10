#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void verificar_apertura(FILE *archivo)
{
    if(archivo == NULL)
    {
        puts("No se ha podido abrir el archivo.");
        exit(2); //Codigo de error
    }
}
datos_persona *recuperar_datos(datos_persona *persona, char *archivo_entrada, int *cnt_estructuras)
{
    int fils;
    int cols;

    FILE *frb;

    frb = fopen(archivo_entrada, "rb");
    verificar_apertura(frb);

    fread(&fils, sizeof(int), 1, frb);
    fread(&cols, sizeof(int), 1, frb);
    *cnt_estructuras = fils*cols; //cnt elementos = cnt estructuras.
    //Reservo memoria para la cantidad de estructuras
    persona = (datos_persona*)malloc(*cnt_estructuras*sizeof(datos_persona));

    for(int cnt = 0; cnt < *cnt_estructuras; cnt++)
    {
        fread(&persona[cnt].anio_nac, sizeof(int), 1, frb);
        persona[cnt].nombre = (char*)malloc(12*sizeof(char)); //Supuestamente el string es de 10 caracteres cada nombre, pero no debo olvidar que levante primero la cantidad de filas y de columnas, contando la distancia de una cadena a otra es de 12 bytes.
        fread(persona[cnt].nombre, sizeof(char), 12, frb); //Supuestamente el string es de 10 caracteres cada nombre, pero no debo olvidar que levante primero la cantidad de filas y de columnas, contando la distancia de una cadena a otra es de 12 bytes.
    }

    //Cerramos el archivo de lectura
    fclose(frb);

    return persona;
}
void grabar_datos(datos_persona *persona, FILE *salida)
{
    //El formato que me pide el programa de mostrar es de 6 filas x 2 columnas.
    for(int cnt = 0; cnt < 6; cnt++)
    {
        fprintf(salida, "|\t");
        fprintf(salida, "nac = %d, nombre = %s\t\t", persona[cnt].anio_nac, persona[cnt].nombre); //Imprimo la primera mitad en la primer columna.
        fprintf(salida, "nac = %d, nombre = %s\t\t", persona[6+cnt].anio_nac, persona[6+cnt].nombre); //Imprimo la segunda mitad en la segunda columna.
        fprintf(salida, "|\n");
    }
    puts("\n");
}
void liberar_memoria(datos_persona *persona, int cnt_estructuras)
{
    for(int cnt = 0; cnt < cnt_estructuras; cnt++)
    {
        free(persona[cnt].nombre);
    }
    free(persona);
}
