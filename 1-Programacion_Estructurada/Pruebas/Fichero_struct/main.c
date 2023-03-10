#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
 {
     char *nombre;
     int edad;

 }trabajadores;

 trabajadores *trab;

 void copiar(char temp[], int i);
 void vaciar(char temp[]);


int main()
{
    char temp[50];
    char aux;
    int cont = 0;
    FILE *f;

    f = fopen("Bloque.txt", "r");
    if(f == NULL)
    {
        printf("No se ha podido abrir el fichero.\n");
        exit(1);
    }

    while(!feof(f))
     {
         fgets(temp, 50, f);
         cont++;
     }

    rewind(f);

    trab = (trabajadores*)malloc(cont*sizeof(trabajadores));
    if(trab == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    for(int i = 0; !feof(f); i++)
    {
        vaciar(temp);
        aux = '0';
        for(int j = 0; aux != '-'; i++)
        {
            aux = fgetc(f);
            if(aux != '-')
            {
                temp[j] = aux;
            }

        }

        copiar(temp, i);

        fgets(temp, 4, f); //Podria poner 50, pero despues del "-" vienen 2 caracteres y el '\n' y el '\0'

        trab[i].edad = atoi(temp);

        printf("Nombre %s  Edad: %i.\n", trab[i].nombre, trab[i].edad); //Atoi lo transformo en un numero entero al caracter 27
    }

    return 0;
}

void vaciar(char temp[])
 {
     for(int i = 0; i < 50; i++)
     {
         temp[i] = '\0';
     }
 }


void copiar(char temp[], int i)
 {
     int N = strlen(temp) + 1; // \'0' no lo cuenta, por eso le sumo 1
     trab[i].nombre = (char*)malloc(N*sizeof(char));
     if (trab[i].nombre == NULL)
     {
         printf("No se ha podido reservar memoria.\n");
         exit(1);
     }

     strcpy(trab[i].nombre, temp);

 }


