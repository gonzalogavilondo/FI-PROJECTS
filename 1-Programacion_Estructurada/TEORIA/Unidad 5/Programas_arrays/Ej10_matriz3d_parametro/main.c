#include <stdio.h>
#include <locale.h>

void imprimir_matriz(short int matrix[][3][4], int, int, int);
void ingresar_valores(short int matrix[][3][4], int, int, int);

int main()
{
    short int iValores[2][3][4];

    setlocale(LC_ALL,"spanish");

    printf("Tama�o de la matriz = %d bytes\n", sizeof(iValores));

    /**** acceso a los datos: mostrar las posiciones de memoria a medida que se modifican ****/
    ingresar_valores(iValores, 2, 3, 4);

    imprimir_matriz(iValores, 2, 3, 4);

    return 0;
}

void imprimir_matriz(short int matrix[][3][4], int paginas, int filas, int columnas)
{
    puts("\nValores ingresados\n");

    for(int p=0; p<paginas; p++)
    {
        printf("\n\tP�gina n�mero %d:\n",p+1);
        for(int f=0; f<filas; f++)
        {
            printf("\n\t\t");
            for(int c=0; c<columnas; c++)
            {
                printf("%5d  ", matrix[p][f][c]);
            }
        }
        printf("\n");
    }
    puts("\n");
}

void ingresar_valores(short int matrix[][3][4], int paginas, int filas, int columnas)
{
    puts("\nIngreso de valores de una matriz tridimensional\n\n");

    for(int p=0; p<paginas; p++)
    {
        printf("\tP�gina n�mero %d:\n",p+1);
        for(int f=0; f<filas; f++)
        {
            printf("\t\tFila n�mero %d:\n",f+1);
            for(int c=0; c<columnas; c++)
            {
                printf("\t\t\tColumna %d ([%d][%d][%d]) = ", c, p, f, c);
                scanf("%hd",&matrix[p][f][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
