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
    int cnt_estructuras;

    //Declaracion de un puntero a estructura
    datos_persona *persona = NULL;

    //Declaracion del archivo de salida
    FILE *fwb;

    //Levanto los datos de un archivo binario
    persona = recuperar_datos(persona, archivo_entrada, &cnt_estructuras);

    //Abro el archivo de salida
    fwb = fopen(archivo_salida, "w");
    verificar_apertura(fwb);

    //Grabo los datos levantados del archivo binario en el archivo de salida
    grabar_datos(persona, fwb);

    //Grabo los datos levantados del archivo binario en pantalla para verificar
    grabar_datos(persona, stdout);

    //Cerramos el archivo de escritura
    fclose(fwb);

    //Liberamos memoria
    liberar_memoria(persona, cnt_estructuras);

    return 0;
}
