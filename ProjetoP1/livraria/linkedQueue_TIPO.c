/*__________________________________________*/
/*####		 PROGRAMA��O  EM  C	        ### */
/*_________________________________________	*/
/*$$$$ 		LINKED QUEUE  (implementa�ao) $$*/
/*$$$$  nome  : linkedQueue_TIPO.c     $$$$$*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

/* DIRECTIVAS DE INCLUSAO */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "linkedQueue_TIPO.h"

/*@@@@ CODIFICA�OES DAS OPERA�OES DA FILA @@@@*/
int enqueue (LQUEUE *fila, TIPO2 elemento){
	return insertend (fila,elemento);
}

int dequeue (LQUEUE *fila, TIPO2 *elemento){
	return deletebegin (fila, elemento);
}

int qpeek (LQUEUE *fila, TIPO2 *elemento){
	return peekbegin(fila,elemento); // peekbegin consultar a cabe�a
}


