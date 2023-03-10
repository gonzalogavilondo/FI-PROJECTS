#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void verificar_apertura(FILE *archivo)
{
    if(archivo == NULL)
    {
        puts("No se ha podido abrir el archivo.");
        exit(2);//Codigo de error
    }
}
pantalla_color *recuperar_datos(pantalla_color *matriz, char *nombre_entrada, int *cnt_elementos)
{
    int fils;
    int cols;
    FILE *frb;

    frb = fopen(nombre_entrada, "rb");
    verificar_apertura(frb);

    fread(&fils, sizeof(int), 1, frb);
    fread(&cols, sizeof(int), 1, frb);
    *cnt_elementos = fils*cols;
    matriz = (pantalla_color*)malloc(*cnt_elementos*sizeof(pantalla_color));
    for(int cnt = 0; cnt < *cnt_elementos; cnt++)
    {
        fread(&matriz[cnt].red, sizeof(int), 1, frb);
        fread(&matriz[cnt].blue, sizeof(int), 1, frb);
        fread(&matriz[cnt].green, sizeof(int), 1, frb);

    }
    //Cerramos el archivo de lectura
    fclose(frb);

    return matriz;
}

pantalla_color *suma_componentes(pantalla_color *matriz, int cnt_elementos)
{
    for(int cnt = 0; cnt < cnt_elementos; cnt++)
    {
        matriz[cnt].suma = (matriz[cnt].blue + matriz[cnt].green + matriz[cnt].red);
    }

    return matriz;
}

void grabar_datos(pantalla_color *matriz, FILE *salida)
{
    for(int cnt = 0; cnt < 3; cnt++)
    {
        fprintf(salida, "|\t");
        fprintf(salida, "%lu\t", matriz[cnt].suma); //Imprimo la primera parte en la primer columna.
        fprintf(salida, "%lu\t", matriz[3+cnt].suma); //Imprimo la segunda parte en la segunda columna.
        fprintf(salida, "%lu\t", matriz[6+cnt].suma); //Imprimo la tercera parte en la tercer columna.
        fprintf(salida, "%lu\t", matriz[9+cnt].suma); //Imprimo la cuarta parte en la cuarta columna.
        fprintf(salida, "|\n");
    }

}


