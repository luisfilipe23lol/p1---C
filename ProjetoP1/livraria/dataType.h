/*__________________________________________*/
/*####	PROGRAMAÇÃO  EM  C	###        		*/
/*_________________________________________	*/
/*$$$$  DATA  TYPE  (interface)	$$$$   		*/
/*$$$$  nome  :  dataType.h	$$$$       		*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

  #ifndef   _DATATYPE 
  #define  _DATATYPE 

  //  conceito  de  int

  #define  INTEIRO  int 
 //  conceito  de  CARRO


  #define T_nome 25
  #define T_descricao1 50

  struct  items  {
	char  nome[T_nome];
	char  descricao[T_descricao1];
	float  preco;
	int  ano;
  };

  typedef  struct  items  ITEMS;
  
  //  definição  de  TIPO

  typedef  ITEMS  TIPO;

  
 #endif
/*----------------------*/





