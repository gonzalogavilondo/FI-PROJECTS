#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
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
    int cnt_palabras = 0;

    //Declaracion del puntero a estructura
    palabras_t *palabras = NULL;

    //Declaracion del archivo de salida
    FILE *fw;

    //Levanto los datos de un archivo binario
    palabras = recuperar_datos(palabras, archivo_entrada, &cnt_palabras);

    //Muestro por pantalla el diccionario antes de implementar la funcion para invertir.
    printf("-Diccionario normal-\n\n");
    grabar_datos(palabras, cnt_palabras, stdout);
    puts("\n");

    //Invertimos las oraciones
    invertir_palabras(palabras, cnt_palabras);
    //Ordenamos las oraciones
    qsort(palabras, cnt_palabras, sizeof(palabras_t), &comparar);
    //Volvemos a invertir las oraciones
    invertir_palabras(palabras, cnt_palabras);

    //Imprimimos en consola el resultado para verificar
    printf("-Diccionario inverso-\n\n");
    grabar_datos(palabras, cnt_palabras, stdout);

    //Abrimos el archivo de texto donde vamos a escribir los datos finales:
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);
    grabar_datos(palabras, cnt_palabras, fw);
    //Cerramos el archivo de escritura
    fclose(fw);

    //Liberamos memoria pedida al sistema operativo.
    liberar_memoria(palabras, cnt_palabras);

    return 0;
}
