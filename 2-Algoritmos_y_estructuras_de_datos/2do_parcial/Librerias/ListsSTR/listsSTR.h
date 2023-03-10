#ifndef HEADER_LISTS_STR_H_INCLUDED
#define HEADER_LISTS_STR_H_INCLUDED


typedef struct dNodeS dNodeS;    ///Nodo para lista doblemente enlazada
struct dNodeS{
	char *value;
	dNodeS *prev;
	dNodeS *next;
};

dNodeS *createDNodeS(char *x);

/**************************************************************/
/*                     LISTA DE ENTEROS                       */
/**************************************************************/

typedef struct
{
    dNodeS *first;
    dNodeS *last;
    int size;
}listS;

listS *createListS();
int getSizeListS(listS *l);
int isEmptyListS(listS *l);
int insertEmptyListS(listS *l, char *x);
int insertFirstListS(listS *l, char *x);
int insertLastListS(listS *l, char *x);
int insertPosListS(listS *l, int pos, char *x);
int deleteFirstListS(listS **l);
int deleteLastListS(listS **l);
int deletePosListS(listS **l, int pos);
char *getValueListS(listS *l, int pos);
int setValueListS(listS *l, int pos, char *x);
int printListS(listS *l);

#endif // HEADER_LISTS_STR_H_INCLUDED
