#include "declaraciones.h"

int *reservar_memoria(int cnt_elementos)
{
    int *vector = NULL;

    vector = (int *)calloc(cnt_elementos, sizeof(int));

    if(vector == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    return vector;
}

void completar_vector(int *vector, int cnt_elementos)
{
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("\t-COMPLETE EL VECTOR-\n\n");
        imprimir_vector(vector, cnt_elementos);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%d", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}

void imprimir_vector(int *vector, int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%d\t", vector[j]);
    }
    printf("|\n\n");

}

void ordenar_vector(int *vector, int cnt_elementos)
{
    //METODO BURBUJA
    int aux = 0;

    for(int j = 0; j < cnt_elementos - 1; j++)
    {
        if(vector[j] > vector[j+1])
        {
            aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
        }

    }

}

int multiplo_5(int *vector, int *mult5, int cnt_elementos)
{
    int j = 0;
    int cnt_mult5 = 0;

    for(int i = 0; i < cnt_elementos; i++)
    {
        if(vector[i] % 5 == 0)
        {
            mult5[j] = vector[i];
            j++;
            cnt_mult5++;
        }
    }
    return cnt_mult5;
}
void reallocar_memoria(int *mult5, int cnt_mult5)
{
    mult5 = (int*)realloc(mult5, cnt_mult5*sizeof(int));

    if(mult5 == NULL)
    {
        printf("No se ha podido reallocar memoria.\n");
        exit(2);
    }

}
