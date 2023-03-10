#include "declara.h"

int main()
{
    int ivalor,                               // 1959;
        cnt;                                  // contador
    float fvalor;                             // 378.123456789;
    char car,                                 // auxiliar
         nombre[] = "..\\Archivos\\varios.txt";
    char str[100];                            // auxiliar
    FILE *fp;

    grabar(nombre);                           // crea también copia.txt; verificar archivos!!

    /**** Atención a la forma de acceso !!! ****/
    fp = fopen("..\\Archivos\\copia.txt","w");// lo abro 'w' --> borra los datos!!!!
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }
    fclose(fp);                               // verificar los datos!!

    fp = fopen(nombre,"r");
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }

    /**** realiza la conversión de texto a entero y a flotante ****/
    cnt = fscanf(fp, "%d%c%f", &ivalor, &car, &fvalor);           // atención a los datos
    puts("Forma directa, fscanf() realiza las conversiones de texto a valores");
    printf("Entero = %d, flotante = %f, retorno = %d\n\n",  ivalor,  fvalor,  cnt);

    /**** ingresar los datos como string (como se guardaron) ****/
    ivalor = 0;
    fvalor = 0.0;
    rewind(fp);                               // el puntero vuelve al principio
    fscanf(fp, "%s", str);                    // lee hasta el primer espacio ' '
    puts("\n\nLectura como string fscanf() lee hasta ' '");
    ivalor = atoi(str);                       // tengo que convertir
    printf("Entero = %d, flotante = %f\n",  ivalor,  fvalor);
    fscanf(fp, "%s", str);                    // lee hasta el fin de la linea
    puts("Luego de la segunda lectura");
    fvalor = atof(str);                       // tengo que convertir
    printf("Entero = %d, flotante = %f\n\n",  ivalor,  fvalor);

    /**** otra forma es leer toda la línea y procesar el string ****/
    ivalor = 0;
    fvalor = 0.0;
    str[0] = '\0';
    rewind(fp);
    fscanf(fp, "%[^\n]", str);                 // lee toda la línea en un solo paso
    printf("\n\nLectura de la linea completa: %s\n", str);
    ivalor = atoi(str);
    fvalor = atof((strchr(str, ';')+1));       // retorna la posición de ';' por eso sumo 1
    printf("Entero = %d, flotante = %f\n\n",  ivalor,  fvalor);

    /**** importancia de saber como se guardaron los datos ****/
    ivalor = 0;
    str[0] = '\0';
    puts("\n\nFormato %#5o, %#5x (numero en octal y hexadecimal");
    fscanf(fp, "%c%[^\n]", &car, str);          // se debe leer el \n anterior (en car)
    ivalor = atoi(str);
    printf("Entero = %d (el valor real es 1959, no convirtio desde octal)\n", ivalor);
    ivalor = atoi((strchr(str, ',')+1));       // retorna la posición de ';' por eso sumo 1
    printf("Entero = %d (considera el 0 del 0x)\n\n",  ivalor);

    /**** conversiones directas de octal y hexadecimal ****/
    fscanf(fp, "%o", &ivalor);
    printf("\n\nCon el modificador %%o fscanf realiza bien la conversion de octal, ivalor = %d\n", ivalor);
    ivalor = 0;
    fscanf(fp, "%x", &ivalor);
    printf("Con el modificador %%x fscanf realiza bien la conversion de hexa, ivalor = %d\n\n", ivalor);

    /**** lectrua de un flotante con 1 decimal y formato exponencial, ancho total 8 ****/
    fvalor = 0;
    fscanf(fp, "%f\n", &fvalor);
    printf("\n\nFormato grabado ""%%+8.1E"" = %E, redondeado por guardar un solo decimal (378.123456789)\n", fvalor);

    /**** lectura del ultimo string hasta A, después campo fijo y luego hasta el final ****/
    fscanf(fp, "%[^A-C]", str);
    printf("\n\n\nLectura hasta la A: %s\n", str);
    fscanf(fp, "%10s", str);
    printf("Segunda lectura (width = 10): %s\n", str);
    fscanf(fp, "%s", str);
    printf("Lectura final: %s\n\n\n", str);

    fclose(fp);

    /**** lectura desde buffer en vez de archivo ****/
    ivalor = 0;
    fvalor = 0.0;
    str[0] = '\0';
            /* podria ser un lugar de memoria */
    cnt = sscanf("0x7a7; 378.1234442", "%x%*c%f", &ivalor, &fvalor);  // %*c lee el ';' pero no lo almacena
    printf("\n%d valores obtenidos desde 'buffer': entero = %d, %%*c no almacena la ';' y flotante = %f\n\n\n", cnt, ivalor, fvalor);

    return 0;
}


