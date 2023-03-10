#include <stdio.h>
#include <locale.h>

void imprimir_matriz(short int [][3], int , int );       // dirección de la matriz y dimensiones
void analisis(short int matrix[][3], int filas, int columnas, int opcion);

int main()
{
    short int iValores[2][3] = { {1,2,3},
                                 {4,5,6}};  // ver valores y memoria

    setlocale(LC_ALL,"spanish");

    printf("Tamaño de la matriz = %d bytes\n\n\n", sizeof(iValores));

    // para imprimir la matriz hay que recorrer TODOS los valores
    imprimir_matriz(iValores, 2, 3);

    /**** acceso a los datos: mostrar las posiciones de memoria a medida que se modifican ****/
    // 1 - ANALIZAR QUE RESULTADO SE OBTIENE
    analisis(iValores, 2, 3, 1);
    // 2 - ANALIZAR QUE RESULTADO SE OBTIENE
    analisis(iValores, 2, 3, 2);

    return 0;
}

void imprimir_matriz(short int matrix[][3], int filas, int columnas)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
//            printf("iValores[%d][%d] = %3d, guardado en %p\n", i, j, matrix[i][j], matrix[i][j]);
            printf("\tiValores[%d][%d] = %3d", i, j, matrix[i][j]);
        }
        puts("\n");
    }
}

void analisis(short int matrix[][3], int filas, int columnas, int opcion)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            switch (opcion)
            {
                case 1:
                    if(i==j)
                    {
                        matrix[i][j] = (i+1)*10 + j + 1;
                    }
                    else
                    {
                        matrix[i][j] = 0;
                    }
                    break;
                case 2:
                    if(i!=j)
                    {
                        matrix[i][j] = (i+1)*100 + j + 1;
                    }
                    break;
            }
        }
    }
    // imprimo resultados
    puts("\nNuevos valores de la matriz: \n");
    imprimir_matriz(matrix, 2, 3);
}

