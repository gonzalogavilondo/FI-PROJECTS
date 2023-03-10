#include "declaraciones.h"

void imprimir_vector_char(char vector[MAX])
{
    printf("| ");
    for(int j = 0; j < MAX; j++)
    {
        printf("%c ", vector[j]);
    }
    printf("|\n\n");

}
void imprimir_vector_int(int vector[7])
{
    printf("| ");
    for(int j = 0; j < 7; j++)
    {
        printf("%d ", vector[j]);
    }
    printf("|\n\n");

}

void imprimir_matriz (char matriz[FILS][COLS])
{
    for (int i = 0; i < FILS; i++)
    {
        printf("|\t");
        for (int j = 0; j < COLS; j++)
        {
           printf("%c \t", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    puts("\n");
}

void mapear_matriz(char matriz[FILS][COLS], char vector[MAX])
{
    int k = 0;
    for (int i = 1; i < FILS; i++)
    {
        for (int j = 0; j < (i); j++)
        {
            vector[k] = matriz[i][j];
            k++;
        }

    }
}

int codificacion(char vector[MAX])
{
    PILA pila;
    inicializar_pila(&pila);
    int aux;

    for (int i = 0; i < MAX; i++)
    {
        switch (vector[i])
        {
            case '{':
                push(&pila, vector[i]);
                break;
            case '[':
                push(&pila, vector[i]);
                break;
            case '(':
                push(&pila, vector[i]);
                break;
            case ')':
                peek(&pila, &aux);
                if (aux == '(')
                {
                    pop(&pila, &aux);
                }
                break;
            case ']':
                peek(&pila, &aux);
                if (aux == '[')
                {
                    pop(&pila, &aux);
                }
                break;
            case '}':
                peek(&pila, &aux);
                if (aux == '{')
                {
                    pop(&pila, &aux);
                }
                break;
        }
    }
    if(isEmpty(&pila) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void comprobar(int codificar)
{
    if(codificar == 1)
    {
        printf("La expresion esta correctamente balanceada.\n");

    }
    else
    {
        printf("La expresion no esta correctamente balanceada.\n");
    }
}

void char_a_entero(char vector[MAX], int vectop[7]) //Guardo los operandos que hay en vector en vectop como enteros.
{
    int cnt = 0;
    char aux[1]; //Auxiliar donde voy a guardar como caracter los operandos.
    for(int i = 0; i < MAX; i++)
    {
        if(vector[i] >= '0' && vector[i] <= '9') //Condicion para estar entre los operandos, ya que los caracteres especiales tienen numeros mas grandes en ASCII.
        {
            aux[0] = vector[i];
            vectop[cnt] = atoi(aux);
            cnt++;
        }
    }
}

int maximo(int vectop[MAX], int inf, int sup)
{
     if (inf == sup)
     {
         return (vectop[inf]);
     }
     int medio = (inf + sup)/2;
     int maxIzq = maximo(vectop, inf, medio);
     int maxDer = maximo(vectop, medio+1, sup);

     if(maxIzq > maxDer)
     {
         return(maxIzq);
     }
     else
     {
         return(maxDer);
     }
}

int minimo(int vectop[MAX], int inf, int sup)
{
     if (inf == sup)
     {
         return (vectop[inf]);
     }
     int medio = (inf + sup)/2;
     int minIzq = minimo(vectop, inf, medio);
     int minDer = minimo(vectop, medio+1, sup);

     if(minIzq < minDer)
     {
         return(minIzq);
     }
     else
     {
         return(minDer);
     }
}

int busqueda_secuencial(int vectop[], int condicion, int dim)
{
    int posicion = 0;
    for(int i = 0; i < dim; i++)
    {
        if(vectop[i] == condicion)
        {
            posicion = i;
        }
    }
    return posicion;
}

void couting(int vectord[7], int vectop[7], int min, int max)
{
    //vectord es donde voy a guardar la cantidad de repeticiones de cada numero del vector, tiene que ser
    //de tamaño = rango = max - min + 1.
    int aux[8] = {0}; //Vector auxiliar
    int salida [7] = {0}; //Vector que va a tener la lista ordenada de forma ascendente.
    int rango = (max - min) + 1;
    for(int i = 0; i < 7; i++) //Recorremos vectop
    {
        aux[vectop[i] - min]++; //Guardo la cantidad de veces que se encuentra cada elemento de vectop en el vector auxiliar.
    }
    for(int i = 1; i < rango; i++)
    {
        aux[i] += aux[i-1];
    }
    for(int i = 7-1; i >= 0; i--)
    {
        salida[aux[vectop[i] - min]-1] = vectop[i];
        aux[vectop[i] - min]--;
    }
    int cnt = 0; //Contador para almacenar de mayor a menor.
    for(int i = 6; i >= 0; i--) //Almaceno la salida en vectord ordenandolo de mayor a menor.
    {
        vectord[cnt] = salida[i];
        cnt++;
    }
}

void cargar_lista(int vectop[7], LISTA *lista)
{
    for(int i = 0; i < 7; i++)
    {
        insert(vectop[i], i, lista);
    }
}

void inicializar_lista(LISTA *lista)
{
    lista->rear = 0;
}

int posmin_lista(LISTA *pS) //Retorna la posicion del nodo con mayor informacion.
{
    int res = 0;
    int pos = 0;
    res = minimo(pS->A, 0, pS->rear);
    pos = busqueda_secuencial(pS->A, res, pS->rear + 1);

    return pos;
}
