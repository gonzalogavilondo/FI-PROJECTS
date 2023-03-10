#include <header.h>

void asignacion_carrera(int matricula, float promedio, int semestre)
{
    if (((semestre>6) && (promedio>8.8)))
    {
		printf("\nAceptado.\n");
		printf("Puede estudiar INGENIERIA.\n");
		printf("La matricula del alumno es: %i\n",matricula);
	}
	else
    {
        if (((semestre>=6) && (promedio>8.5)))
		{
		    printf("\nAceptado.\n");
			printf("Puede estudiar MEDICINA\n");
			printf("La matricula del alumno es: %i\n",matricula);
		}
        else
        {
            if (((semestre>5) && (promedio>=8.3)))
            {
                printf("\nAceptado.\n");
				printf("Puede estudiar LICENCIATURA\n");
				printf("La matricula del alumno es: %i\n",matricula);
			}
			else
            {
                if (((semestre>=3) && (promedio>=7.8)))
                {
					printf("\nAceptado.\n");
					printf("Puede estudiar TECNICO\n");
					printf("La matricula del alumno es: %i\n",matricula);
				}
				else
                {
                    printf("\nNo puede inscribirse a ninguna carrera de esta universidad.");
                }
			}
		}
	}
}
