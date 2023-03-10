#include "declaraciones.h"

int factorial_nr(int num)
{
    int factorial = 1;

    for(int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int factorial_r(int num)
{
    if(num > 0)
    {
        return (num*(factorial_r(num-1)));
    }
    else
    {
        return 1;
    }

}
