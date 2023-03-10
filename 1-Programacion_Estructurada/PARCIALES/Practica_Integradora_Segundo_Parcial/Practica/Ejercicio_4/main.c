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
    char *archivo_entrada = (argv[1]);
    char *archivo_salida = (argv[2]);
    int cnt_pares = 0;
    double m_distancia = 0;

    //Declaracion del puntero a estructura
    punto *coordenada = NULL;

    //Declaracion del archivo de escritura
    FILE *fw;

    //Invocacion de la funcion que recupera los datos del archivo de entrada y va reserva memoria a medida que levanta.
    coordenada = recuperar_datos(coordenada, archivo_entrada, &cnt_pares); //Paso por referencia la cantidad de pares de coordenadas

    //Invocacion de la funcion que calcula las distancias euclidianas entre los puntos
    coordenada = distancia(coordenada, cnt_pares);

    //Abro el archivo de escritura
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);
    //Grabo en un archivo de texto las distancias
    imprimir(coordenada, cnt_pares, fw);
    //Cierro el archivo de escritura
    fclose(fw);

    //Invocacion de la funcion que determina cual es la mayor
    m_distancia = mayor_distancia(coordenada, cnt_pares);

    //Imprimo por consola la mayor distancia
    printf("La mayor distancia es: %.2f", m_distancia);

    //Libero memoria
    free(coordenada);

    return 0;
}
