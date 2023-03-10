#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdint.h>
#define CANTIDAD_CARACTERES 11
#pragma pack(1) //Esto es para que el compilador no 'redondee' el tamaño de la estructura cod_desc_t (de 25 bytes a 28 bytes)

typedef struct
{
    uint32_t cod;
    uint8_t desc[21];
} cod_desc_t;

typedef struct
{
    uint32_t id;
    uint8_t *nombre;

}persona_t;

int main()
{

    //Ejemplo 1
    {

        cod_desc_t ciudad1 = {7600, "Mar del plata"};
        cod_desc_t ciudad2;

        //Asignacion de la variable ciudad1 a ciudad2

        ciudad2 = ciudad1; //se copia el contenido pero en otra dirección de memoria

        printf("size of cod_desc_t: %d \n", sizeof(cod_desc_t));
        printf("size of ciudad1.cod: %d \n", sizeof(ciudad1.cod));
        printf("size of ciudad1.desc: %d \n", sizeof(ciudad1.desc));
        printf("cod: %d y desc: %s \n", ciudad2.cod, ciudad2.desc);

        strncpy((char *)&ciudad2.desc, "Miramar", 7);

        printf("cod: %d y desc: %s \n", ciudad1.cod, ciudad1.desc);
        printf("cod: %d y desc: %s \n", ciudad2.cod, ciudad2.desc);

    }

    //Ejemplo 2
    {

        char cadena[CANTIDAD_CARACTERES];

        strncpy(cadena, "unodostres", CANTIDAD_CARACTERES);

        persona_t alumno1, alumno2;

        alumno1.id = 1;
        alumno1.nombre = (uint8_t *)&cadena[0];

        alumno2 = alumno1;

        printf("id: %d y nombre: %s \n", alumno2.id, alumno2.nombre);

        strncpy((char *)&alumno2.nombre[0], "cuatroseis", CANTIDAD_CARACTERES);

        printf("id: %d y nombre: %s \n", alumno1.id, alumno1.nombre);

    }



    return 0;
}
