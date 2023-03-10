#include <stdio.h>
#include <stdlib.h>

int main()
{
    short int matriz[2][3] = {{1,2,3},
                              {4,5,6}};
    char letra='A';
    char let='B';

    /**** se imprimen todos los valores para controlar ****/
    for(int i=0; i<2; i++)          // declara la variable en el lazo!!!
    {
        for(int j=0; j<3; j++)      // declara la variable en el lazo!!!
        {
            printf("\t%d",matriz[i][j]);
        }
        puts("\n");                 // finaliza una fila
    }

    /**** ver como se modifica memoria ****/
    matriz[0][0] = (short int)letra; // matriz[0][0] seria = 65, en memoria aparece en hexadecimal que es: 41
    matriz[0][1] = (short int)let;  // matriz[0][1] seria = 66, en memoria aparece en hexadecimal que es: 4

    //No imprime los valores de i, j ya que estan declarados dentro de los lazos for y una vez que salen, "mueren".

    /**** ingreso un short como entero ==> INVADE MEMORIA ****/
    //scanf("%d",&matriz[1][1]);       // el compilador lanza un warning !!!
    scanf("%hd",&matriz[1][1]);      // ingresa como short ==> OK
    //Si quiero imprimir puedo imprimir como %d, solo para scanear tira el warning.

    /**** se imprimen todos los valores para controlar ****/
    puts("\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        puts("\n");                  // finaliza una fila
    }

    return 0;
}
