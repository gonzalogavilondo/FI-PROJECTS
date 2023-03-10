#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "declaraciones.h"

void verificar_apertura(FILE *archivo)
{
    if(archivo == NULL)
    {
        puts("No se ha podido abrir el archivo.");
        exit(2);//Codigo de error
    }

}

punto *recuperar_datos(punto *coordenada, char *archivo_entrada, int *cnt_pares)
{
    int cnt_coordenadas;
    FILE *fr;
    fr = fopen(archivo_entrada, "r");
    verificar_apertura(fr);

    fscanf(fr, "%d%*c", &cnt_coordenadas);
    coordenada = (punto *)malloc(cnt_coordenadas*sizeof(punto)); //Reservo memoria para la cantidad de pares de coordenadas.
    *cnt_pares = cnt_coordenadas/2; //La cantidad de pares de coordenadas, como su nombre lo indica es la cantidad de coordenadas agrupadas de a 2.
    for(int cnt = 0; cnt < cnt_coordenadas; cnt++)
    {
        fscanf(fr, "%d%*c%d%*c%*c%d%*c%d%*c", &coordenada[cnt].coorx1, &coordenada[cnt].coory1,
                                              &coordenada[cnt].coorx2, &coordenada[cnt].coory2);
    }

    //Cierro el archivo de lectura
    fclose(fr);

    return coordenada;
}

punto  *distancia(punto *coordenada, int cnt_pares)
{
    for(int cnt = 0; cnt < cnt_pares; cnt++)
    {
        coordenada[cnt].distancia = sqrt(pow(coordenada[cnt].coorx1 - coordenada[cnt].coorx2, 2) + pow(coordenada[cnt].coory1 - coordenada[cnt].coory2, 2));
    }

    return coordenada;
}

double mayor_distancia(punto *coordenada, int cnt_pares)
{
    double aux;
    aux = coordenada[0].distancia; //Le asigno el primer valor de distancia calculado y lo voy comparando con los demas, si uno es mayor, el valor de aux cambia a ese valor.
    for(int cnt = 1; cnt < cnt_pares; cnt++) //cnt = 1 para que empiece comparando con el segundo elemento y no se compare a si mismo.
    {
        if(coordenada[cnt].distancia > aux)
        {
            aux = coordenada[cnt].distancia;
        }
    }

    return aux;
}

void imprimir(punto *coordenada, int cnt_pares, FILE *salida)
{
    for(int cnt = 0; cnt < cnt_pares; cnt++)
    {
        fprintf(salida, "%dº Distancia = %.2f\n", cnt+1, coordenada[cnt].distancia);
    }
}
