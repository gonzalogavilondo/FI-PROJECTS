/***** forma 1 de pasar un vector como par�metro
       utilizando #define para el tama�o         ****/

#include <stdio.h>

#define TAM 5           // tama�o del vector

void imprimir_vector(short int vector[]);    // direcci�n del vector
void leer_vector(short int []);              // tambi�n es una forma v�lida, no tiene el nombre

int main()
{
    short int iValores[TAM];  // ver valores y memoria

    leer_vector(iValores);
    imprimir_vector(iValores);

    return 0;
}

void leer_vector(short int vector[])
{
    printf("\nIngrese los valores del vector:\n\n");
    for(int cnt=0; cnt<TAM; cnt++)
    {
        printf("\tiValores[%d] = ", cnt);
        scanf("%hd", &vector[cnt]);
    }

    return ;
}

void imprimir_vector(short int vector[])
{
    printf("\n\n\nImpresion del vector:\n\n");
    for(int cnt=0; cnt<TAM; cnt++)
    {
        printf("\tiValores[%d] = %3d\n", cnt, vector[cnt]);
    }
    puts("\n");
}
