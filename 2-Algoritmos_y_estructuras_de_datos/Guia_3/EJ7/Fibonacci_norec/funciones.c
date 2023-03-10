#include "declaraciones.h"

int fibonacci(int n)
{
     int first = 1;
     int second = 1;
     int sum = 1;
     int i;

     for(i = 2; i <= n; i++)
     {
         sum = first + second;
         first = second;
         second = sum;
     }

     return(sum);
}
