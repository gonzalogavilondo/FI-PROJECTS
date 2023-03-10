#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(int argc, char *argv[])
{
    if(argc != 3)  //Nombre del programa, del archivo de entrada y de salida.
    {
        puts("Aprende a usar el programa\n");
        exit(1); //Codigo de error
    }
    //argv[0] Es donde se encuentra el nombre del programa.
    char *archivo_entrada = (argv[1]); //Nombre del archivo de entrada.
    char *archivo_salida = (argv[2]); //Nombre del archivo de salida.
    int cnt_lineas = 0;
    int long_min = 0;

    //Declaracion del archivo de escritura, donde voy a escribir los datos que voy a levantar.
    FILE *fw;
    //Declaracion del archivo de escritura, donde voy a escribir los datos que voy a levantar del archivo binario.
    FILE *fwb;

    //Declaracion del puntero a estructura
    datos_oracion *oracion = NULL;

    //Abro el archivo donde voy a escribir la informacion que voy a levantar.
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);
    //Levanto lo que hay en el archivo de entrada y voy reservando memoria mientras levanto.
    oracion = recuperar_datos(oracion, archivo_entrada, &cnt_lineas);
    //Funcion que me determine la cadena mas corta
    long_min = linea_menor(oracion, cnt_lineas);
    //Escribo lo levantado en el archivo de salida
    grabar_datos(oracion, cnt_lineas, long_min, fw);
    //Reutilizo la funcion para imprimir en consola
    grabar_datos(oracion, cnt_lineas, long_min, stdout);
    //Escribo en un archivo binario
    grabar_datos_binario(oracion, cnt_lineas, long_min);
    //Cierro el archivo de escritura
    fclose(fw);

    //Libero memoria
    liberar_memoria(cnt_lineas, oracion);

    /********************************************************************
    RECUPERO LO DEL ARCHIVO EN BINARIO Y LO GUARDO EN UN ARCHIVO DE TEXTO
    ********************************************************************/

    //Abro el archivo donde voy a escribir la informacion levantada del archivo binario
    fwb = fopen("sbejercicio1.txt", "w");
    verificar_apertura(fwb);
    //Recupero los datos del archivo que escribi en binario
    oracion = recuperar_datos_binario(oracion, &cnt_lineas);
    //Escribo en un archivo de salida
    grabar_datos(oracion, cnt_lineas, long_min, fwb);
    //Cierro el archivo de escritura
    fclose(fwb);
    //Libero memoria
    liberar_memoria(cnt_lineas, oracion);

}
