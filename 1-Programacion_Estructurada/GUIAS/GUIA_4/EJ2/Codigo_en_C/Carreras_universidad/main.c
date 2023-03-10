#include <header.h>

int main()
{
	int matricula = 0;
	float promedio = 0.0;
	int semestre = 0;

	printf("Escriba su matricula: ");
	scanf("%i",&matricula);
	printf("\nEscriba su promedio: ");
	scanf("%f",&promedio);
	printf("\nEscriba el semestre en el que se inscribio: ");
	scanf("%i",&semestre);
	asignacion_carrera(matricula, promedio, semestre);

	return 0;
}
