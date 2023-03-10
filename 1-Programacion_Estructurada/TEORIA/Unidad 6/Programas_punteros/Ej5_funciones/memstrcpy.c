#include "funciones.h"

void dump5(char *str);

void copiar(void)
{
    char s[5] = {'s','a','\0','c','h'};
    char membuff[5];
    char strbuff[5];

    memset(membuff, 0, 5);    // inicializa ambos buffers con 0s
    memset(strbuff, 0, 5);

    memcpy(membuff,s,5);      // copia s al buffer de memoria
    strcpy(strbuff,s);        // copia s al buffer string

    // strcpy no puede copiar el '\0', memcpy lo ignora
    dump5(membuff);           // 73 61 00 63 68   sa ch
    dump5(strbuff);           // 73 61 00 00 00   sa
}

void dump5(char *str)
{
    int cnt;

    for(cnt=0; cnt<5; cnt++)
        printf("%.2x ", str[cnt]);   //.2 para que imprima 00 en vez de 0

    printf("\t");

    for(cnt=0; cnt<5; cnt++)
        printf("%c", str[cnt]);

    printf("\n");
}

void memvarios(void)
{
    char mensaje[60] = "Four score and seven years ago ...";
    char fuente[]="0123456789ABCDEF";
    char destino[]="0123456789ABCDEF";

    /**** memset() ****/
    printf("\nmensaje antes de memset():\t%s", mensaje);
    memset(mensaje+5, '@', 10);
    printf("\nmensaje despues de memset():\t%s", mensaje);

    /**** memcpy()/memmove() La diferencia depende del compilador ****/
    memcpy(fuente+4,fuente,6);
    memmove(destino+4,destino,6);
    // En Codeblocks no hay diferencia entre ambas funciones
    printf("\n\nResultado con memcpy: \t%s", fuente+4);        // 012345ABCDEF
    printf("\nResultado con memmove: \t%s\n\n", destino+4);    // 012345ABCDEF

    // En TC (Turbo C)
    // memcpy:    012301ABCDEF     solapa 6 - 4 caracteres / sobreescribió el 45 antes de copiar
    // memmove:   012345ABCDEF     OK
}
