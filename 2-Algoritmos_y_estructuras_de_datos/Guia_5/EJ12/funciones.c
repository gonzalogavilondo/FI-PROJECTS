#include "declaraciones.h"

void postorder(char *pre, char *in, int n)
{
    int root = strchr(in, pre[0]) - in;  //Guardo la posicion que el nodo raiz ocupa en el inorder. (Root es la posicion de la raiz)

    //El tamaño del lado izquierdo es root. Si root = 0, entonces termine de recorrer el lado izquierdo
    if(root != 0)                       //Si el lado izquierdo no esta vacio, entonces seguimos recorriendo
    {
        postorder(pre+1, in, root);
    }
    //El tamaño del lado derecho es (n-root-1)
    if(root != n-1)                    //Si el lado derecho no esta vacio, entonces seguimos recorriendo
    {
        postorder(pre+root+1, in+root+1, n-root-1);
    }
    printf("%c", pre[0]);
}
