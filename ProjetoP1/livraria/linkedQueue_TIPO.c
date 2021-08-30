/*__________________________________________*/
/*####		 PROGRAMAÇÃO  EM  C	        ### */
/*_________________________________________	*/
/*$$$$ 		LINKED QUEUE  (implementaçao) $$*/
/*$$$$  nome  : linkedQueue_TIPO.c     $$$$$*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

/* DIRECTIVAS DE INCLUSAO */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "linkedQueue_TIPO.h"

/*@@@@ CODIFICAÇOES DAS OPERAÇOES DA FILA @@@@*/
int enqueue (LQUEUE *fila, TIPO2 elemento){
	return insertend (fila,elemento);
}

int dequeue (LQUEUE *fila, TIPO2 *elemento){
	return deletebegin (fila, elemento);
}

int qpeek (LQUEUE *fila, TIPO2 *elemento){
	return peekbegin(fila,elemento); // peekbegin consultar a cabeça
}


