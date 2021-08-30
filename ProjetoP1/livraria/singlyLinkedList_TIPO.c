	/* _________________________________________________*/	
	/*####_____________PROGRAMAÇÃO EM C___________####*/
	/* _________________________________________________*/
	/*$$$$ SINGLY LINKED LIST (implementação)	$$$$*/ 
	/*$$$$ nome : sLinkedList_TIPO2.c		$$$$*/  
	/*$$$$ autor: Bruno Rodriges					$$$$*/ 
	/*__________________________________________________*/
 
/*@@@@ DIRECTIVAS DE INCLUSÃO	@@@@*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "singlyLinkedList_TIPO2.h"

/*@@@@ TIPO2S ABSTRATOS DE DADOS (DEFINIÇÃO)	@@@@*/
typedef struct nodo {
	TIPO2 dado;
	struct nodo *elo;
} NODO;
struct lista {
	NODO *primeiroNodo;
};
/*@@@@ CODIFICAÇÕES DAS OPERAÇÕES DE LISTA	@@@@*/

SLLIST *screate() {
	SLLIST *lista = (SLLIST*) malloc(sizeof(SLLIST)); 
	if(lista != NULL) {
	lista->primeiroNodo = NULL; // (*lista).primeiro = NULL;
	}
	return lista;
}

int sinsertend(SLLIST *lista, TIPO2 elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO *nodoNovo = (NODO*) malloc(sizeof(NODO)), *nodoAuxiliar;
	if(nodoNovo == NULL) {
	return MEMORIA_ESGOTADA;
	}

	if(lista->primeiroNodo == NULL) {
	nodoNovo->dado = elemento;
	nodoNovo->elo = NULL;
	lista->primeiroNodo = nodoNovo;	
	}
	else {
	nodoAuxiliar = lista->primeiroNodo; 
 
	while(nodoAuxiliar->elo != NULL) {		
		nodoAuxiliar = nodoAuxiliar->elo;	
	}

	nodoNovo->dado = elemento;
	nodoNovo->elo = NULL;
	nodoAuxiliar->elo = nodoNovo;	

	}
	return OK;
 }
 
 int sinsertbegin(SLLIST *lista, TIPO2 elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO *nodoNovo = (NODO*) malloc(sizeof(NODO));	if(nodoNovo == NULL) {
	return MEMORIA_ESGOTADA;
	}

	nodoNovo->dado = elemento;
	nodoNovo->elo = lista->primeiroNodo;
	lista->primeiroNodo = nodoNovo; 

	return OK;
}
/*int eliminate(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2*), TIPO2*elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	NODO *nodoVisitado, *nodoAuxiliar;
	nodoAuxiliar = lista->primeiroNodo; 
	while(nodoAuxiliar != NULL) {
	if(compararElemento(nodoAuxiliar->dado, elemento) == VERDADEIRO){

	if(nodoAuxiliar == lista->primeiroNodo) {		
		lista->primeiroNodo = nodoAuxiliar->elo;	}
	else {
		nodoVisitado->elo = nodoAuxiliar->elo;	
	}
 
	free(nodoAuxiliar);
	nodoAuxiliar = NULL; 
	return OK;
	}
	else {
	nodoVisitado = nodoAuxiliar;
		nodoAuxiliar = nodoAuxiliar->elo;	}
	}
	return ELEMENTO_INEXISTENTE;
 }*/
 int ssize(SLLIST *lista) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	int nNodos = 0;
	NODO *nodoAuxiliar = lista->primeiroNodo; 
	while(nodoAuxiliar != NULL) {
	nodoAuxiliar = nodoAuxiliar->elo;	nNodos++;
	}
	return nNodos;
}

 int sempty(SLLIST *lista) {
	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	return (lista->primeiroNodo == NULL ? LISTA_VAZIA : OK); 
 }

 int sview(SLLIST *lista, void (*imprimirElemento)(TIPO2)) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}
	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}
	NODO *nodo = lista->primeiroNodo;
	while(nodo != NULL) {
	imprimirElemento(nodo->dado);
 
		nodo = nodo->elo; }
	return OK;
}

 int sget(SLLIST *lista, int posicao, TIPO2 *elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	if(posicao > ssize(lista)) {
	return POSICAO_INEXISTENTE;
	}

	int contador = 0;
	NODO *nodo = lista->primeiroNodo; 
	while(++contador != posicao) {
		nodo = nodo->elo; 	
	}

	*elemento = nodo->dado; 
	return OK;
 }
 
 
 //editar nodo
  int editar(SLLIST *lista, int posicao, TIPO2 elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	if(posicao > ssize(lista)) {
	return POSICAO_INEXISTENTE;
	}

	int contador = 0;
	NODO *nodo = lista->primeiroNodo; 
	while(++contador != posicao) {
		nodo = nodo->elo; 	
	}
	
	nodo->dado = elemento;
	//*elemento = nodo->dado; 
	return OK;
 }

 int eliminar(SLLIST **lista) {

	if(*lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	NODO *nodoAuxiliar = (*lista)->primeiroNodo;

	while(nodoAuxiliar != NULL) {
	NODO *nodoSeguinte = nodoAuxiliar->elo; 
	free(nodoAuxiliar);

		nodoAuxiliar = nodoSeguinte; 
			}

	free(*lista);
	*lista = NULL; 
	return OK;
 }

 int sconvertListToArray(SLLIST *lista, TIPO2 *vetor) {

	if(lista == NULL) {
 
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	int indice = 0;

	NODO *nodo = lista->primeiroNodo; 
	while(nodo != NULL) {
	vetor[indice] = nodo->dado; 
	indice++;
		nodo = nodo->elo; 
			}

	return 0;
 }


 int bubbleSortList(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2), int ordem) {

	if(lista == NULL) {
		return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}

	int i, j, k; 
	TIPO2 eTemporario;

	int nNodos = ssize(lista); 
	NODO *nodoAuxiliar1, *nodoAuxiliar2;

	k = nNodos; 
	for(i = 1; i < nNodos; i++, k--) {
		nodoAuxiliar1 = lista->primeiroNodo; 
		nodoAuxiliar2 = nodoAuxiliar1->elo; 
		for(j = 1; j < k; j++) {
			if(((*compararElemento)(nodoAuxiliar1->dado, nodoAuxiliar2->dado) == VERDADEIRO && ordem == CRESCENTE) || ((*compararElemento)(nodoAuxiliar1->dado, nodoAuxiliar2->dado) == VERDADEIRO && ordem == DECRESCENTE)) {
				eTemporario = nodoAuxiliar1->dado;
				nodoAuxiliar1->dado = nodoAuxiliar2->dado;
				nodoAuxiliar2->dado = eTemporario;
			}
			nodoAuxiliar1 = nodoAuxiliar1->elo;
			nodoAuxiliar2 = nodoAuxiliar2->elo; 
		}
	}

	return OK;
 }


 int insertafter(SLLIST *lista, int posicao, TIPO2 elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	NODO *nodoAuxiliar;

	int i;

	nodoAuxiliar = lista->primeiroNodo; 
	for(i = 1; i < posicao; i++) {
	nodoAuxiliar = nodoAuxiliar->elo; 
	if(nodoAuxiliar == NULL) {
	return POSICAO_INEXISTENTE;
	}
	}

	NODO *nodoNovo = (NODO*) malloc(sizeof(NODO)); 
	nodoNovo->dado = elemento;
	nodoNovo->elo = nodoAuxiliar->elo; 	nodoAuxiliar->elo = nodoNovo;

	return OK;
 }


 int search(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2*), TIPO2 *elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

 
	if(elemento == NULL) {
	return NULO;
	}

	NODO *nodoAuxiliar;

	nodoAuxiliar = lista->primeiroNodo; 
	while(nodoAuxiliar != NULL) {
		if(compararElemento(nodoAuxiliar->dado, elemento)==0) {
			return OK;
		}
		nodoAuxiliar = nodoAuxiliar->elo; 
	}

	return ELEMENTO_INEXISTENTE;
 }


 int reverse(SLLIST *lista) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	NODO *nodoAuxiliar1 = lista->primeiroNodo, *nodoAuxiliar2 = NULL,*nodoAuxiliar3 = NULL;

	while(nodoAuxiliar1 != NULL) {
	nodoAuxiliar3 = nodoAuxiliar2;
	nodoAuxiliar2 = nodoAuxiliar1;
	nodoAuxiliar1 = nodoAuxiliar1->elo; 
	nodoAuxiliar2->elo = nodoAuxiliar3; 
	     }

	lista->primeiroNodo = nodoAuxiliar2; 
	return OK;
 }


 int selectionSortList(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2), int ordem) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}
 

	int i, j, k; 
	TIPO2 eElemento;

	int nNodos = ssize(lista); 
	NODO *nodoAuxiliar1, *nodoAuxiliar2;

	k = nNodos; 
	nodoAuxiliar1 = lista->primeiroNodo; 
	for(i = 1; i <= nNodos; i++) {
	nodoAuxiliar2 = nodoAuxiliar1->elo; 
	for(j = i + 1; j <= nNodos; j++) {
	if((compararElemento(nodoAuxiliar1->dado, nodoAuxiliar2->dado) == VERDADEIRO && ordem == CRESCENTE) ||
	(compararElemento(nodoAuxiliar1->dado, nodoAuxiliar2->dado) == VERDADEIRO && ordem == DECRESCENTE)) {
	eElemento = nodoAuxiliar1->dado;
	nodoAuxiliar1->dado = nodoAuxiliar2->dado;
		nodoAuxiliar2->dado = eElemento; 
			}

		nodoAuxiliar2 = nodoAuxiliar2->elo; 
			}

		nodoAuxiliar1 = nodoAuxiliar1->elo; 
			}

	return 0;
 }


 int rinsertend(SLLIST *lista, TIPO2 elemento) {

	if(lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	return _rinsertend(&(lista->primeiroNodo), elemento); 
	 }

 int _rinsertend(NODO **nodo, TIPO2 elemento) {
	if(*nodo == NULL) {

	*nodo = (NODO*) malloc(sizeof(NODO)); 

		if(*nodo == NULL) {
	return MEMORIA_ESGOTADA;
	}

	(*nodo)->dado = elemento;
	(*nodo)->elo = NULL;
 

	return OK;
	}

	else {
		return _rinsertend(&((*nodo)->elo), elemento); 
	}
 }

 int deletebegin(SLLIST *lista, TIPO2 *elemento) {

	if (lista == NULL) {
	return LISTA_INEXISTENTE;
	}

	if (sempty(lista) == LISTA_VAZIA) {
	return LISTA_VAZIA;
	}

	if (elemento == NULL) {
	return NULO;
	}

	NODO *nodoAuxiliar;
	nodoAuxiliar = lista->primeiroNodo; 
	*elemento = nodoAuxiliar->dado;
	lista->primeiroNodo = nodoAuxiliar->elo; 
	free(nodoAuxiliar);	nodoAuxiliar = NULL; 

	return OK;
}
int peekbegin(SLLIST *lista,TIPO2 *elemento) {

	if (lista == NULL) {
		return LISTA_INEXISTENTE;
	}

	if (sempty(lista) == LISTA_VAZIA) {
		return LISTA_VAZIA;
	}

	if (elemento == NULL) {
		return NULO;
	}

	*elemento = lista->primeiroNodo->dado; 
	return OK;
 }

 
 
 int deleteend(SLLIST *lista, TIPO2 *elemento){ // eliminar no fim
	if(lista == NULL){
		return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}

	if(elemento == NULL){
		return NULO;
	}

	NODO *nodoVisitado, * nodoAuxiliar;

	nodoVisitado = NULL;
	nodoAuxiliar = lista->primeiroNodo;

	while(nodoAuxiliar->elo != NULL){
		nodoVisitado = nodoAuxiliar;
		nodoAuxiliar = nodoAuxiliar->elo;
	}

	*elemento = nodoAuxiliar->dado;

	if(nodoVisitado != NULL){
		nodoVisitado->elo = NULL;
	}
	else{
		lista->primeiroNodo = NULL;
	}

	free(nodoAuxiliar);
	nodoAuxiliar = NULL;

	return OK;

}

	
	
	
	
	int eliminarposicao(SLLIST *lista, int posicao) {

		if(lista == NULL) {
			return LISTA_INEXISTENTE;
		}
	
		if(sempty(lista) == LISTA_VAZIA) {
			return LISTA_VAZIA;
		}
	
		if(posicao > ssize(lista)) {
			return POSICAO_INEXISTENTE;
		}

		NODO *nodoVisitado, * nodoAuxiliar;

		nodoVisitado = NULL;
		nodoAuxiliar = lista->primeiroNodo;
		if(posicao==0){
			lista->primeiroNodo=nodoAuxiliar->elo;
		}
		
		int contador = 0;
		while(++contador != posicao) {
			nodoVisitado = nodoAuxiliar;
			nodoAuxiliar = nodoAuxiliar->elo;
		}
		
		if(nodoVisitado != NULL){
			nodoVisitado->elo = nodoAuxiliar->elo;
		}
		else{
			nodoVisitado->elo = NULL;
		}

		free(nodoAuxiliar);
		nodoAuxiliar = NULL;
	
		return OK;
 }
 
 
 
 
 



int peekend(SLLIST *lista, TIPO2 *elemento){
	if(lista == NULL){
		return LISTA_INEXISTENTE;
	}

	if(sempty(lista) == LISTA_VAZIA){
		return LISTA_VAZIA;
	}

	if(elemento == NULL){
		return NULO;
	}

	NODO *nodoAuxiliar = lista->primeiroNodo;

	while(nodoAuxiliar->elo != NULL){
		nodoAuxiliar = nodoAuxiliar->elo;
	}

	*elemento = nodoAuxiliar->dado;

	return OK;

}

 /*__________________________________________________*/

