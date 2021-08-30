/*__________________________________________*/
/*####	PROGRAMAÇÃO  EM  C	###        		*/
/*_________________________________________	*/
/*$$$$  DATA  TYPE  (interface)	$$$$   		*/
/*$$$$  nome  :  dataType.h	$$$$       		*/
/*$$$$  autor:  (c)  Salvador  Lima	$$$$	*/
/*__________________________________________*/

  #ifndef   _DATATYPE3
  #define  _DATATYPE3

  //  conceito  de  int


 //  conceito  de  CARRO


  #define T_nome 25
  #define T_descricao1 50

  struct utilizador{
    	int id;				// id do utilizador
    	char nome[50];		//nome do utilizador
		char username[50];	//username para login
		char password[50];	
		int tipo;	//Tipo de utilizador (1-Administrador 2-decisor)
		int nOrcamentos_analisados;
	};

  typedef  struct  utilizador  UTILIZADOR;
  
  //  definição  de  TIPO

  typedef  UTILIZADOR  TIPOuser;

  
 #endif
/*----------------------*/





