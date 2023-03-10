#include "declaraciones.h"

void verificar_apertura(FILE *informacion)
{
    if(informacion == NULL)
    {
        perror("No se ha podido abrir el archivo");
        exit(2); //Codigo de error
    }

}

int *recuperar_datos(char archivo_entrada[], int *cnt_codigos)
{
    int *vector = NULL;
    FILE *fr; //Archivo de lectura, de donde voy a levantar los datos.

    fr = fopen(archivo_entrada, "r");
    verificar_apertura(fr);

    fscanf(fr, "%d%*c", cnt_codigos);
    vector = (int *)malloc(*cnt_codigos*sizeof(int)); //Reservo memoria para la cantidad de codigos.
    for(int cnt = 0; cnt < (*cnt_codigos); cnt++)
    {
        fscanf(fr, "%d%*c", &vector[cnt]); //Almaceno cada codigo en el vector
    }

    //Cierro el archivo de lectura
    fclose(fr);

    return vector;
}

int *combinar(int *entrada_1, int *entrada_2, int *entrada_3, int *cnt_codigos1, int *cnt_codigos2, int *cnt_codigos3)
{
    int j, k, l;
    j = 0;
    k = 0;
    l = 0;

    int *vector = NULL;
    vector = (int *)malloc((*cnt_codigos1 + *cnt_codigos2 + *cnt_codigos3)*sizeof(int));
    for(int i = 0; i < *cnt_codigos1; i++)
    {
        vector[i] = entrada_1[j];
        j++;
    }
    for(int i = *cnt_codigos1; i < (*cnt_codigos1 + *cnt_codigos2); i++)
    {
        vector[i] = entrada_2[k];
        k++;
    }
    for(int i = (*cnt_codigos1 + *cnt_codigos2); i < (*cnt_codigos1 + *cnt_codigos2+ *cnt_codigos3); i++)
    {
        vector[i] = entrada_3[l];
        l++;
    }

    return vector;
}

void menu(int *salida, int cnt_codigost)
{
    int opcion = 0;
    int low = 0;

    do
    {
        printf("%cQue metodo de ordenamiento desea utilizar? <MS = 1/QS = 2>: ", 168);
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            puts("\nCODIGOS DE LA ZONA 1 ORDENADOS POR MERGE-SORT:\n");
            //Ordenamos mediante merge-sort
            mergesort(salida, low, cnt_codigost);
        }
        else if(opcion == 2)
        {
            puts("\nCODIGOS DE LA ZONA 1 ORDENADOS POR QUICK-SORT:\n");
            //Ordenamos mediante Quick-sort
            quicksort(salida, low, cnt_codigost - 1);
        }
        else
        {
            puts("Opcion invalida.\n");
            system("pause");
            system("cls || clear");
        }

    }while(opcion != 1 && opcion != 2);

}

void grabar_datos(int *vector, int cnt_codigos, FILE *salida)
{
    for(int cnt = 0; cnt < cnt_codigos; cnt++)
    {
        fprintf(salida, "%d\n", vector[cnt]);
    }
}

void imprimir_datos(int *vector, int cnt_codigos)
{
    for(int cnt = 0; cnt < cnt_codigos; cnt++)
    {
        printf("%d\n", vector[cnt]);
    }
}
