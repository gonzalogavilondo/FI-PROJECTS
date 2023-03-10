 #include "myInclude.h"

 void graba(char *nombre)
 {
    int aux,
        iValor = 1959;
    float fValor = 1.235E3;
    stFile stRecords[2];
    FILE *fp;

    strcpy(stRecords[0].Nombre, "Pedro Picapiedra");
    stRecords[0].iDato = 123;
    stRecords[0].fDato = -1.45E-3;
    stRecords[0].stFecha.day = 3;
    stRecords[0].stFecha.month = 4;
    stRecords[0].stFecha.year = 2015;

    strcpy(stRecords[1].Nombre, "Pablo Marmol");
    stRecords[1].iDato = 456;
    stRecords[1].fDato = 2.85E5;
    stRecords[1].stFecha.day = 13;
    stRecords[1].stFecha.month = 1;
    stRecords[1].stFecha.year = 2010;

    aux = sizeof(stFile);

    /**** voy a guardar el entero, las dos estructuras y el flotante ****/
    fp = fopen(nombre,"w");
    if(fp == NULL)                            // si fp != NULL se pudo abrir el archivo
    {
        perror("No puedo abrir el archivo ");
        exit(1);                              // termina el programa con un código de error
    }

    fwrite((void *)&iValor, sizeof(int), 1, fp);
    fwrite((void *)stRecords, aux, 2, fp);
    fwrite((void *)&fValor, sizeof(float), 1, fp);

    fclose(fp);
}

void printRecord(stFile stRec)
{
    printf("\tNombre = %s\n\tEntero = %d\n\tFlotante = %e\n\tFecha = %d/%d/%d\n\n",
           stRec.Nombre, stRec.iDato, stRec.fDato,
           stRec.stFecha.day, stRec.stFecha.month, stRec.stFecha.year);
}

void backup(char *nombre)
{
    FILE *fpw, *fpr;
    long int sz;
    void *tmp;

    fpr = fopen(nombre, "r");
    fseek(fpr, 0L, SEEK_END);                   // pone el puntero al final del archivo
    sz = ftell(fpr);                            // retorna la cantidad de bytes (se puede usar porque son caracteres)
    rewind(fpr);                                // vuelve el puntero al primer caracter

    tmp = malloc(sz);

    fpw = fopen("..\\Archivos\\wr_bckp.txt", "w");

    fread(tmp, sz, 1, fpr);
    fwrite(tmp, sz, 1, fpw);

    fclose(fpw);
    fclose(fpr);
    free(tmp);

}
