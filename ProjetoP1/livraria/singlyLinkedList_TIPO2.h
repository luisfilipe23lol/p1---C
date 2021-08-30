/*--------------------------------------------------*/
/*####       PROGRAMA��O EM C	       	    ####*/
/*--------------------------------------------------*/
/*$$$$ APLICACAO							    $$$$*/
/*$$$$ nome : principal.c			    		$$$$*/  
/*$$$$ autor:Bruno Rodrigues 	      		    $$$$*/
/*--------------------------------------------------*/
  
  
  
  /*@@@@  DIRECTIVAS  DE  INCLUS�O	@@@@*/
  #include  "dataType2.h"

 /*@@@@  DIRECTIVAS  DE  DEFIN��O	@@@@*/
	/*  C�DIGO  DE  AVALIA��O  CONDICIONAL	*/
  #define  FALSO  0
  #define  VERDADEIRO  1

	/*  C�DIGO  DE  ORDENA��O	*/
  #define  CRESCENTE  1
  #define  DECRESCENTE  -1

	/*  C�DIGO  DE  AVALIA��O  DA  LISTA	*/
  #define  OK  0
  #define  LISTA_VAZIA  -1
  #define  LISTA_INEXISTENTE  -2
  #define  POSICAO_INEXISTENTE  -3
  #define  ELEMENTO_INEXISTENTE  -1
  #define  MEMORIA_ESGOTADA  -5
  #define  NULO  -6

  /*@@@@  TIPO2S  ABSTRATO  DE  DADOS  (DECLARA��O)	@@@@*/
  typedef  struct lista SLLIST;

 /*@@@@ PROT�TIPO2S DAS OPERA��ES SOBRE LISTA	@@@@*/
 SLLIST *screate();

 int sinsertend(SLLIST *lista, TIPO2 elemento); 

 int sinsertbegin(SLLIST *lista, TIPO2 elemento); 
 
 int seliminate(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2*), TIPO2*elemento);

 int ssize(SLLIST *lista);

 int sempty(SLLIST *lista);

 int sview(SLLIST *lista, void (*imprimirElemento)(TIPO2));

 int sget(SLLIST *lista, int posicao, TIPO2 *elemento);
 
 int editar(SLLIST *lista, int posicao, TIPO2 elemento);

 int eliminar(SLLIST **lista);

 int sconvertListToArray(SLLIST *lista, TIPO2 *vetor);

 int bubbleSortList(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2), int ordem);
 
 int insertafter(SLLIST *lista, int posicao, TIPO2 elemento); 

 int search(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2*), TIPO2 *elemento);

 int reverse(SLLIST *lista);

 int selectionSortList(SLLIST *lista, int (*compararElemento)(TIPO2, TIPO2), int ordem);

 int rinsertend(SLLIST *lista, TIPO2 elemento); 

 int deletebegin(SLLIST *lista, TIPO2 *elemento);

 int peekbegin(SLLIST *lista, TIPO2 *elemento);
 
 int deleteend(SLLIST *lista, TIPO2 *elemento);
 
 int eliminarposicao(SLLIST *lista, int posicao);

 int peekend(SLLIST *lista, TIPO2 *elemento);	
 /* 	-*/

