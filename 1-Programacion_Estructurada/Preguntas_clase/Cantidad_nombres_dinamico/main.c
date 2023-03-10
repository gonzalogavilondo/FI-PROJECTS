#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaraciones_funciones.h"
int main()
{
    int cantidad_personas = 0;
    int longitud_nombre = 0;
    char nombre[LONGMAX] = {'0'};
    char **cadenas = NULL;

    printf("Digite la cantidad de personas: ");
    scanf("%i", &cantidad_personas);

    //Reservamos memoria para el puntero doble, que seria la cantidad de personas, que a su vez este va a apuntar a otro puntero que apunta a el nombre de cada persona.
    cadenas = (char**)malloc(cantidad_personas*sizeof(char*));
    if(cadenas == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(0);
    }

    //Ingresamos los nombres de las personas con su longitud.
    for(int i = 0; i < cantidad_personas; i++)
    {
        system("pause");
        system("cls || clear");
        printf("Escriba el nombre de la %i%c persona: ", i+1, 248);
        fflush(stdin);
        fgets(nombre, LONGMAX, stdin);
        longitud_nombre = strlen(nombre);
        //Reservo memoria para la cantidad de caracteres de cada persona (puntero simple).
        cadenas[i] = (char*)malloc(longitud_nombre*sizeof(char));
        strcpy(cadenas[i], nombre);
        printf("El nombre de la %i%c persona es: %s\n", i+1, 248, nombre);
        printf("La cantidad de caracteres de la %i%c persona son: %i\n\n", i+1, 248, longitud_nombre);
        free(cadenas[i]); //Libero memoria para la cantidad de caracteres en cada nombre.
    }

    free(cadenas);//Libero memoria para la cantidad de personas.


    /*
    Tengo que hacer una modificacion, un do while descargando en un auxiliar cada tecla que ingreso el usuario para reallocar
    la memoria necesaria.
    O con fgets.
    */


    return 0;
}
