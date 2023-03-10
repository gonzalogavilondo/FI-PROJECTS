 #include "myInclude.h"

int main()
{
    int aux,
        iValor;
    float fValor;
    stFile stRecords[2];
    FILE *fp;
    char nombre[] = "..\\Archivos\\write.txt";

    /**** voy a guardar el entero, las dos estructuras y el flotante ****/
    graba(nombre);

    /**** voy a leer primero el flotante, después la 2º estructura, el entero y la 1º estructura ****/
    fp = fopen(nombre,"r");
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }

    rewind(fp);
    fseek(fp, -sizeof(float), SEEK_END);      // retrocedo un flotante desde el fin del archivo
    aux = ftell(fp);                          // posicion del flotante
    fread((void *)&fValor, sizeof(fValor), 1, fp);
    printf("fValor estaba en la posicion %d, y es = %e\n\n", aux, fValor);

    rewind(fp);
    fseek(fp, -(sizeof(float)+sizeof(stFile)), SEEK_END);
    aux = ftell(fp);
    fread((void *)&stRecords[1], sizeof(stFile), 1, fp);
    printf("stRecords[1] estaba en la posicion %d, y contiene: \n", aux);
    printRecord(stRecords[1]);

    rewind(fp);                               // el entero está al comienzo del archivo
    aux = ftell(fp);
    fread((void *)&iValor, sizeof(iValor), 1, fp);
    printf("iValor estaba en la posicion %d, y es = %d\n\n", aux, iValor);

    aux = ftell(fp);                          // no hace falta mover el puntero, es el proximo dato
    fread((void *)&stRecords[0], sizeof(stFile), 1, fp);
    printf("stRecords[0] estaba en la posicion %d, y contiene: \n", aux);
    printRecord(stRecords[0]);

    fclose(fp);

    backup(nombre);

    return 0;
}
