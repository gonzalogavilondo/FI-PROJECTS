#include "funciones.h"

void datos(void)
{
    char cadena1[] = "Primera";                                     // longitud 8
    char cadena2[] = { 'S', 'e', 'g', 'u', 'n', 'd', 'a', '\0'};    // longitud 8
    char cadena3[100] = "Una cadena en C";

    /**** Ingeso datos ****/
    strcpy(cadena2, cadena3);            // sobre escribe cadena1 porque cadena3 tiene mayor longitud
    printf("\nContenido de cadena1 = %s\n", cadena1);        // junta los 2 strings vector + cadena2

    strcpy(cadena2, "Segunda");             // vuelvo a los valores originales
    strcpy(cadena1, "Primera");             // no hay problema porque cadena2 tiene longitud menor
    printf("\nContenido de cadena1 = %s\n", cadena1);        // verifico cadena1

    strncpy(cadena2, cadena3, 4);        // copia sólo 4 caracteres
    printf("\nContenido de cadena1 = %s y cadena2 = %s\n", cadena1, cadena2);

    /**** Comparación entre strings ****/
    printf("\nComparacion entre Abc y Bbc = %d", strcmp("Abc", "Bbc"));
    printf("\nComparacion entre abc y Abc = %d", strcmp("abc", "Abc"));
    printf("\nComparacion entre Abc y Abc = %d", strcmp("Abc", "Abc"));

    printf("\n\nComparacion 4 caracteres = %d", strncmp("Abcde", "Abcdf", 4));
}

void longitud(void)
{
    char cadena1[] = "Hola";                          // longitud 5
    char cadena2[] = { 'h', 'o', 'l', 'a', '\0'};     // longitud 5
    char vector[] = { 'H', 'o', 'l', 'a'};            // vector de 4 elementos
    char cadena3[20] = "Una cadena en C";
    char cadena4[] = "";                              // ver memoria desde aca

    /**** Para conocer la longitud de un string ****/
    printf("Longitud de cadena1 = %d\n", strlen(cadena1));
    printf("Longitud de cadena2 = %d\n", strlen(cadena2));
    printf("Longitud de vector = %d\n", strlen(vector));     // produce 8 porque no encuentra '\0'
    printf("Longitud de cadena3 = %d\n", strlen(cadena3));
    printf("Longitud de cadena4 = %d\n", strlen(cadena4));

    printf("\nContenido de cadena1 = %s\n", cadena1);
    printf("\nContenido de cadena2 = %s\n", cadena2);
    printf("\nContenido de vector = %s\n", vector);          // junta los 2 strings vector + cadena2
    printf("\nContenido de cadena3 = %s\n", cadena3);
    printf("\nContenido de cadena4 = %s\n", cadena4);

}

void concatenar(void)
{
    char nombre[] = "Tomas A. ";
    char apellido[] = "Edison ";
    char largo[] = "String demasiado largo";

    printf("\n\nNombre completo: %s", strcat(apellido, largo));    // sobre escribe apellido y nombre
    printf("\nApellido: %s y nombre: %s", apellido, nombre);

    printf("\n\nBusco a en largo = %s", strchr(largo, 'a'));       // primer ocurrencia de a
    printf("\n\nBusco a en largo = %s", strrchr(largo, 'a'));       // última ocurrencia de a

    printf("\n\nBusco b, r, g, a en largo = %d\n\n", strcspn(largo, "brga"));
}


