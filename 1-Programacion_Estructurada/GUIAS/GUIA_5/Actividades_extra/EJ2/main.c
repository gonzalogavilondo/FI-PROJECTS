#include <stdio.h>
#include <stdlib.h>

int completar_elemento (const int V[9], int, int);
void completar_matx (const int[9], int [3][3]);
void imprimir_matx (const int [3][3]);
int main()
{
    int V[9] = {0,2,3,4,5,6,7,8,9};
    int M[3][3] = {{0}};
    completar_matx(V, M);
    imprimir_matx(M);
    return 0;
}

int completar_elemento (const int V[9], int i, int j)
{
    int elemento;
    if ( (V[j] != 0 && V[i] % V[j] == 0) || (V[i] != 0 && V[j] % V[i] == 0) )
    {
        if ( (V[j] != 0 && V[i] % V[j] == 0) && (V[i] != 0 && V[j] % V[i] == 0) )
        {
            elemento = 2;
        }
        else
        {
            if (V[j] != 0 && V[i] % V[j] == 0)
            {
                elemento = 1;
            }
            else
            {
                elemento = -1;
            }
        }
    }
    else
    {
        elemento = 0;
    }
    return elemento;
}

void completar_matx (const int V[9], int M[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            M[i][j] = completar_elemento(V, i, j);
        }
    }
}

void imprimir_matx (const int M[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("|\t");
        for (int j = 0; j < 3; j++)
        {
            printf("%i\t", M[i][j]);
        }
        printf("|\n");
    }
}
