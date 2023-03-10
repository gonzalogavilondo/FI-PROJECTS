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

void OrdSeleccion(int *vector, int cnt_elementos)
{
    int min, i, j, aux;

    for(i = 0; i < cnt_elementos; i++)
    {
        //Busco al minimo y lo asigno a "min"
        min = i;
        for(j = i+1; j < cnt_elementos; j++)
        {
            if(vector[j] < vector[min])
            {
                min = j;
            }
            //Al terminar, "min" tiene el indice del menor elemento.
        }
        if(i != min)
        {
            //Intercambio los valores
            aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
        }
    }

}
