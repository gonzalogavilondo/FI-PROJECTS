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

void OrdInsercion(int *vector, int cnt_elementos)
{
    int i, j, aux;

    for(i = 1; i < cnt_elementos; i++)
    {
        j = i;
        aux = vector[i]; //Guarda el valor que quiere insertar en una variable auxiliar.
        while(j > 0 && aux < vector[j-1]) //Recorre de derecha a izquierda
        {
            vector[j] = vector[j-1];      //Se detiene cuando el anterior ya NO es mayor.
            j--;                          //En cada caso, corre el numero a la derecha.
        }
        vector[j] = aux;                  //Al terminar, coloca el valor en su posicion final.
    }

}
