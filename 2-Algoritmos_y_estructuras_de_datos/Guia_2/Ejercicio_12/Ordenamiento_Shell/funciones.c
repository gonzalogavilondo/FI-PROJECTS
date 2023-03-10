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

void OrdShell(int *vector, int cnt_elementos)
{
    int intervalo, i, j, k, aux;

    intervalo = cnt_elementos/2;

    while(intervalo >= 1)
    {
        for(i = 0; i+intervalo < cnt_elementos; i++)
        {
            j = i;
            while(j >= 0)
            {
                k = j + intervalo;
                if(vector[j] > vector[k])   //Si se cumple esta condicion, intercambio los valores.
                {
                    aux = vector[j];
                    vector[j] = vector[k];
                    vector[k] = aux;

                    j = j - intervalo;
                }
                else
                {
                   j = -1;
                }
            }
        }
        intervalo = intervalo/2;            //Divide denuevo el intervalo a la mitad.
    }
}
