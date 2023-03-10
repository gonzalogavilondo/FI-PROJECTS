#include "declaraciones.h"

int main()
{
    //Declaramos el nodo a estructura
    list *lista;
    lista = (list*)malloc(sizeof(list));
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

    //Borramos un elemento elemento e imprimimos
    printf("\nLuego de Borrar el primero\n");
    deletee(&lista, 1);
    traverse(lista);

    //Extraemos sin eliminar e imprimimos
    printf("\nLuego de Extraer el segundo sin borrarlo\n");
    traverse(lista);
    printf("El valor extraido es: %d\n", get(lista, 2));

    //Intercambiamos valores e imprimimos
    printf("\nLuego de Intercambiar el primero con el tercero\n");
    intercambiar(lista, 1, 3);
    traverse(lista);

    //Buscamos un valor
    if (search(&lista, 3))
    {
        printf("\nSe encuentra el 3 en la lista\n");
    }
    else
    {
        printf("No se encuentra el 20 en la lista\n\n");
    }

    //Buscamos el mayor
    printf("\nLa posicion del mayor es: %i\n\n", posMayor(lista));

    //Verificamos si la lista esta ordenada luego de todos los cambios hechos
    if (sort(lista) == 1)
    {
        printf("La lista esta ordenada de menor a mayor\n\n");
    }
    else
    {
        printf("\nLa lista no esta ordenada de menor a mayor\n");
    }

    //Liberamos memoria
    liberar_memoria(lista);
    return 0;
}
