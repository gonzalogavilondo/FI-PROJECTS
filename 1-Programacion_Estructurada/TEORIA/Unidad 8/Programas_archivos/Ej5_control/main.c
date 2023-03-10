#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long cnt;                                 // contador
    int aux;                                  // auxiliar
    char nombre[] = "..\\Archivos\\print.txt";
    char str[50];                             // auxiliar
    FILE *fp;

    fp = fopen(nombre, "r");
    fseek(fp, 0L, SEEK_END);
    cnt = ftell(fp);                          // verificar con la longitud del archivo
    fclose(fp);
    printf("La longitud del archivo \"%s\" es %d bytes\n\n\n", nombre, cnt);

    fp = fopen("..\\Archivos\\cualquiera.dat", "r");  // el archivo no existe
    if(!fp)
    {
        perror("Codigo de error");
        /**** las 3 líneas producen el mismo efector que perror() ****/
        aux = errno;                          // aux = 2
        strcpy(str, strerror(aux));           // #define  ENOFILE  2  /* No such file or directory */
        printf("Codigo de error: %s\n", str); // en errno.h --> equivalente a usar perror
    }
    else
    {
        fclose(fp);                           // si lo pudo abrir que lo cierre
    }

    puts("\n");
    fp = fopen(nombre, "r");                  // abro para lectura !!
    if(!fp)
    {
        perror("Error en la apertura");
    }
    fputs("no se puede escribir", fp);
    if(ferror(fp))
    {
        sprintf(str, "Error #%d, codigo", errno);
        perror(str);
    }
    fclose(fp);

    puts("\n\n");

    return 0;
}
