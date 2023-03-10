#include "declara.h"

void grabar(const char *nombre)
{
    int ivalor = 1959;
    float fvalor = 378.123456789;
    FILE *fp;

    fp = fopen(nombre,"w");
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }

    fprintf(fp, "%d; %f2\n", ivalor, fvalor); // entero ';' flotante
    fclose(fp);

    fcopy("..\\Archivos\\copia.txt", nombre); // hago una copia para sobrescribir!!

    fp = fopen(nombre,"a");                   // append --> sigo guardando datos

    fprintf(fp, "%05o, %#05x\n", ivalor, ivalor);  // o = octal; x/X = hexa con 5 digitos (0xddddd)
    fprintf(fp, "%#05o\n", ivalor);           // octal con 5 digitos (0xddddd)
    fprintf(fp, "%#05x\n", ivalor);           // hexadecimal
    fprintf(fp, "%+8.1E\n", fvalor);          // 1 decimal, con exponencial
    fputs("Este_es_un_string_hAsta_que_se_escriba_A-B-C", fp);

    fclose(fp);
}

int fcopy(char *destino, const char *fuente)
{
    FILE *fdestino,
         *ffuente;
    int dato;
    int cnt = 0;

    fdestino = fopen(destino, "w");
    ffuente = fopen(fuente, "r");

    if(!fdestino || !ffuente)                   // si fdestino == NULL OR ffuente == NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);
         // termina el programa con un código de error
    }

    while( (dato = getc(ffuente)) != EOF )
    {
        putc(dato, fdestino);
        cnt++;
    }

    fclose(fdestino);
    fclose(ffuente);

    return cnt;
}

