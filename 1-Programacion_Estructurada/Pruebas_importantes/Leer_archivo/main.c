#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *falumnos;

    int num_elementos = 0;
    char *cadena;

    falumnos = fopen("C:\\Users\\Gonza\\Desktop\\Prueba_archivos\\Alumnos.txt", "r");
    if(falumnos == NULL)
    {
        perror("Error al abrir el archivo.\n");
    }

    fseek(falumnos, 0, SEEK_END);  //Movemos el flujo hasta el final del archivo.
    num_elementos = ftell(falumnos); //ftell pregunta donde se encuentra el flujo de datos, como lo movi antes, me va a dar la cantidad de elementos o caracteres,
    rewind(falumnos); //Otra vez movemos al flujo al inicio del archivo (rewind = rebobinar).
    cadena = (char*)malloc(num_elementos*sizeof(char)); //Reservo memoria para la cadena.
    if(cadena == NULL)
    {
        perror("Error en reserva de memoria\n");
    }

    fread(cadena, sizeof(char), num_elementos, falumnos);
    /*
    fread hace el "trabajo pesado" primero recibe la cadena, de que tamaño cada elemento y cuantos quiero
    leer, y por ultimo el flujo que lo que va a hacer es extraer la informacion.
    Nota: fread retorna la cantidad de numeros leidos, entonces vamos a hacer la comprobacion a continuacion:
    */

    printf("%s", cadena);

    free(cadena);
    fclose(falumnos);
    return 0;
}
