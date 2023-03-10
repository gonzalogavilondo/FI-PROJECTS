#include<stdlib.h>
#include<stdio.h>

int int_cmp(const void *ptr1, const void *ptr2);           // prototipo de la función

int main()
{
    int (*cmp)(const void *, const void *) = int_cmp;      // puntero a la función int_cmp
    int i,
        numero = 7,
        arr[] = {5, 4, 3, 2, 10, 1, 7};

    for(i=0; i<numero; i++)
    {
        printf("%d ", arr[i]);
    }

    //qsort(arr, numero, sizeof(int), int_cmp);              // usa el nombre de la función
    //qsort(arr, numero, sizeof(int), &int_cmp);             // forma no recomendable
    qsort(arr, numero, sizeof(int), cmp);                  // usa puntero a la función

    puts("\n");
    for(i=0; i<numero; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("\n");

    return 0;
}

int int_cmp(const void *ptr1, const void *ptr2)
{
    int a = *(int *)ptr1,
        b = *(int *)ptr2;

    return (a > b) ? 1 : ( (a == b) ?  0 :  -1);               // menor a mayor
    //return (a < b) ? 1 : ( (a == b) ?  0 :  -1);               // mayor a menor
}
