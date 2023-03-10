#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(int argc, char *argv[])
{
    if(argc != 3)  //Nombre del programa, del archivo de entrada y de salida.
    {
        puts("Aprende a usar el programa.");
        exit(1); //Codigo de error
    }
    //argv[0] Es donde se encuentra el nombre del programa.
    char *archivo_entrada = (argv[1]);
    char *archivo_salida = (argv[2]);
    int cnt_elementos;

    //Declaracion del vector dinamico
    float *vec = NULL;

    //Declaracion del archivo de escritura, el que voy a utilizar para escribir los datos que voy a levantar
    FILE *fw;

    //Funcion para levantar los datos del archivo de entrada
    vec = recuperar_datos(vec, archivo_entrada, &cnt_elementos);

    //Ordenamiento del vector
    ordenar_vector(vec, cnt_elementos);

    //Abrimos el archivo en donde voy a escribir el vector resultante
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);

    //Grabo en el archivo de texto el vector resultante
    imprimir_vector(vec, cnt_elementos, fw);

    //Imprimo por pantalla para verificar
    imprimir_vector(vec, cnt_elementos, stdout);

    //Cerramos el archivo de escritura
    fclose(fw);

    //Liberamos memoria
    free(vec);

    return 0;
}
