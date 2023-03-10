#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0;
	int salir = 0;
	do
    {
        system("cls");
		if (((salir >= 0) && (salir <= 1)))
		{
		    printf("Escriba un numero: ");
			scanf("%i",&num);
			if (num %2 == 0)
			{
			    printf("El numero %i es par\n", num);
			}
            else
            {
                printf("El numero %i es impar\n", num);
			}
		}
		else
        {
            printf("Digite una opcion correcta.\n");
		}
		printf("Si desea volver presione 1, para salir digite 0: ");
		scanf("%i",&salir);
	} while (salir != 0);

    return 0;
}
