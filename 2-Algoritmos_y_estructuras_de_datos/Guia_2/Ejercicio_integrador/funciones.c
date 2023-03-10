#include "declaraciones.h"

void verificar_matriz(int matriz[FILS][COLS], char nombre)
{
    int aux = 0;
    for(int i = 0; i < FILS-1; i++) //Recorre las filas hasta donde hay un ultimo '0' en la columna.
    {
        for(int j = i+1; j < COLS; j++) //Recorre las columnas en todos los lugares donde debe haber un '0' si es una matriz triangular superior.
        {
            if(matriz[j][i] != 0)
            {
                aux = -1;   //Si donde debe haber ceros, hay un valor distinto, entonces la matriz ya no es triangular superior, y le asignamos a aux = -1.
            }
        }
    }
    if(aux == -1)
    {
        printf("Matriz '%c' no valida.\n", nombre);
        exit(1);//Si una de las dos matrices no cumple con la triangularidad, el programa termina con un codigo de error = 1.
    }

}

void mapear_matriz(int matriz[FILS][COLS], int vector[LONGMAX])
{
    int k = 0;
    for (int i = 0; i < FILS; i++)
    {
        for (int j = i; j < COLS; j++)
        {
            vector[k] = matriz[i][j];
            k++;
        }
    }
}

void OrdInsercion(int vector[LONGMAX])
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

void busqueda_secuencial(int vector_1[LONGMAX], int vector_2[LONGMAX], int condicion[3], int posicion[3])
{
    int j = 0;
    for(int i = 0; i < LONGMAX; i++)
    {
        if((vector_1[i] == condicion[j]) && (vector_2[i] == condicion[j]))
        {
            posicion[j] = i;
            j++;
        }
        else
        {
            if(((vector_1[i] == condicion[j]) && (vector_2[i] != condicion[j])) || ((vector_1[i] != condicion[j]) && (vector_2[i] == condicion[j])))
            {
                printf("No se puede iniciar comunicacion. Los valores de coincidencia pedidos no coinciden.\n");
                exit(2);//Frena con la busqueda y sale del programa con un codigo de error igual a 2.
                /*
                Nota: Pongo que alguno de los dos vectores coincida con la condicion para asegurarme que estoy parado
                      en uno de los valores pedidos.
                */

            }
        }
    }
}

void imprimir_vector(int vector[LONGMAX])
{
    printf("[  ");
    for(int j = 0; j < LONGMAX; j++)
    {
        printf("%d  ", vector[j]);
    }
    printf("]\n\n");

}

void imprimir(int posicion[3], int condicion[3])
{
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("La condicion es hayar en ambos vectores la posicion del numero: %d", condicion[i]);
        printf("\nLa posicion del numero pedido es: %d\n\n", posicion[i]+1);
    }

}
