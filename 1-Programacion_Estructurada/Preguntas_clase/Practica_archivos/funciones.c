#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones.h"

int elegir_apertura(void)
{
    int opcion = 0;

    do
    {
        puts("1) Grabar en memoria.\n");
        puts("2) Grabar en archivo de texto.\n");
        puts("3) Grabar en archivo binario.\n");
        puts("4) Salir.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        if(opcion == 4)
        {
            exit(0);
        }
        else
        {
            if(opcion > 4 || opcion < 1)
            {
                puts("\nIngrese una opcion correcta.");
                system("pause");
                system("cls || clear");

            }
        }

    }while(opcion > 4 || opcion < 1);

    return opcion;
}
datos_persona *reservar_memoria(int16_t max_nombre, int16_t max_personas)
{
    datos_persona *ptr;
    ptr = (datos_persona *)malloc(max_personas*sizeof(datos_persona)); //Guardo memoria para todas las personas
    if(ptr == NULL)
    {
        printf("No se ha podido reservar memoria.\n");
        exit(1);
    }
    else
    {
        for(int cnt = 0; cnt < max_personas; cnt++)
        {
            ptr[cnt].nombre = (char *)malloc(max_nombre*sizeof(char)); //Reservo memoria para el nombre
        }
    }

    return ptr;
}
void verificar_apertura(FILE *informacion)
{
    if(informacion == NULL)
    {
        perror("No se ha podido abrir el archivo");
        exit(2);
    }
}

void ingresar_datos(datos_persona *persona, int16_t max_nombre)
{
    char *pch;

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &persona->cnt_personas);
    fflush(stdin);
    for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
    {
        fflush(stdin);
        printf("Nombre: ");
        fgets(persona[cnt].nombre, max_nombre, stdin);
        fflush(stdin);
        pch = strchr(persona[cnt].nombre, 10); //El 10 es el \n en ASCII. Si lo encuentra reemplaza el nueva linea por \0(fin de linea).
            if(pch != NULL)
            {
                *pch = '\0';
            }
        persona[cnt].long_nombre = strlen(persona[cnt].nombre);
        printf("Altura(metros): ");
        scanf("%f", &persona[cnt].altura);
        printf("Edad: ");
        scanf("%d", &persona[cnt].edad);
        printf("\n\n");
    }

}

void grabar_datos(const datos_persona *persona, FILE *salida)
{
    fprintf(salida, "%d\n", persona->cnt_personas);
    for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
    {
        fprintf(salida, "%d,", persona[cnt].long_nombre); //Longitud del nombre
        fprintf(salida, "%s,", persona[cnt].nombre); //Nombre de la persona
        fprintf(salida, "%.2f,", persona[cnt].altura); //Altura de la persona
        fprintf(salida, "%d", persona[cnt].edad); //Edad de la persona
        fprintf(salida, "\n");
    }

}

datos_persona *recuperar_datos(datos_persona *persona, char *nombre)
{
    FILE *fr;
    int cnt_personas;
    char *ptr;
    fr = fopen(nombre, "r");
    verificar_apertura(fr);

    fscanf(fr, "%d%*c", &cnt_personas);
    persona = (datos_persona *)malloc(cnt_personas*sizeof(datos_persona));
    persona->cnt_personas = cnt_personas;
    for(int cnt = 0; cnt < cnt_personas; cnt++)
    {
        fscanf(fr, "%d%*c", &persona[cnt].long_nombre);
        persona[cnt].nombre = (char*)malloc(persona[cnt].long_nombre + 1*sizeof(char)); //Reservo memoria para el nombre
        ptr = persona[cnt].nombre + persona[cnt].long_nombre; //Pongo un \0 al final del nombre.
        *ptr = '\0';
        fread(persona[cnt].nombre, sizeof(char), persona[cnt].long_nombre, fr);
        fscanf(fr, "%*c%f%*c%d%*c", &persona[cnt].altura, &persona[cnt].edad);
    }

    //Cierro el archivo
    fclose(fr);

    return persona;

}

void grabar_datos_binario(const datos_persona *persona, FILE *informacion)
{
    fwrite(&persona->cnt_personas, sizeof(int), 1, informacion);
    for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
    {
        fwrite(&persona[cnt].long_nombre, sizeof(int), 1, informacion);
        fwrite(persona[cnt].nombre, sizeof(char), persona[cnt].long_nombre, informacion);
        fwrite(&persona[cnt].altura, sizeof(float), 1, informacion);
        fwrite(&persona[cnt].edad, sizeof(int),1, informacion);
    }
}
datos_persona *reallocar_memoria(datos_persona *persona)
{
    persona = (datos_persona*)realloc((datos_persona*)persona, (persona->cnt_personas)*sizeof(datos_persona));
    if(persona == NULL)
    {
        printf("No se ha podido reservar espacio en memoria\n");
        exit(3);
    }
    else
    {
        for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
        {
            persona[cnt].nombre = (char*)realloc((char*)persona[cnt].nombre, persona[cnt].long_nombre*sizeof(char));
        }
    }

    return persona;
}
void imprimir_datos_finales(const datos_persona *persona, FILE *salida)
{
    fprintf(salida, "Cantidad de personas: %d\n", persona->cnt_personas);
    for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
    {
        fprintf(salida, "\nLongitud del nombre: %d", persona[cnt].long_nombre);
        fprintf(salida, "\nNombre: %s", persona[cnt].nombre);
        fprintf(salida, "\nAltura: %.2f", persona[cnt].altura);
        fprintf(salida, "\nEdad: %d", persona[cnt].edad);
        fprintf(salida, "\n\n");
    }

}
datos_persona *recuperar_datos_binario(datos_persona *persona, char *nombre_b)
{
    int cnt_personas;
    char *ptr;
    FILE *frb;

    frb = fopen(nombre_b, "rb");
    verificar_apertura(frb);

    fread(&cnt_personas, sizeof(int), 1, frb);
    persona = (datos_persona*)malloc(cnt_personas*sizeof(datos_persona));
    persona->cnt_personas = cnt_personas;
    for(int cnt = 0; cnt < cnt_personas; cnt++)
    {
        fread(&persona[cnt].long_nombre, sizeof(int), 1, frb);
        persona[cnt].nombre = (char*)malloc(persona[cnt].long_nombre + 1*sizeof(char)); //+1 para incluir al \0
        ptr = persona[cnt].nombre + persona[cnt].long_nombre;
        *ptr = '\0';  //Pongo un \0 al final del nombre.
        fread(persona[cnt].nombre, sizeof(char), persona[cnt].long_nombre, frb);
        fread(&persona[cnt].altura, sizeof(float), 1, frb);
        fread(&persona[cnt].edad, sizeof(int), 1, frb);
    }

    //Cierro el archivo de lectura
    fclose(frb);

    return persona;
}
void liberar_memoria(datos_persona *persona)
{
    for(int cnt = 0; cnt < persona->cnt_personas; cnt++)
    {
        free(persona[cnt].nombre);
    }
    free(persona);
}
