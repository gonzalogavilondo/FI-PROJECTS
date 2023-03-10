#include "myInclude.h"

int reserva_memoria(datos_alumno *alumno[], int cantidad, int longitud)
{
    int cnt;

    for(cnt=0; cnt<cantidad; cnt++)
    {
        alumno[cnt] = (datos_alumno *)malloc(sizeof(datos_alumno));
        alumno[cnt]->nombre.nombre = (char *)malloc(longitud*sizeof(char));
        (*alumno[cnt]).nombre.apellido = (char *)malloc(longitud*sizeof(char));

        if(alumno[cnt] && alumno[cnt]->nombre.nombre && alumno[cnt]->nombre.apellido)
        {
            ingreso_datos(alumno[cnt], longitud);
        }
        else
        {
            return -1;
        }
    }

    return 0;
}

void ingreso_datos(datos_alumno *alumno, int longitud)
{
    char temp[20];

    system("cls");
    fflush(stdin);
    printf("\nIngrese los siguientes datos: ");
    printf("\n\n\tTitulo (max 4 caracteres) = ");
    scanf("%[^\n]%*c", temp);
    memmove(alumno->nombre.titulo, temp, 4);
    alumno->nombre.titulo[4]=0;

    printf("\n\tNombre (max %d caracteres): ", --longitud);
    scanf("%[^\n]%*c", temp);
    memmove(alumno->nombre.nombre, temp, longitud);
    alumno->nombre.nombre[longitud]=0;

    printf("\n\tApellido (max %d caracteres): ", longitud);
    scanf("%[^\n]%*c", temp);
    memmove(alumno->nombre.apellido, temp, longitud);
    alumno->nombre.apellido[longitud]=0;

    fflush(stdin);
    printf("\n\tNumero de matricula = ");
    scanf("%d", &alumno->matricula);
    fflush(stdin);
    printf("\n\tDia de nacimiento = ");
    scanf("%d", &alumno->nacim.day);
    fflush(stdin);
    printf("\n\tMes de nacimiento = ");
    scanf("%d", &(*alumno).nacim.month);
    fflush(stdin);
    printf("\n\tAnio de nacimiento = ");
    scanf("%d", &alumno->nacim.year);
}

void imprime_datos(datos_alumno *alumno[], int cantidad)
{
    for(int cnt=0; cnt<cantidad; cnt++)
    {
        printf("\n\n%s %s %s, mat: %d, nac:%d/%d/%d", alumno[cnt]->nombre.titulo,
               alumno[cnt]->nombre.nombre, alumno[cnt]->nombre.apellido, alumno[cnt]->matricula,
               alumno[cnt]->nacim.day, (*alumno[cnt]).nacim.month, alumno[cnt]->nacim.year);
    }
}

void libera_memoria(datos_alumno *alumno[], int dimension)
{
    for(int cnt=0; cnt<dimension; cnt++)
    {
        free(alumno[cnt]->nombre.nombre);
        free((*alumno[cnt]).nombre.apellido);
        free(alumno[cnt]);
    }
}
