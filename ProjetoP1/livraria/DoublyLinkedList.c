/*--------------------------------------------------*/
/*####	PROGRAMAÇÃO EM C	####*/
/*--------------------------------------------------*/
/*$$$$ DOUBLY LINKED LIST (implementação)	$$$$*/
/*$$$$ nome : doublyLinkedList_int.c	$$$$*/
/*$$$$ autor: Salvador Lima	$$$$*/
/*	*/
/*@@@@ DIRECTIVAS DE INCLUSÃO	@@@@*/
#include <stdio.h>
 #include <stdlib.h>
 #include <locale.h>

 #include "DoublyLinkedList.h"

 /*@@@@ TIPOS DE DADOS AGREGADOS	@@@@*/

/*@@@@ TIPOS ABSTRATOS DE DADOS (DEFINIÇÃO)	@@@@*/
 /* TIPOS AGREGADOS	*/
 /** int	**/
 typedef struct nodo {
	struct nodo *eloAnterior;
	TIPO dado;
	struct nodo *eloSeguinte;
 } NODO;

 struct lista {
	NODO *primeiroNodo;
	NODO *ultimoNodo;
 };

 /*@@@@ CODIFICAÇÕES DAS OPERAÇÕES DE LISTA	@@@@*/
 DLLIST *create() {
	DLLIST *lista = (DLLIST*) malloc(sizeof(DLLIST)); 

	if(lista != NULL) {
		lista->primeiroNodo = NULL; 
		lista->ultimoNodo = NULL;
			}

	return lista;
 }

 int insertend(DLLIST *lista, TIPO elemento) {
	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO *nodoNovo = (NODO*) malloc(sizeof(NODO)), *nodoAuxiliar;

	if (nodoNovo == NULL)
	 {
	return MEMORIA_ESGOTADA;
	}

	if (lista->primeiroNodo == NULL)
	{
		nodoNovo->eloAnterior = NULL;
		nodoNovo->dado = elemento;
		nodoNovo->eloSeguinte = NULL; 
	
		lista->primeiroNodo = nodoNovo; 
		
	}else {
		nodoAuxiliar = lista->primeiroNodo; 

		while(nodoAuxiliar->eloSeguinte != NULL){
		nodoAuxiliar = nodoAuxiliar->eloSeguinte; 
		}
		
		nodoNovo->eloAnterior = nodoAuxiliar; 
		nodoNovo->dado = elemento;
		nodoNovo->eloSeguinte = NULL;
		
		nodoAuxiliar->eloSeguinte = nodoNovo;
 	}

	return OK;
 }


 int insertbegin(DLLIST *lista, TIPO elemento) {

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO *nodoNovo = (NODO*) malloc(sizeof(NODO)); 

	if (nodoNovo == NULL) {
	return MEMORIA_ESGOTADA;
	}

	if (lista->primeiroNodo == NULL) {
	nodoNovo->eloAnterior = NULL;
	nodoNovo->dado = elemento;
	nodoNovo->eloSeguinte = NULL; 

		lista->primeiroNodo = nodoNovo; 	}
	else {
	nodoNovo->eloAnterior = NULL;
	nodoNovo->dado = elemento;
	nodoNovo->eloSeguinte = lista->primeiroNodo; 

	lista->primeiroNodo->eloAnterior = nodoNovo; 	lista->primeiroNodo = nodoNovo;
	}

	return OK;
 }

/*
 int Dweliminate(DLLIST *lista, int (*compararElemento)(TIPO, TIPO*), TIPO *elemento) {
 

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if (empty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	NODO *nodoAuxiliar;

	nodoAuxiliar = lista->primeiroNodo; 

	while (nodoAuxiliar != NULL) {
		if (compararElemento(nodoAuxiliar->dado, elemento) == VERDADEIRO) {
			if (nodoAuxiliar == lista->primeiroNodo) {
				lista->primeiroNodo = lista->primeiroNodo->eloSeguinte; 
				if(lista->primeiroNodo != NULL){
					lista->primeiroNodo->eloAnterior = NULL; 	
				}
			}else {
				if (nodoAuxiliar->eloSeguinte == NULL){
					nodoAuxiliar->eloAnterior->eloSeguinte = NULL; 
				}
				else{
					nodoAuxiliar->eloAnterior->eloSeguinte = nodoAuxiliar->eloSeguinte;
					nodoAuxiliar->eloSeguinte->eloAnterior = nodoAuxiliar->eloAnterior; 
				}
				free(nodoAuxiliar);
				nodoAuxiliar = NULL; 	
			}
		return OK;
		}
		nodoAuxiliar = nodoAuxiliar->eloSeguinte; 
	}
	return ELEMENTO_INEXISTENTE;
 }*/


 int size(DLLIST *lista) {

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	int nNodos=0;
 

	NODO *nodoAuxiliar = lista->primeiroNodo; 

	while(nodoAuxiliar != NULL) {
	nodoAuxiliar = nodoAuxiliar->eloSeguinte; 	nNodos++;
	}

	return nNodos;
 }


 int empty(DLLIST *lista) {

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	return (lista->primeiroNodo == NULL ? LISTA_VAZIA : OK);  }



 int view(DLLIST *lista, void (*imprimirElemento)(TIPO)) {

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if (empty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	NODO *nodo = lista->primeiroNodo; 

	while (nodo != NULL) {
	imprimirElemento(nodo->dado);
		nodo = nodo->eloSeguinte; 	}

	return OK;
 }


 int get(DLLIST *lista, int posicao, TIPO *elemento) {
	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(empty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	if(posicao > size(lista)) {
	return ELEMENTO_INEXISTENTE;
 
	}

	int contador = 0;
	NODO *nodo = lista->primeiroNodo; 

	while(++contador != posicao)
	 { 	
	
		nodo = nodo->eloSeguinte; 
			}

	*elemento = nodo->dado; 

	return OK;
 }


 int destroy(DLLIST **lista) {
	if (*lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO* nodoAuxiliar = (*lista)->primeiroNodo;

	while (nodoAuxiliar != NULL) {
	NODO *nodoSeguinte = nodoAuxiliar->eloSeguinte; 

	free(nodoAuxiliar);

		nodoAuxiliar = nodoSeguinte; 	}

	free(*lista);
	*lista = NULL; 

	return OK;
 }


 int convertListToArray(DLLIST *lista, TIPO *vetor) {
	if (lista == NULL){
		return LISTA_INEXISTENTE;
	}

	if (empty(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}

	int indice = 0;

	NODO *nodo = lista->primeiroNodo; 

	while (nodo != NULL) {
		vetor[indice] = nodo->dado; 
		indice++;
		nodo = nodo->eloSeguinte; 
	}

	return OK;
 }
 /*--------------------------------------------------*/

