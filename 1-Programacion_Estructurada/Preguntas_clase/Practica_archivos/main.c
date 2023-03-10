#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaraciones.h"

int main(int argc, char *argv[])
{
    if(argc != 3)  //Nombre del programa y el parametro MAX_NOMBRE
    {
        puts("Aprende a usar el programa\n");
        exit(1); //Codigo de error
    }
    //Uso la funcion atoi porque quiero transformar un ascii a un entero.
    //argv[0] es el nombre del programa, en donde se encuentra
    int16_t max_nombre = atoi(argv[1]);
    int16_t max_personas = atoi(argv[2]);
    int salida = 0;

    salida = elegir_apertura();

    //Declaracion del puntero a estructura
    datos_persona *persona;

    //Declaracion del flujo de datos
    FILE *informacion;

    //Reservo memoria para 2 personas(max personas)
    persona = reservar_memoria(max_nombre, max_personas);

    //Ingreso datos
    ingresar_datos(persona, max_nombre);

    //Realloco memoria por si el usuario ingreso 1 sola persona
    persona = reallocar_memoria(persona);

    system("pause");
    system("cls || clear");

    if(salida == 1)
    {
        imprimir_datos_finales(persona, stdout);
    }
    else
    {
        if(salida == 2)
        {
            //Declaracion del nombre del archivo
            char nombre[] = "Persona.txt";
            informacion = fopen(nombre, "w");
            verificar_apertura(informacion);
            //Grabo en formato txt
            grabar_datos(persona, informacion);
            //Cerramos el archivo
            fclose(informacion);
            liberar_memoria(persona);
            //Recupero los datos(Levanto lo que dice el archivo).
            persona = recuperar_datos(persona, nombre);
            //Imprimo los datos finales tambien por pantalla
            imprimir_datos_finales(persona, stdout);

        }
        /***********************
        Hago lo mismo en binario
        ************************/
        else
        {
            //Declaracion del nombre del archivo
            char nombre_b[] = "Persona.bin";
            informacion = fopen(nombre_b, "wb");
            verificar_apertura(informacion);
            //Grabo en formato binario
            grabar_datos_binario(persona, informacion);
            //Cerramos el archivo
            fclose(informacion);
            //Libero memoria
            liberar_memoria(persona);
            //Recupero los datos(Levanto lo que dice el archivo).
            persona = recuperar_datos_binario(persona, nombre_b);
            //Imprimo los datos finales tambien por pantalla
            imprimir_datos_finales(persona, stdout);

        }
    }
    //Libero memoria
    liberar_memoria(persona);

    return 0;
}
