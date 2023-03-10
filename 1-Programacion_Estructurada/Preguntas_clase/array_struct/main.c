
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaraciones.h"

int main(int argc, char *argv[])
{
    if(argc != 4)  //Nombre del programa y los 3 parametros pasados CNT_ALUMNOS, MAX_MATERIAS, MAX_NOMBRE
    {
        puts("Aprende a usar el programa\n");
        exit(2); //Codigo de error
    }
    //Uso la funcion atoi porque quiero transformar un ascii a un entero.
    //argv[0] es el nombre del programa, en donde se encuentra
    int16_t cnt_alumnos = atoi(argv[1]);
    int16_t max_nombre = atoi(argv[2]);
    int16_t max_materias = atoi(argv[3]);
    int16_t salida;
    FILE *falumnos = NULL;

    salida = elegir_apertura(falumnos);

    //Declaracion del puntero a estructura
    datos_alumno *alumnos;

    //Reserva de memoria

    alumnos = reservar_memoria(cnt_alumnos, max_nombre, max_materias);

    //Continuamos con el programa
    if(salida == 3)
    {
        char nombre_b[] = "Alumnos.bin";
        falumnos = fopen(nombre_b, "wb");
        verificar_apertura(falumnos);
        //Ingreso de datos
        ingresar_datos(alumnos, cnt_alumnos, max_nombre, max_materias);
        imprimir_datos_binario(alumnos, falumnos, cnt_alumnos);

        //Agregar alumnos
        cnt_alumnos += 2;
        alumnos = agregar_alumnos(alumnos, cnt_alumnos, 2, max_materias, max_nombre);

        //Impresion de datos luego de agregar 2 alumnos
        imprimir_datos_binario(alumnos, falumnos, cnt_alumnos);

        //Sacar alumnos
        cnt_alumnos -= 1;
        intercambiar_datos(alumnos, cnt_alumnos, max_materias);
        alumnos = sacar_alumnos(alumnos, cnt_alumnos, max_materias);

        //Impresion de datos final
        imprimir_datos_binario(alumnos, falumnos, cnt_alumnos);;

        //Cerrar archivo
        fclose(falumnos);

        //Libero memoria
        liberar_memoria(alumnos, cnt_alumnos);

        //Recuperar datos y meterlos en las estructuras desde el respaldo
        recuperar_datos_binario(alumnos, nombre_b);

    }
    else
    {
        char nombre[] = "Alumnos.txt";
        falumnos = fopen(nombre, "w");
        verificar_apertura(falumnos);
        //Ingreso de datos
        ingresar_datos(alumnos, cnt_alumnos, max_nombre, max_materias);
        if(salida == 2)
        {
            imprimir_datos(alumnos, cnt_alumnos, falumnos);

            //Agregar alumnos
            cnt_alumnos += 2;
            alumnos = agregar_alumnos(alumnos, cnt_alumnos, 2, max_materias, max_nombre);

            //Impresion de datos luego de agregar 2 alumnos
            imprimir_datos(alumnos, cnt_alumnos, falumnos);

            //Sacar alumnos
            cnt_alumnos -= 1;
            intercambiar_datos(alumnos, cnt_alumnos, max_materias);
            alumnos = sacar_alumnos(alumnos, cnt_alumnos, max_materias);

            //Impresion de datos final
            imprimir_datos(alumnos, cnt_alumnos, falumnos);

            //Cerrar archivo
            fclose(falumnos);

        }
        else
        {
            imprimir_datos(alumnos, cnt_alumnos, stdout);

            //Agregar alumnos
            cnt_alumnos += 2;
            alumnos = agregar_alumnos(alumnos, cnt_alumnos, 2, max_materias, max_nombre);

            //Impresion de datos luego de agregar 2 alumnos
            imprimir_datos(alumnos, cnt_alumnos, stdout);

            //Sacar alumnos
            cnt_alumnos -= 1;
            intercambiar_datos(alumnos, cnt_alumnos, max_materias);
            alumnos = sacar_alumnos(alumnos, cnt_alumnos, max_materias);

            //Impresion de datos final
            imprimir_datos(alumnos, cnt_alumnos, stdout);

            //Cerrar archivo
            fclose(falumnos);

        }
        //Libero memoria
        liberar_memoria(alumnos, cnt_alumnos);

        //Recuperar datos y meterlos en las estructuras desde el respaldo
        recuperar_datos(alumnos, nombre);

    }


    return 0;
}

/*************************************************

Estructura datos_alumno

    char *nombre;          4 bytes
    int matricula;       + 4 bytes
    catedras *materia;     4 bytes
                        --------------
                           12 bytes


*************************************************/
