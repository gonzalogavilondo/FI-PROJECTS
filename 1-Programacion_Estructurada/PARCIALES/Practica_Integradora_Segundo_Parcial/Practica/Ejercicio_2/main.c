#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(int argc, char *argv[])
{
    if(argc != 3)  //3 = Nombre del programa, del archivo de entrada y de salida.
    {
        puts("Aprende a usar el programa\n");
        exit(1); //Codigo de error
    }
    //argv[0] Es donde se encuentra el nombre del programa.
    char *archivo_entrada = (argv[1]); //Nombre del archivo de entrada.
    char *archivo_salida = (argv[2]); //Nombre del archivo de salida.
    int cnt_elementos = 0;

    //Declaramos el puntero a estructura
    pantalla_color *matriz = NULL;

    //Declaramos el flujo de salida
    FILE *fw;

    //Recuperamos la informacion que hay en el archivo de entrada
    matriz = recuperar_datos(matriz, archivo_entrada, &cnt_elementos);

    //Funcion donde sume las 3 componentes
    matriz = suma_componentes(matriz, cnt_elementos);

    //Mostramos el "despues" por pantalla para verificar
    grabar_datos(matriz, stdout);

    //Abrimos el archivo de salida en formato txt
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);

    //Grabamos los datos en forma de matriz
    grabar_datos(matriz, fw);

    //Cerramos el archivo de escritura
    fclose(fw);

    //Liberamos memoria
    free(matriz);

    return 0;
}

