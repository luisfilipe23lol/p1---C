/*__________________________________________*/
/*####		 PROGRAMA��O  EM  C	        ### */
/*_________________________________________	*/
/*$$$$ 		LINKED QUEUE  (implementa�ao) $$*/
/*$$$$  nome  : linkedQueue_TIPO.h     $$$$$*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

/* DIRECTIVAS DE INCLUSAO */
#include "singlyLinkedList_TIPO2.h"

/* DIRECTIVAS DE DEFENI�AO */
	/* CODIGO DE AVALIA�AO CONDICIONAL */
#define FALSO 0
#define VERDADEIRO 1

	/* CODIGO DE ORDENA�AO */
#define CRESCENTE 1
#define DECRESCENTE -1

	/* CODIGO DE AVALIA�AO DA FILA */
#define OK 0
#define FILA_VAZIA -1
#define FILA_INEXISTENTE -2
#define ELEMENTO_INEXISTENTE -1
#define MEMORIA_ESGOTADA -5
#define NULO -6

/* @@@@ intS DE DADOS AGREGADOS ( DECLARA�AO) @@@@*/
typedef struct lista LQUEUE;


	/* PROTIPOS DAS OPERA�OES SOBBRE A FILA*/
LQUEUE *screate();

int enqueue(LQUEUE *fila, TIPO2 elemento);

int dequeue (LQUEUE *fila, TIPO2 *elemento);

int qpeek(LQUEUE *fila, TIPO2 *elemento);

int size (LQUEUE *fila);

int empty (LQUEUE *fila);

int destroy (LQUEUE **fila);

int sview (LQUEUE *fila, void (imprimirElemento)(TIPO2));


