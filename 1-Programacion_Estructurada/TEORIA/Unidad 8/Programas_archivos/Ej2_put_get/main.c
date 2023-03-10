#include <stdio.h>
#include <stdlib.h>
#include <conio.h>                             // para usar el getche()
#include <string.h>

int flength(FILE *);                           // retorna la longitud del archivo
void lectOK(char *, int, char *);

int main()
{
    FILE *fp;
    int len;
    char letra = ' ';
    char nombre[] = "C:\\Users\\Gonza\\Desktop\\Programacion_Estructurada\\TEORIA\\Unidad 8\\Programas_archivos\\Ej2_put_get\\prueba.txt";
    char *datos;

    /**** genero un archivo con información de distinto tipo ****/
    fp = fopen(nombre,"w");
    if(fp == NULL)                             // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                               // termina el programa con un código de error
    }

    puts("Datos grabados: ");

    /**** escritura ****/
    while(letra != 'q')
    {
        letra = getche();                      // ingresa una tecla desde teclado y la imprime en pantalla (no agrega '\n')
        //letra = getc(stdin);                   // toma los caracteres al apretar el ENTER
        putc(letra, fp);                       // putc es una macro equivalente a fputc
    }
    fputc('\n', fp);                           // guarda '\n' + '\r' = 0xA + 0xD
    putc('\n', stdout);

    fputs("String 1", fp);                     // salida a archivo, no agrega 0x0 ni '\n'
    fputs("String 1", stdout);                 // salida a pantalla, no agrega '\n' al final
    fputs("String 2\n", fp);                   // a continuación del anterior
    puts("String 2");                          // salida a pantalla, agrega '\n' al final
    fputs("String 3\n", fp);
    puts("String 3");

    fclose(fp);                                // Verificar los datos guardados

    /***** lectura (hay que conocer como se guardaron los datos!!!) ****/
    fp = fopen(nombre,"r");
    len = flength(fp);
    datos = (char *)malloc(len+2);            // para contemplar EOF y 0x0 del final de string
    fgets(datos, len, fp);                    // no se leen todos los caracteres porque encontró un '\n'
    fclose(fp);

    puts("\nDatos leidos: ");
    puts(datos);

    lectOK(nombre, len, datos);               // MI FUNCION

    puts("\nDatos completos: ");
    puts(datos);

    return 0;
}

int flength(FILE *fp)
{
    long int sz;

    fseek(fp, 0L, SEEK_END);                   // pone el puntero al final del archivo
    sz = ftell(fp);                            // retorna la cantidad de bytes (se puede usar porque son caracteres)
    rewind(fp);                                // vuelve el puntero al primer caracter

    return (int)sz;
}

void lectOK(char *nombre, int len, char *datos)
{
    FILE *fp;
    char aux[len];
    int cnt;

    datos[0] = 0;                              // borra la información que quedó de antes
    cnt = strlen(datos);
    fp = fopen(nombre, "r");
    while(cnt < len)
    {
       fgets(aux, len-cnt, fp);                // convierte el '\r' + '\n' en sólo '\n'
       strcat(datos, aux);
       cnt = strlen(datos);
       len--;                                  // tengo que eliminar un '\r' por cada línea
    }
    fclose(fp);
}
