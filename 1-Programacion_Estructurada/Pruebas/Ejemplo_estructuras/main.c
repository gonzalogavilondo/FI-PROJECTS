#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct corredor
{
    char nombre[20];
    int edad;
    char sexo[20];
    char club[20];

}corredor1;


int main()
{
    char categoria[20];

    printf("Digite su nombre: ");
    gets(corredor1.nombre);
    printf("Digite su edad: ");
    scanf("%i", &corredor1.edad);
    fflush(stdin);
    printf("Digite su sexo: ");
    gets(corredor1.sexo);
    printf("Digite su club: ");
    gets(corredor1.club);

    //Condicion de categoria

    if(corredor1.edad <= 18)
    {
        strcpy(categoria, "Juvenil"); //categoria = juvenil
    }
    else if(corredor1.edad <= 40)
    {
        strcpy(categoria, "Senior");

    }
    else
    {
        strcpy(categoria, "Veterano");
    }

    //Imprimir datos
    printf("\n-Datos del corredor-\n");
    printf("\nCategoria: %s", categoria);
    printf("\nNombre: %s", corredor1.nombre);
    printf("\nEdad: %i", corredor1.edad);
    printf("\nSexo: %s", corredor1.sexo);
    printf("\nClub: %s", corredor1.club);
    printf("\n");


   system("pause");

return 0;

}
