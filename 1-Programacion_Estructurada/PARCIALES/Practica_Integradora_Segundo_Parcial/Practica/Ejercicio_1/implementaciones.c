#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void verificar_apertura(FILE *informacion)
{
    if(informacion == NULL)
    {
        perror("No se ha podido abrir el archivo");
        exit(2); //Codigo de error
    }
}
datos_oracion *recuperar_datos(datos_oracion *oracion, char *nombre_entrada, int *cnt_lineas)
{
    FILE *fr; //Archivo de lectura, de donde voy a levantar los datos.
    char *ptr;

    fr = fopen(nombre_entrada, "r");
    verificar_apertura(fr);

    fscanf(fr, "%d%*c", cnt_lineas);
    oracion = (datos_oracion *)malloc(*cnt_lineas*sizeof(datos_oracion)); //Reservo memoria para la cantidad de oraciones.
    for(int cnt = 0; cnt < *cnt_lineas; cnt++)
    {
        fscanf(fr, "%d%*c", &oracion[cnt].long_linea);
        oracion[cnt].oracion = (char*)malloc(oracion[cnt].long_linea + 1*sizeof(char)); //Reservo memoria para la oracion
        ptr = (oracion[cnt].oracion + oracion[cnt].long_linea); //Pongo un \0 al final del nombre.
        *ptr = '\0';
        fread(oracion[cnt].oracion, sizeof(char), oracion[cnt].long_linea, fr);
        fscanf(fr, "%*c"); //Ultimo salto de linea
    }

    //Cierro el archivo de lectura
    fclose(fr);

    return oracion;

}

void grabar_datos(const datos_oracion *oracion, int cnt_lineas, int long_min, FILE *salida)
{
    for(int cnt = 0; cnt < cnt_lineas; cnt++)
    {
        if(oracion[cnt].long_linea > long_min)
        {
            fprintf(salida, "%s\n", oracion[cnt].oracion);
        }
    }

}

void liberar_memoria(int cnt_lineas, datos_oracion *oracion)
{
    for(int cnt = 0; cnt < cnt_lineas; cnt++)
    {
        free(oracion[cnt].oracion);
    }
    free(oracion);
}

void grabar_datos_binario(const datos_oracion *oracion, int cnt_lineas, int long_min)
{
    FILE *fw;

    fw = fopen("ejercicio1.bin", "wb");
    verificar_apertura(fw);

    fwrite(&cnt_lineas, sizeof(int), 1, fw);
    for(int cnt = 0; cnt < cnt_lineas; cnt++)
    {
        if(oracion[cnt].long_linea > long_min)
        {
            fwrite(&oracion[cnt].long_linea, sizeof(int), 1, fw);
            fwrite(oracion[cnt].oracion, sizeof(char), oracion[cnt].long_linea, fw);
        }
    }

    fclose(fw);
}
datos_oracion *recuperar_datos_binario(datos_oracion *oracion, int *cnt_lineas)
{
    char *ptr;
    FILE *frb;

    frb = fopen("ejercicio1.bin", "rb");
    verificar_apertura(frb);

    fread(cnt_lineas, sizeof(int), 1, frb);
    *cnt_lineas = 4; //Ya que saque una oracion
    oracion = (datos_oracion*)malloc(*cnt_lineas*sizeof(datos_oracion));
    for(int cnt = 0; cnt < *cnt_lineas; cnt++)
    {
        fread(&oracion[cnt].long_linea, sizeof(int), 1, frb);
        oracion[cnt].oracion = (char*)malloc(oracion[cnt].long_linea+1*sizeof(char)); //Reservo memoria para cada oracion, el +1 para el \0
        ptr = oracion[cnt].oracion + oracion[cnt].long_linea;
        *ptr = '\0';
        fread(oracion[cnt].oracion, sizeof(char), oracion[cnt].long_linea, frb);

    }

    //Cierro el archivo de lectura
    fclose(frb);

    return oracion;
}

int linea_menor(datos_oracion *oracion, int cnt_lineas)
{
    int long_min = 0;
    long_min = oracion[0].long_linea;
    for(int cnt = 0; cnt < cnt_lineas; cnt++)
    {
        if(long_min > oracion[cnt].long_linea)
        {
            long_min = oracion[cnt].long_linea;
        }
    }

    return long_min;
}
