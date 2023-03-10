void copia_string(char *str1, char *str2)
{
    int cnt=0;
    do
    {
        str1[cnt] = str2[cnt];
        cnt++;
    }while(str2[cnt]);
    str1[cnt] = '\0';       // para marcar el fin del string si el vector tiene longitud menor

}
