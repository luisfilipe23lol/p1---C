/*__________________________________________*/
/*####		 PROGRAMAÇÃO  EM  C	        ### */
/*_________________________________________	*/
/*$$$$ 		LINKED QUEUE  (implementaçao) $$*/
/*$$$$  nome  : linkedQueue_TIPO.h     $$$$$*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

/* DIRECTIVAS DE INCLUSAO */
#include "singlyLinkedList_TIPO2.h"

/* DIRECTIVAS DE DEFENIÇAO */
	/* CODIGO DE AVALIAÇAO CONDICIONAL */
#define FALSO 0
#define VERDADEIRO 1

	/* CODIGO DE ORDENAÇAO */
#define CRESCENTE 1
#define DECRESCENTE -1

	/* CODIGO DE AVALIAÇAO DA FILA */
#define OK 0
#define FILA_VAZIA -1
#define FILA_INEXISTENTE -2
#define ELEMENTO_INEXISTENTE -1
#define MEMORIA_ESGOTADA -5
#define NULO -6

/* @@@@ intS DE DADOS AGREGADOS ( DECLARAÇAO) @@@@*/
typedef struct lista LQUEUE;


	/* PROTIPOS DAS OPERAÇOES SOBBRE A FILA*/
LQUEUE *screate();

int enqueue(LQUEUE *fila, TIPO2 elemento);

int dequeue (LQUEUE *fila, TIPO2 *elemento);

int qpeek(LQUEUE *fila, TIPO2 *elemento);

int size (LQUEUE *fila);

int empty (LQUEUE *fila);

int destroy (LQUEUE **fila);

int sview (LQUEUE *fila, void (imprimirElemento)(TIPO2));


