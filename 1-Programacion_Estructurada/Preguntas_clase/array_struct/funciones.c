#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaraciones.h"

void verificar_apertura(FILE *falumnos)
{
    if(falumnos == NULL)
    {
        perror("No se ha podido abrir el archivo");
        exit(5);
    }
}

int elegir_apertura(FILE *falumnos)
{
    int opcion = 0;

    do
    {
        puts("1) Grabar en memoria.\n");
        puts("2) Grabar en archivo de texto.\n");
        puts("3) Grabar en archivo binario.\n");
        puts("4) Salir.\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        if(opcion == 4)
        {
            exit(0);
        }
        else
        {
            if(opcion > 4 || opcion < 1)
            {
                puts("\nIngrese una opcion correcta.");
                system("pause");
                system("cls || clear");

            }
        }

    }while(opcion > 4 || opcion < 1);

    return opcion;
}

datos_alumno *reservar_memoria(int16_t cnt_alumnos, int16_t max_nombre, int16_t max_materias)
{
    datos_alumno *ptr;
    ptr = (datos_alumno *)malloc(cnt_alumnos*sizeof(datos_alumno)); //Guardo memoria para todos los alumnos
    if(ptr == NULL)
    {
        printf("No se ha podido reservar memoria.\n");
        exit(1);
    }
    else
    {
        for(int cnt = 0; cnt < cnt_alumnos; cnt++)
        {
            ptr[cnt].nombre = (char *)malloc(max_nombre*sizeof(char));
            ptr[cnt].materia = (catedras *)malloc(max_materias*sizeof(catedras));
            for(int loop = 0; loop < max_materias; loop++)
            {
                ptr[cnt].materia[loop].nombre = (char *)malloc(max_nombre*sizeof(char));
            }
        }
    }

    return ptr;
}

void liberar_memoria(datos_alumno *ptr, int16_t cnt_alumnos)
{
    for(int cnt = 0; cnt < cnt_alumnos; cnt++)
    {
        for(int loop = 0; loop < ptr[cnt].cnt_materias; loop++)
        {
            free(ptr[cnt].materia[loop].nombre);
        }
        free(ptr[cnt].nombre);
        free(ptr[cnt].materia);
    }
    free(ptr);
}
void ingresar_datos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_nombre, int16_t max_materias)
{
    static int total_anterior = 0;
    int cnt = 0;
    char barra;
    char *pch;

    for(cnt = total_anterior; cnt < (cnt_alumnos); cnt++)
    {
        //Nombre
        fflush(stdin);
        printf("Ingrese el nombre del %i%c alumno: ", cnt+1, 167);
        fgets(alumnos[cnt].nombre, max_nombre, stdin);
        pch = strchr(alumnos[cnt].nombre, 10); //El 10 es el \n en ASCII. Si lo encuentra reemplaza el nueva linea por \0(fin de linea).
        if(pch != NULL)
        {
            *pch = '\0';
        }
        alumnos[cnt].long_nombre = strlen(alumnos[cnt].nombre); //Longitud de cada nombre, el +1 es por el \0
        /*
        alumnos[cnt].nombre = (char*)realloc((char*)alumnos[cnt].nombre, (alumnos[cnt].long_nombre)*sizeof(char));//Reasigno memoria para cada nombre de cada persona
        */

        //Matricula
        printf("Ingrese la matricula del %i%c alumno: ", cnt+1, 167);
        scanf("%i", &alumnos[cnt].matricula);
        printf("Ingrese la cantidad de materias del %i%c alumno: ", cnt+1, 167);
        scanf("%i", &alumnos[cnt].cnt_materias);

        //Estructura catedras

        for(int i = 0; i < alumnos[cnt].cnt_materias; i++)
        {
            fflush(stdin);
            printf("Ingrese el nombre de la %i%c materia: ", i+1, 167);
            fgets(alumnos[cnt].materia[i].nombre, max_nombre, stdin);
            pch = strchr(alumnos[cnt].materia[i].nombre, 10); //El 10 es el \n en ASCII. Si lo encuentra reemplaza el nueva linea por \0(fin de linea).
            if(pch != NULL)
            {
                *pch = '\0';
            }
            alumnos[cnt].materia[i].long_nombre_mat = strlen((alumnos[cnt].materia[i].nombre)); //Longitud de cada nombre de cada materia, el +1 es por el \0
            /*
            alumnos[cnt].materia[i].nombre = (char*)realloc((char*)alumnos[cnt].materia[i].nombre, (alumnos[cnt].materia[i].long_nombre_mat)*sizeof(char)); //Reasigno memoria para cada nombre de cada materia
            */
            printf("Ingrese la fecha en la cual el %i%c alumno aprobo la %i%c materia de la forma <dd/mm/yyyy>: ", cnt+1, 167, i+1, 167);
            scanf("%i%c%i%c%i", &alumnos[cnt].materia[i].aprobado.dia, &barra, &alumnos[cnt].materia[i].aprobado.mes, &barra, &alumnos[cnt].materia[i].aprobado.anio);
            printf("Ingrese el promedio del %i%c alumno en la %i%c materia: ", cnt+1, 167, i+1, 167);
            scanf("%f", &alumnos[cnt].materia[i].promedio);

        }
        puts("\n\n");
    }
    total_anterior += cnt;
    system("pause");
    system("cls || clear");

}

void imprimir_datos(const datos_alumno *alumnos, int16_t cnt_alumnos, FILE *salida)
{
    fprintf(salida, "%d,", cnt_alumnos); //Cantidad de alumnos en ese momento
    for(int cnt = 0; cnt < cnt_alumnos; cnt++)
    {
        fprintf(salida, "%d,", alumnos[cnt].long_nombre); //Longitud del nombre
        fprintf(salida, "%s,", alumnos[cnt].nombre); //Nombre
        fprintf(salida, "%d,", alumnos[cnt].matricula); //Numero de matricula
        fprintf(salida, "%d,", alumnos[cnt].cnt_materias); //Cantidad de materias
        for(int loop = 0; loop < alumnos[cnt].cnt_materias; loop++)
        {

            fprintf(salida, "%d,", alumnos[cnt].materia[loop].long_nombre_mat); //Largo del nombre
            fprintf(salida, "%s,", alumnos[cnt].materia[loop].nombre); //Nombre materia
            fprintf(salida, "%d/%d/%d,", alumnos[cnt].materia[loop].aprobado.dia, //Fecha de aprobacion
                                          alumnos[cnt].materia[loop].aprobado.mes,
                                          alumnos[cnt].materia[loop].aprobado.anio);
            fprintf(salida, "%.2f,", alumnos[cnt].materia[loop].promedio); //Promedio

        }
    }
    fprintf(salida, "\n");
}
void imprimir_datos_recuperados(const datos_alumno *alumnos, int cnt_alumnos)
{
    for(int cnt = 0; cnt < cnt_alumnos; cnt++)
    {
        printf("Cantidad de alumnos: %d\n\n", alumnos[cnt].cnt_alumnos);
        printf("\n\t-DATOS DEL %d%c ALUMNO -\n\n", cnt+1, 167);
        printf("Longitud del nombre: %d", alumnos[cnt].long_nombre);
        printf("\nNombre: %s", alumnos[cnt].nombre);
        printf("\nMatricula: %d\n",alumnos[cnt].matricula);
        for(int loop = 0; loop < alumnos[cnt].cnt_materias; loop++)
        {
            printf("\nLongitud del nombre de la materia: %d", alumnos[cnt].materia[loop].long_nombre_mat);
            printf("\nMateria: %s", alumnos[cnt].materia[loop].nombre);
            printf("\nAprobada: %d/%d/%d", alumnos[cnt].materia[loop].aprobado.dia,
                                           alumnos[cnt].materia[loop].aprobado.mes,
                                           alumnos[cnt].materia[loop].aprobado.anio);
            printf("\nPromedio: %.2f\n\n", alumnos[cnt].materia[loop].promedio);
        }

        //Pausa y salto de linea para empezar el siguiente alumno
        system("pause");
        puts("\n");
    }
}

void imprimir_datos_binario(datos_alumno *alumnos, FILE *falumnos, int16_t cnt_alumnos)
{
    fwrite(&cnt_alumnos, sizeof(int16_t), 1, falumnos);
    for(int cnt = 0; cnt < cnt_alumnos; cnt++)
    {
        fwrite(&alumnos[cnt].long_nombre, sizeof(int), 1, falumnos);
        fwrite(alumnos[cnt].nombre, sizeof(char), alumnos[cnt].long_nombre, falumnos);
        fwrite(&alumnos[cnt].matricula, sizeof(int), 1, falumnos);
        fwrite(&alumnos[cnt].cnt_materias, sizeof(int), 1, falumnos);
        for(int loop = 0; loop < alumnos[cnt].cnt_materias; loop++)
        {
            fwrite(&alumnos[cnt].materia[loop].long_nombre_mat, sizeof(int), 1, falumnos);
            fwrite(alumnos[cnt].materia[loop].nombre, sizeof(char), alumnos[cnt].materia[loop].long_nombre_mat, falumnos);
            fwrite(&alumnos[cnt].materia[loop].aprobado.dia, sizeof(int), 1, falumnos);
            fwrite(&alumnos[cnt].materia[loop].aprobado.mes, sizeof(int), 1, falumnos);
            fwrite(&alumnos[cnt].materia[loop].aprobado.anio, sizeof(int), 1, falumnos);
            fwrite(&alumnos[cnt].materia[loop].promedio, sizeof(float), 1, falumnos);
        }
    }

}


datos_alumno *agregar_alumnos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t nuevos_alumnos, int16_t max_materias, int16_t max_nombre)
{
    alumnos = (datos_alumno*)realloc((datos_alumno*)alumnos, (cnt_alumnos)*sizeof(datos_alumno));
    if(alumnos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria\n");
        exit(3);
    }
    else
    {
        for(int cnt = (cnt_alumnos - nuevos_alumnos); cnt < (cnt_alumnos); cnt++)
        {
            alumnos[cnt].nombre = (char *)malloc(max_nombre*sizeof(char));
            alumnos[cnt].materia = (catedras *)malloc(max_materias*sizeof(catedras));
            for(int loop = 0; loop < max_materias; loop++)
            {
                alumnos[cnt].materia[loop].nombre = (char *)malloc(max_nombre*sizeof(char));
            }

        }
        puts("\n");
        ingresar_datos(alumnos, cnt_alumnos, max_nombre, max_materias);
    }

    return alumnos;

}

void intercambiar_datos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_materias)
{
    int alumno;

    puts("\n");
    printf("Elija el alumno que desea sacar: ");
    scanf("%d", &alumno);
    if(alumno > cnt_alumnos)
    {
        printf("El numero de alumno que ha digitado no existe.\n");
        exit(4);
    }
    else
    {
        free(alumnos[alumno-1].nombre);
        free(alumnos[alumno-1].materia);
        for(int loop = 0; loop < alumnos[alumno-1].cnt_materias; loop++)
        {
            free(alumnos[alumno-1].materia[loop].nombre);
        }

        //Ponemos los datos del cnt+1 en cnt pisandolo.

        for(int cnt = alumno-1; cnt < cnt_alumnos; cnt++)
        {
            alumnos[cnt] = alumnos[cnt+1];

        }
    }
}
datos_alumno *sacar_alumnos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_materias)
{
    alumnos = (datos_alumno*)realloc((datos_alumno*)alumnos, (cnt_alumnos)*sizeof(datos_alumno));
    if(alumnos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria\n");
        exit(5);
    }

    return alumnos;
}

void recuperar_datos(datos_alumno *alumnos, char *nombre)
{
    system("pause");
    system("cls || clear");
    char barra;
    int cnt_alumnos;
    int cnt;
    static int total_anterior = 0;
    char *ptr;
    FILE *fr;
    fr = fopen(nombre, "r");

    fscanf(fr, "%d%*c", &cnt_alumnos);
    alumnos = (datos_alumno*)malloc(cnt_alumnos*sizeof(datos_alumno)); //Reservo memoria para la cantidad de alumnos
    for(cnt = total_anterior; cnt < cnt_alumnos; cnt++)
    {
        alumnos[cnt].cnt_alumnos = cnt_alumnos;
        fscanf(fr, "%d%*c", &alumnos[cnt].long_nombre);
        alumnos[cnt].nombre = (char*)malloc((alumnos[cnt].long_nombre + 1)*sizeof(char)); //Reservo memoria para cada nombre
        ptr = alumnos[cnt].nombre + alumnos[cnt].long_nombre;
        *ptr = '\0';
        fread((void*)alumnos[cnt].nombre, sizeof(char), alumnos[cnt].long_nombre, fr);
        fscanf(fr, "%*c%d%*c%d%*c", &alumnos[cnt].matricula, &alumnos[cnt].cnt_materias);
        alumnos[cnt].materia = (catedras*)malloc(alumnos[cnt].cnt_materias*sizeof(catedras)); //Reservo memoria para la cantidad de materias
        for(int loop = 0; loop < alumnos[cnt].cnt_materias; loop++)
        {
            fscanf(fr, "%d%*c", &alumnos[cnt].materia[loop].long_nombre_mat);
            alumnos[cnt].materia[loop].nombre = (char*)malloc((alumnos[cnt].materia[loop].long_nombre_mat + 1)*sizeof(char)); //Reservo memoria para el nombre de cada materia y el +1 es por el \0
            ptr = alumnos[cnt].materia[loop].nombre + alumnos[cnt].materia[loop].long_nombre_mat;
            *ptr = '\0';
            fread((void*)alumnos[cnt].materia[loop].nombre, sizeof(char), alumnos[cnt].materia[loop].long_nombre_mat, fr);
            fscanf(fr, "%*c%d%c%d%c%d", &alumnos[cnt].materia[loop].aprobado.dia, &barra, &alumnos[cnt].materia[loop].aprobado.mes, &barra, &alumnos[cnt].materia[loop].aprobado.anio);
            fscanf(fr, "%*c%f", &alumnos[cnt].materia[loop].promedio);
            fscanf(fr, "%*c"); //La ultima coma
        }

    }
    total_anterior += cnt;
    fscanf(fr, "%*c");

    //Imprimimos los datos resultantes
    imprimir_datos_recuperados(alumnos, total_anterior);

    //Cerramos el archivo
    fclose(fr);

    //Libero memoria
    liberar_memoria_final(alumnos, total_anterior);

}
void liberar_memoria_final(datos_alumno *ptr, int cnt_modificaciones)
{
    for(int i = 0; i < cnt_modificaciones; i++)
    {
        for(int cnt = 0; cnt < ptr[i].cnt_alumnos; cnt++)
        {
            for(int loop = 0; loop < ptr[cnt].cnt_materias; loop++)
            {
                free(ptr[cnt].materia[loop].nombre);
            }
            free(ptr[cnt].nombre);
            free(ptr[cnt].materia);
        }
        free(ptr);
    }
}
void recuperar_datos_binario(datos_alumno *alumnos, char *nombre_b)
{
    FILE *frb;
    int cnt_alumnos;
    char *ptr;

    frb = fopen(nombre_b, "rb");
    verificar_apertura(frb);

    fread(&cnt_alumnos, sizeof(int), 1, frb);
    alumnos = (datos_alumno *)malloc(cnt_alumnos*sizeof(datos_alumno));
    for(int cnt = 0; cnt < cnt_alumnos; cnt++)
    {
        alumnos[cnt].cnt_alumnos = cnt_alumnos;
        fread(&alumnos[cnt].long_nombre, sizeof(int), 1, frb);
        alumnos[cnt].nombre = (char *)malloc(alumnos[cnt].long_nombre + 1*sizeof(char));
        fread(alumnos[cnt].nombre, sizeof(char), alumnos[cnt].long_nombre, frb);
        ptr = alumnos[cnt].nombre + alumnos[cnt].long_nombre;
        *ptr  = '\0';
        fread(&alumnos[cnt].matricula, sizeof(int), 1, frb);
        fread(&alumnos[cnt].cnt_materias, sizeof(int), 1, frb);
        alumnos[cnt].materia = (catedras *)malloc(alumnos[cnt].cnt_materias*sizeof(catedras));
        for(int loop = 0; loop < alumnos[cnt].cnt_materias; loop++)
        {
            fread(&alumnos[cnt].materia[loop].long_nombre_mat, sizeof(int), 1, frb);
            alumnos[cnt].materia[loop].nombre = (char *)malloc(alumnos[cnt].materia[loop].long_nombre_mat + 1*sizeof(char));
            fread(alumnos[cnt].materia[loop].nombre, sizeof(char), alumnos[cnt].materia[loop].long_nombre_mat, frb);
            ptr = alumnos[cnt].materia[loop].nombre + alumnos[cnt].materia[loop].long_nombre_mat;
            *ptr  = '\0';
            fread(&alumnos[cnt].materia[loop].aprobado.dia, sizeof(int), 1, frb);
            fread(&alumnos[cnt].materia[loop].aprobado.mes, sizeof(int), 1, frb);
            fread(&alumnos[cnt].materia[loop].aprobado.anio, sizeof(int), 1, frb);
            fread(&alumnos[cnt].materia[loop].promedio, sizeof(float), 1, frb);
        }
    }
    //Imprimimos los datos resultantes
    imprimir_datos_recuperados(alumnos, cnt_alumnos);

    //Cerramos el archivo
    fclose(frb);

    //Libero memoria
    liberar_memoria_final(alumnos, cnt_alumnos);

}
