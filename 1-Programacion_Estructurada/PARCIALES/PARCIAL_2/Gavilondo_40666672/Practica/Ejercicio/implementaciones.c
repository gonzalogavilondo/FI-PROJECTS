#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones.h"

void  verificar_apertura(FILE *archivo)
{
    if(archivo == NULL)
    {
        puts("No se ha podido abrir el archivo.");
        exit(2); //Codigo de error
    }
}

palabras_t *recuperar_datos(palabras_t *palabras, char *nombre_entrada, int *cnt_palabras)
{
    FILE *frb; //Declaro el archivo de entrada

    frb = fopen(nombre_entrada, "rb");
    verificar_apertura(frb);

    fread(cnt_palabras, sizeof(int), 1, frb);
    palabras = (palabras_t*)malloc(*cnt_palabras*sizeof(palabras_t));
    for(int cnt = 0; cnt < *cnt_palabras; cnt++)
    {
        fread(&palabras[cnt].lng_palabra, sizeof(int), 1, frb);
        palabras[cnt].palabra = (char*)malloc(palabras[cnt].lng_palabra*sizeof(char)); //Reservo memoria para la palabra
        fread(palabras[cnt].palabra, sizeof(char), palabras[cnt].lng_palabra, frb);

    }
    //Cerramos el archivo de lectura
    fclose(frb);

    return palabras;

}

void grabar_datos(palabras_t *palabras,int cnt_palabras, FILE *salida)
{
    for(int cnt = 0; cnt < cnt_palabras; cnt++)
    {
        fprintf(salida, "%d-%s\n", palabras[cnt].lng_palabra, palabras[cnt].palabra);

    }

}

void liberar_memoria(palabras_t *palabras, int cnt_palabras)
{
    for(int cnt = 0; cnt < cnt_palabras; cnt++)
    {
        free(palabras[cnt].palabra);
    }

    free(palabras);

}

void invertir_palabras(palabras_t *palabras, int cnt_palabras)
{
    for(int i = 0; i < cnt_palabras; i++)
    {
        char temp[palabras[i].lng_palabra-1]; //Sacamos el \0
        for(int j = 0; j < palabras[i].lng_palabra-1; j++)
        {
            temp[j] = palabras[i].palabra[palabras[i].lng_palabra-2-j]; //Levantaba de mas el \0 y un salto de linea
        }
        temp[palabras[i].lng_palabra-1] = '\0';
        strcpy(palabras[i].palabra, temp);
        //palabras[i].palabra = &temporal;

    }

}

int comparar(palabras_t *ptr1, palabras_t *ptr2)
{
    return(strcmp(ptr1->palabra, ptr2->palabra));
}
