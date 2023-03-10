/**** Se muestran varias maneras de inicializar las componentes de la matriz ****/

#include <stdio.h>

int main()
{
    /** forma por defecto para declarar la matriz e ingresar sus valores **/
    short int iValores[2][3][4];

    // la centena representa la hoja, la decena la fila y la unidad la columna
    for(int k=0; k<2; k++)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<4; j++)
            {
                iValores[k][i][j] = 100*(k+1)+10*(i+1)+(j+1);
            }
        }
    }                  // valores de i, j y k? ==> alcance de las variables

    /** almacena los valores en forma consecutiva comenzando por la última dimensión **/
/*    short int iValores[2][3][4]= { 100, 101, 102, 103,
                                   104, 105, 106, 107,
                                   108, 109, 110, 111,

                                   200, 201, 202, 203,
                                   204, 205, 206, 207,
                                   208, 209, 210, 211 };
*/
    /** almacena los primeros valores de cada fila, cada { abre una dimensión **/
/*    short int iValores[2][3][4]= { { { 100},                   // fila 1 sólo 1 valor
                                     { 110, 111},              // fila 2 sólo 2 valores
                                     { 120, 121, 122, 123} },  // fila 3 completa

                                   { { 200, 201, 202, 203},
                                     { 210},
                                     { 220, 221, 222, 223} } };
*/
    /** almacena sólo valores específicos (útil si hay muchos nulos) **/
/*    short int iValores[2][3][4]= { { [0][0]=100, [1][1]=105, [2][2]=110 }, // página 0
                                   { { 200, 201, 202, 203},                // página 1, fila 0
                                     { 210},                               // página 1, fila 1
                                     { 220, 221, 222, 223} } };            // página 1, fila 2
*/
    /**** se imprimen las 2 hojas ****/
    puts("\nValores ingresados\n");
    for(int p=0; p<2; p++)
    {
        printf("\n\tPagina numero %d:\n",p+1);
        for(int f=0; f<3; f++)
        {
            printf("\n\t\t");
            for(int c=0; c<4; c++)
            {
                printf("%5d  ", iValores[p][f][c]);
            }
        }
        printf("\n");
    }
    puts("\n");

    return 0;
}
