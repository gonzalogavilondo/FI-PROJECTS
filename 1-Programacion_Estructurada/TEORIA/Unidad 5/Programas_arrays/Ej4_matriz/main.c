#include <stdio.h>
#include <locale.h>

int main()
{
    short int iValores[][3] = { {1,2,3},
                                {4,5,6}};
                                        // ver valores y memoria
    int i, j;                              // usados para los lazos

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("el valor del elemento [%i][%i] es: %i\n\n", i, j, iValores[i][j]);
            printf("Y su almacenamiento en memoria es: %i y en hexadecimal %#X\n\n", &iValores[i][j], &iValores[i][j]);
        }

    }
    /**** no se puede dejar la segunda dimensión sin valor ****/
    //short int iValores[][] = { {1,2,3}, {4,5,6}};  // error!!!

    setlocale(LC_ALL,"spanish");

    printf("Tamaño de la matriz = %d bytes\n\n\n", sizeof(iValores));

    /**** para imprimir la matriz hay que recorrer TODOS los valores  ****/
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("iValores[%d][%d] = %3d, guardado en %p\n", i, j, iValores[i][j], &iValores[i][j]);
        }
        puts("\n");              // finaliza cada fila
    }

    /**** se puede modificar un sólo valor de manera específica (verificar en la memoria) ****/
    iValores[1][0] = 254;         // recalcar los índices (fila 2, columna 1)

    /**** acceso a los datos: mostrar las posiciones de memoria a medida que se modifican ****/

    // 1 - ANALIZAR QUE RESULTADO SE OBTIENE
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==j)
            {
                iValores[i][j] = (i+1)*10 + j + 1;
            }
            else
            {
                iValores[i][j] = 0;
            }
        }
    }
    // imprimo resultados
    puts("\nNuevos valores de la matriz: \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("\t%3d", iValores[i][j]);
        }
        puts("\n");
    }

    // 2 - ANALIZAR QUE RESULTADO SE OBTIENE
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i!=j)
            {
                iValores[i][j]= (i+1)*100 + j + 1;
            }
        }
    }
    // imprimo resultados
    puts("\nNuevos valores de la matriz: \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("\t%3d", iValores[i][j]);
        }
        puts("\n");
    }

    // analizar que valores se imprimen
    puts("\nNuevos valores de la matriz: \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("\t%3d", iValores[j][i]);
        }
        puts("\n");
    }

    return 0;
}

