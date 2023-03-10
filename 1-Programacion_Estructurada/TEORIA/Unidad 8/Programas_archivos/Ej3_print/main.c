#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 59;
    float f = 378.123456789;
    char s[] = "Mi mensaje";
    FILE *fp;

    fp = fopen("C:\\Users\\Gonza\\Desktop\\Programacion_Estructurada\\TEORIA\\Unidad 8\\Programas_archivos\\Ej3_print\\print.txt","w");
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }

    /**** prec: para strings = cantidad de caracteres que se imprimen ****/
    fputs("Formato %2s (minimo 2 caracteres, no trunca):\n", fp);
    fprintf(fp, "%2s/\n", s);                 // mínimo 2, no trunca
    fputs("\nFormato %15s (alineado a derecha, minimo 15 caracteres, completa con ' '):\n", fp);
    fprintf(fp, "%15s/\n", s);                // derecha, mínimo 15, completa con ' '
    fputs("\nFormato %-15s (alineado a izquierda, minimo 15 caracteres, completa con ' '):\n", fp);
    fprintf(fp, "%-15s/\n", s);               // izquierda, mínimo 15, completa con ' '
    fputs("\nFormato %15.5s (alineado a derecha, ancho 15 caracteres, imprime solo 5):\n", fp);
    fprintf(fp, "%15.5s/\n", s);              // derecha, ancho = 15, sólo 5 caracteres
    fputs("\nFormato %-15.8s (alineado a izquierda, ancho 15 caracteres, imprime solo 8):\n", fp);
    fprintf(fp, "%-15.8s/\n", s);             // izquierda, ancho = 15, sólo 8 caracteres
    fputs("\nFormato %s, %.4s (imprime completo y luego solo 4 caracteres)\n", fp);
    fprintf(fp, "%s, %.4s/\n", s, s);         // completo, sólo 4 caracteres (sin width)
    fputs("\n\n", fp);

    /**** prec: para enteros = cantidad mínima de dígitos que imprime ****/
    fputs("\nFormato %7.5d (alineado a derecha, imprime 5 caracteres y completa con ' ' hasta 7)\n", fp);
    fprintf(fp, "%7.5d/\n", i);               // derecha (completa con ' ' hasta 10)
    fputs("\nFormato %07d (alineado a derecha, completa con '0' hasta 7 caracteres)\n", fp);
    fprintf(fp, "%07d/\n", i);                // derecha (completa con '0' hasta 10)
    fputs("\nFormato %-7d (alineado a izquierda, completa con ' ' hasta 7 caracteres)\n", fp);
    fprintf(fp, "%-7d/\n", i);                // izquierda (agrega ' ' hasta 7)
    fputs("\nFormato %+5d, %+5d (imprime siempre el signo (+/-), con 5 caracteres\n", fp);
    fprintf(fp, "%+5d, %+5d/\n", i, -i);      // siempre imprime el signo (+/-) (5 caracteres)
    fputs("\nFormato % 5d, % 5d (imprime blank o signo (' '/-), con 5 caracteres)\n", fp);
    fprintf(fp, "% 5d, % 5d/\n", i, -i);      // blank o '-' para números negativos (5 caracteres)
    fputs("\nFormato %#5o, %#5x (numero en octal (0ddd) y hexadecimal (0xddd) (5 caracteres)\n", fp);
    fprintf(fp, "%#5o, %#05x/\n", i, i);      // o = octal (0ddd), x/X = hexa (0xddd)
    fputs("\n\n", fp);

    /**** prec: para flotantes = máximo número de dígitos después del punto decimal ****/
    fputs("\nFormato %2.5f (imprime AL MENOS 2 caracteres con 5 digitos decimales)\n", fp);
    fprintf(fp, "%2.5f/\n", f);               // al menos 2 caracteres con 5 decimales
    fputs("\nFormato %10.3f (imprime 10 caracteres con 3 digitos decimales)\n", fp);
    fprintf(fp, "%10.3f/\n", f);              // derecha, 10 caracteres, 3 decimales
    fputs("\nFormato %-10.3f (10 caracteres, 3 decimales, alineado izquierda)\n", fp);
    fprintf(fp, "%-10.3f/\n", f);             // izquierda, 10 caracteres, 3 decimales
    fputs("\nFormato %+8.1f, %+8.1E (1 decimal sin y con notacion exponencial)\n", fp);
    fprintf(fp, "%+8.1f, %+8.1E/\n", f, -f);  // 1 decimal, con y sin exponencial
    fputs("\nFormato %g, %G, %g, %.2G, 1.23e-5, 1.23e-3, 1.23e3, 1.23e3 ", fp);
    fputs("(si exp es <(-4) o >[.prec] usa %e; sino %f\n", fp);
    i=fprintf(fp, "%g, %G, %g, %.2G", 1.23e-5, 1.23e-3, 1.23e3, 1.23e3);

    fclose(fp);

    char aux[++i];                            // incremento para el 0x0
    sprintf(aux, "%g, %G, %g, %.2G", 1.23e-5, 1.23e-3, 1.23e3, 1.23e3);    // imprime en aux
    printf("La sentencia \"%s\" almaceno %d bytes en el archivo\n\n", aux, --i);

    return 0;
}


