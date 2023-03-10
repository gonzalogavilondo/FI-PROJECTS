#include <stdio.h>
#include <stdlib.h>

void my_recursive_function(int *arr, int val, int idx, int len)
{
    if(idx == len)
    {
        printf("-1");
        return ;
    }
    if(arr[idx] == val)
    {
        printf("%d",idx);
        return;
    }
    my_recursive_function(arr,val,idx+1,len);
}
int main()
{
    int array[10] = {7, 6, 4, 3, 2, 1, 9, 5, 0, 8};
    int value = 2;
    int len = 10;
    my_recursive_function(array, value, 0, len);
    return 0;
}

//ACLARAR PORQUE IMPRIME 4
