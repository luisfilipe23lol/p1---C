/*--------------------------------------------------*/
/*####	PROGRAMAÇÃO EM C	####*/
/*--------------------------------------------------*/
/*$$$$ DOUBLY LINKED LIST (interface)	$$$$*/
/*$$$$ nome : doublyLinkedList_int.h	$$$$*/
/*$$$$ autor: Salvador Lima	$$$$*/
/*	*/
/*@@@@ DIRECTIVAS DE INCLUSÃO	@@@@*/
 /*@@@@ DIRECTIVAS DE DEFINÇÃO	@@@@*/
	/* CÓDIGO DE AVALIAÇÃO CONDICIONAL	*/
 #define FALSO 0
 #define VERDADEIRO 1

	/* CÓDIGO DE ORDENAÇÃO	*/
 #define CRESCENTE 1
 #define DECRESCENTE -1

	/* CÓDIGO DE AVALIAÇÃO DA LISTA	*/
 #define OK 0
 #define LISTA_VAZIA -1
 #define LISTA_INEXISTENTE -2
 #define POSICAO_INEXISTENTE -3
 //#define ELEMENTO_INEXISTENTE -4
 #define ELEMENTO_INEXISTENTE -1
 #define MEMORIA_ESGOTADA -5
 
 #include "..\livraria\dataType.h"


 /*@@@@ TIPOS DE DADOS AGREGADOS (DECLARAÇÃO)	@@@@*/
 typedef struct lista DLLIST; 
/*@@@@ PROTÓTIPOS DAS OPERAÇÕES SOBRE LISTA	@@@@*/
 /* descrição: Cria uma lista
	valores de retorno: referência da lista ou
	NULL
 */
 DLLIST *create();

 /* descrição: Coloca um elemento no fim da lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int insertend(DLLIST *lista, TIPO elemento); 

 /* descrição: Coloca um elemento no início da lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int insertbegin(DLLIST *lista, TIPO elemento); 

 /* descrição: Elimina um elemento da lista
	valores de retorno: OK,
 
	LISTA_INEXISTENTE,
	ELEMENTO_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int Dweliminate(DLLIST *lista, TIPO (*compararElemento)(TIPO, TIPO*), TIPO *elemento);

 /* descrição: Determina o número de nodos da lista
	valores de retorno: número de nodos
 */
 int size(DLLIST *lista);

 /* descrição: Verifica o estado vazio da lista
	valores de retorno: OK ou
	LISTA_INEXISTENTE
 */
 int empty(DLLIST *lista);

 /* descrição: Visualiza a lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	LISTA_VAZIA
 */
 int view(DLLIST *lista, void (*imprimirElemento)(TIPO));

 /* descrição: Acede ao elemenento da lista
	valores de retorno: OK ou
	LISTA_INEXISTENTE
 */
 int get(DLLIST *lista, int posicao, TIPO *elemento);

 /* descrição: Destroi a lista
	valores de retorno: OK,
	LISTA_INEXISTENTE,
	LISTA_VAZIA ou
	ELEMENTO_INEXISTENTE
 */
 int destroy(DLLIST **lista);

 /* descrição: Converte a lista num vetor
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	LISTA_VAZIA
 */
 int convertListToArray(DLLIST *lista, TIPO *vetor);
/*--------------------------------------------------*/

