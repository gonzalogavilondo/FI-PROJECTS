#include "listas.h"

int main()
{
    //Declaramos el nodo a estructura
    NODO *lista;
    lista = (NODO*)malloc(sizeof(NODO));
    //Inicializamos
    inicializar_lista(&lista);

    //Insertamos valores         NOTA: AL ASIGNAR VALORES SIEMPRE EL CONTADOR DEBE EMPEZAR DESDE 1.
    for(int i = 1; i < 5 ; i++)
    {
        insert(&lista, i,i);
    }
    //Imprimimos
    puts("Lista original");
    traverse(lista);
    ProcessArray(lista, 6, 4);

    //Liberamos memoria
    liberar_memoria(lista);
    return 0;
}

NODO ProcessArray(NODO *listA, int x, int n)
{
    int i, j, k;
    i = 0;
    j = n-1;
    do
    {
        k = (i+j)/2;
        if (x <= listA[k])
        {
            j = k-1;
        }
        if(listA[k] <= x)
        {
            i = k+1;
        }
    }while(i <= j);

     if (listA[k] == x)
     {
        return(k);
     }
     else
     {
        return -1;
     }
}
