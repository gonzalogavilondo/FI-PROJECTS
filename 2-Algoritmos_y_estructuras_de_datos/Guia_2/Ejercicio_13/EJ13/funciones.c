#include "declaraciones.h"

void completar_matriz (float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < FILSMAX; i++)
    {
        for (int j = 0; j < COLSMAX; j++)
        {
            printf("COMPLETE LA MATRIZ: \n\n");
            imprimir_matriz(matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void imprimir_vector(float vector[LONGMAX])
{
    printf("|\t");
    for(int j = 0; j < LONGMAX; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}

void imprimir_matriz (float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < FILSMAX; i++)
    {
        printf("|\t");
        for (int j = 0; j < COLSMAX; j++)
        {
           printf("%.2f \t", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    puts("\n");
}

void mapear_matriz(float matriz[FILSMAX][COLSMAX], float vector[LONGMAX])
{
    int k = 0;
    for (int i = 0; i < FILSMAX; i++)
    {
        for (int j = i; j < COLSMAX; j++)
        {
                vector[k] = matriz[i][j];
                k++;
        }

    }

}

int busqueda_binaria(float vector[LONGMAX], float condicion)
{
    int low, mid, high;
    low = 0; high = (FILSMAX - 1); //low seria la posicion inicial y high la posicion final.

    while(low <= high)  //Mientras que la posicion inicial sea menor a la posicion final
    {
        mid = (low + high)/2; //Encuentro el valor medio.
        if(vector[mid] < condicion)        //Verifico si el valor que esta en esa posicion es menor al valor que quiero encontrar
        {
            low = (mid + 1);   //Si es menor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo low del intervalo.
        }
        else
        {
            if (vector[mid] > condicion) //Como no era menor, verifico si es mayor el valor que esta en esa posicion con respecto al que quiero hayar.
            {
                high = (mid - 1);//Si es mayor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo high del intervalo.
            }
            else //Si no es ni mayor, ni menor, quiere decir que entonces el valor que esta en la posicion [mid], es el que queriamos buscar.
            {
                return(mid);
            }
        }
    }

    return(-1);
}
void OrdInsercion(float vector[LONGMAX])
{
    int i, j, aux;

    for(i = 1; i < LONGMAX; i++)
    {
        j = i;
        aux = vector[i]; //Guarda el valor que quiere insertar en una variable auxiliar.
        while(j > 0 && aux < vector[j-1]) //Recorre de derecha a izquierda
        {
            vector[j] = vector[j-1];      //Se detiene cuando el anterior ya NO es mayor.
            j--;                          //En cada caso, corre el numero a la derecha.
        }
        vector[j] = aux;                  //Al terminar, coloca el valor en su posicion final.
    }

}

void imprimir(int posicion, float condicion)
{
    printf("\n\nLa condicion es hayar en el vector la posicion del numero: %.2f", condicion);

    if(posicion == -1)
    {
        printf("\n\nNo se ha podido encontrar la posicion del valor pedido.\n");
    }
    else
    {
        printf("\n\nLa posicion del numero pedido es: %d\n\n", posicion+1);

    }
}
