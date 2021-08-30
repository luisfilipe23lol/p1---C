/*__________________________________________*/
/*####	PROGRAMAÇÃO  EM  C	###        		*/
/*_________________________________________	*/
/*$$$$  DATA  TYPE  (interface)	$$$$   		*/
/*$$$$  nome  :  dataType.h	$$$$       		*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

  #ifndef   _DATATYPE2 
  #define  _DATATYPE2 


#include <time.h>
  //  conceito  de  int

  #define  INTEIRO  int 
 //  conceito  de  CARRO


#define DATA_SIZE 1000 

  #define T_identificador 10
  #define T_nome1 50
  #define T_descricao 255
  #define T_estado 30
  #define T_justificacao 255
  #define T_user 50
  #define T_resultado 50
  
  struct  orcamento  {
  	int id;
  	char identificador[T_identificador];
	char  nome_fornecedor[T_nome1];
	char  descricao[T_descricao];
	float  montante_total;
	char lista[20+T_identificador];
	char estado[T_estado];
	char resultado[T_resultado];
	int dia;
	int mes;
	int ano;
	int hora;
	int min;
	char justificacao[T_justificacao];
	char user[T_user];	
  };

  typedef  struct  orcamento  ORCAMENTO;
  
  //  definição  de  TIPO

  typedef  ORCAMENTO  TIPO2;

  
 #endif
/*----------------------*/





