#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int valor = 5;
    int *pSimple;                 // Puntero a entero
    int **pDoble;                 // Puntero a puntero
    int mat[3][4] = { {0,  1,  2,  3},
                      {4,  5,  6,  7},
                      {8,  9, 10, 11} };
    char **cadenas;

    pSimple = &valor;
    pDoble = &pSimple;
    printf("valor = %d, *pSimple = %d, **pDoble = %d\n", valor, *pSimple, **pDoble);

    pDoble = (int **)malloc(3*sizeof(int *));
    *pDoble = (int *)&mat[0];
    *(pDoble + 1) = (int *)&mat[1];
    pDoble[2] = (int *)&mat[2];

    valor = *(*(pDoble + 1) + 2);
    valor = pDoble[1][2];

    /**** almacenar 5 cadenas de caracteres de longitudes 5, 7, 12, 20 y 15 ****/
    cadenas = (char **)malloc(5*sizeof(char));
    *cadenas = (char *)malloc(5*sizeof(char));
    *(cadenas+1) = (char *)malloc(7*sizeof(char));
    *(cadenas+2) = (char *)malloc(12*sizeof(char));
    *(cadenas+3) = (char *)malloc(20*sizeof(char));
    *(cadenas+4) = (char *)malloc(15*sizeof(char));

    strcpy(*cadenas,"Sr.");            // recordar el 0x0
    strcpy(*(cadenas+1),"Pedro");
    strcpy(*(cadenas+2),"Picapiedra");
    strcpy(*(cadenas+3),"Piedra Dura 2345");
    strcpy(cadenas[4],"Prehistoria");

    return 0;
}
