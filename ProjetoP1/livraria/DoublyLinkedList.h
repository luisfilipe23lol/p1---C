/*--------------------------------------------------*/
/*####	PROGRAMA��O EM C	####*/
/*--------------------------------------------------*/
/*$$$$ DOUBLY LINKED LIST (interface)	$$$$*/
/*$$$$ nome : doublyLinkedList_int.h	$$$$*/
/*$$$$ autor: Salvador Lima	$$$$*/
/*	*/
/*@@@@ DIRECTIVAS DE INCLUS�O	@@@@*/
 /*@@@@ DIRECTIVAS DE DEFIN��O	@@@@*/
	/* C�DIGO DE AVALIA��O CONDICIONAL	*/
 #define FALSO 0
 #define VERDADEIRO 1

	/* C�DIGO DE ORDENA��O	*/
 #define CRESCENTE 1
 #define DECRESCENTE -1

	/* C�DIGO DE AVALIA��O DA LISTA	*/
 #define OK 0
 #define LISTA_VAZIA -1
 #define LISTA_INEXISTENTE -2
 #define POSICAO_INEXISTENTE -3
 //#define ELEMENTO_INEXISTENTE -4
 #define ELEMENTO_INEXISTENTE -1
 #define MEMORIA_ESGOTADA -5
 
 #include "..\livraria\dataType.h"


 /*@@@@ TIPOS DE DADOS AGREGADOS (DECLARA��O)	@@@@*/
 typedef struct lista DLLIST; 
/*@@@@ PROT�TIPOS DAS OPERA��ES SOBRE LISTA	@@@@*/
 /* descri��o: Cria uma lista
	valores de retorno: refer�ncia da lista ou
	NULL
 */
 DLLIST *create();

 /* descri��o: Coloca um elemento no fim da lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int insertend(DLLIST *lista, TIPO elemento); 

 /* descri��o: Coloca um elemento no in�cio da lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int insertbegin(DLLIST *lista, TIPO elemento); 

 /* descri��o: Elimina um elemento da lista
	valores de retorno: OK,
 
	LISTA_INEXISTENTE,
	ELEMENTO_INEXISTENTE ou
	MEMORIA_ESGOTADA
 */
 int Dweliminate(DLLIST *lista, TIPO (*compararElemento)(TIPO, TIPO*), TIPO *elemento);

 /* descri��o: Determina o n�mero de nodos da lista
	valores de retorno: n�mero de nodos
 */
 int size(DLLIST *lista);

 /* descri��o: Verifica o estado vazio da lista
	valores de retorno: OK ou
	LISTA_INEXISTENTE
 */
 int empty(DLLIST *lista);

 /* descri��o: Visualiza a lista
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	LISTA_VAZIA
 */
 int view(DLLIST *lista, void (*imprimirElemento)(TIPO));

 /* descri��o: Acede ao elemenento da lista
	valores de retorno: OK ou
	LISTA_INEXISTENTE
 */
 int get(DLLIST *lista, int posicao, TIPO *elemento);

 /* descri��o: Destroi a lista
	valores de retorno: OK,
	LISTA_INEXISTENTE,
	LISTA_VAZIA ou
	ELEMENTO_INEXISTENTE
 */
 int destroy(DLLIST **lista);

 /* descri��o: Converte a lista num vetor
	valores de retorno: OK,
	LISTA_INEXISTENTE ou
	LISTA_VAZIA
 */
 int convertListToArray(DLLIST *lista, TIPO *vetor);
/*--------------------------------------------------*/

