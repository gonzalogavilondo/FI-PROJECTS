#include <stdio.h>
#include <stdlib.h>

int fcopy(const char *destino, const char *fuente);     // retorna la cantidad de bytes copiados
int fexists(const char *fname);                         // 1 ==> existe; 0 ==> no existe

int main()
{
    FILE *fp;
    float f = 3.1415927;
    int ret;

    /**** se puede invocar la línea de comandos (DOS) ****/
    system("if not exist ..\\Archivos md ..\\Archivos");

    /**** genero 2 archivos con la misma información ****/
    fp = fopen("..\\Archivos\\file1.txt","w");
    if(fp)                                              // si fp != NULL se pudo abrir el archivo
    {
        fputs("file1 ", fp);
        fputs("texto ", fp);
        fprintf(fp, "%.7f", f);
        fclose(fp);
        ret = fcopy("..\\Archivos\\file2.txt", "..\\Archivos\\file1.txt");  // MI FUNCION
        printf("\nSe copiaron %d bytes\n", ret);        // verificar el archivo!!
   }

    /**** se sobrescribe la información por abrir en modo escritura ****/
    if(fexists("..\\Archivos\\file2.txt"))              // MI FUNCION
    {
        printf("Quiere sobrescribir el archivo? (Y/N): ");
        ret = getchar();
        if(ret!='Y')
        {
            rename("..\\Archivos\\file2.txt", "..\\Archivos\\backup.txt");
        }
    }
    fp = fopen("..\\Archivos\\file2.txt","w");
    fputs("\nEscribo nueva información ", fp);
    fclose(fp);                                         // verificar la nueva información

    /**** se AGREGA información conservando la anterior ****/
    fp = fopen("..\\Archivos\\file2.txt","a");          // se agrega la información (append)
    fputs("\nEscribo nueva información ", fp);
    fclose(fp);                                         // verificar que la información se agregó

    /**** diferencia entre modo texto y modo binario ****/
    fp = fopen("..\\Archivos\\float1.txt","wt");
    fprintf(fp, "%f", f);
    fclose(fp);
    fp = fopen("..\\Archivos\\float2.txt","wb");
    fwrite((const void *)&f, 1, sizeof(float), fp);     // f = 3.1415927 = 0x 40 49 0F DB
    fclose(fp);                                         // comprobar los tamaños y la información

    return 0;
}

int fcopy(const char *destino, const char *fuente)
{
    FILE *fdestino,
         *ffuente;
    int dato;
    int cnt = 0;

    fdestino = fopen(destino, "w");
    ffuente = fopen(fuente, "r");

    while( (dato = getc(ffuente)) != EOF )
    {
        putc(dato, fdestino);
        cnt++;
    }

    fclose(fdestino);
    fclose(ffuente);

    return cnt;
}

int fexists(const char *fname)
{
    FILE *file = fopen(fname, "r");

    if (file != NULL)
    {
        fclose(file);
        return 1;
    }

    return 0;
}
