#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include <string.h>
#include <ctype.h>

#include "..\livraria\dataType_USER.h"
#include "..\livraria\dataType2.h"
#include "..\livraria\dataType.h"
#include "..\livraria\inputValues.h"
#include "..\livraria\DoublyLinkedList.h"
#include "..\livraria\linkedQueue_TIPO.h"

#define n 10 		//numero de utilizadores
#define t_identificador 5

    struct UTILIZADOR{
    	int id;				// id do utilizador
    	char nome[50];		//nome do utilizador
		char username[50];	//username para login
		char password[50];	
		int tipo;	//Tipo de utilizador (1-Administrador 2-decisor)
		int nOrcamentos_analisados;
	}utilizador[n];
	
	
void exportar(int *users){
	FILE *fp=fopen("users.bin","wb");	//abre o ficheiro binario em modo escrita 
	fwrite(users,sizeof(int),1,fp);							//escreve no ficheiro a quantidade de Utilizador
	fwrite(utilizador,sizeof(struct UTILIZADOR),n,fp);				//escreve a struct Utilizador
	printf("Exportação concluida");		
	fclose(fp);												//fecha o ficheiro binario
}
void importar(int *users){
	FILE *fp=fopen("users.bin","rb");		//abre o ficheiro binario em modo leitura 
	fread(users,sizeof(int),1,fp);									//le do ficheiro a quantidade de Utilizador
	fread(utilizador,sizeof(struct UTILIZADOR),n,fp);					//le do ficheiro a strucut Utilizador
//	printf("Importação concluida");
	fclose(fp);													//fecha o ficheiro binario
}

//criar utilizadores
criarUser(int *users){		
	char username[50];
	char nome[50];
	int i=1;
	system("cls");
	printf("\n\t Criar utilizador");
	printf("\nNome do utilizador\n");
	fflush(stdin);
	gets(nome);
	printf("\nUsername\n");
	fflush(stdin);
	gets(username);
	for(i=1;i<=*users;i++){

		if(!strcmp(utilizador[i].username,username)){	
			printf("\n\nEsse Username já existe!!\n");
			printf("\nUtilizador não criado!!\n");
			system("pause");
			break;
		}else {
			if(i==*users){
			//copia o username
			utilizador[*users].id=*users;
			strcpy(utilizador[*users].username,username);	
			strcpy(utilizador[*users].nome,nome);	
			// pede para inserir password
			printf("\nPassword\n");						
			fflush(stdin);
			gets(utilizador[*users].password);
			//Tipo de utilizador
			printf("\nTipo de utilizador: \n");
			printf(" 1 - Administrador");
			printf("\n 2 - Decisor");
			printf("\n => ");
			scanf("%i",&utilizador[*users].tipo);
			
			*users=*users+1;
			printf("\nUtilizador criado com sucesso \n");
			system("pause");
			break;		
			}
		}	
	}
	exportar(users);	
}


int login(int *users){
	char username[50];
	char password[50];
	int i;
	
	system("cls");
	
	printf("\n\tLogin");
	printf("\n Username: ");
	fflush(stdin);
	gets(username);
	printf("\n Password: ");
	fflush(stdin);
	gets(password);

	//verificar login
	for(i=0;i<=*users;i++){
		if(!strcmp(username,utilizador[i].username)){		
			if(!strcmp(password,utilizador[i].password)){
				printf("\n\nLogin efectuado com sucesso.\n\n");
				system("Pause");
				return utilizador[i].id;
			}else{		
				printf("\n\nUsername ou password incorretos!!\n\n");
				system("pause");
				return 0;
			}
		}
	}	
	printf("\n\nUsername ou password incorretos!!\n\n");
	system("pause");

	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////



//listar os items - só lista um
void listarItems2(ITEMS *items){

		printf("\n");
		printf("Nome: %s",(*(items)).nome);
		printf("Descrição: %s",(*(items)).descricao);
		printf("Preco: %.2f",(*(items)).preco);
		printf("\nAno: %i",(*(items)).ano);
		printf("\n\n");
}


//exportar os orçamentos analisados e por analisar pro ficheiro
void exportar_lista(SLLIST *fila,char nome[],int nOrcamentos){
	char name[25+t_identificador]={"../files/orcamentos_"};
	strcat(name,nome);
	strcat(name,".txt");
	
	FILE *fp = fopen(name,"w");
	
	if(fp == NULL){
		printf("\n\nErro ao abrir o ficheiro\n\n");
		exit(1);	//aborta o programa
	}
	
	ORCAMENTO *orcamento = (ORCAMENTO*) calloc(nOrcamentos,sizeof(ORCAMENTO));
									
	sconvertListToArray(fila,orcamento);
	
	int i=0;
	fprintf(fp,"%i\n",nOrcamentos);
	printf("Orçamentos: %i",nOrcamentos);
	for(i=1;i<=nOrcamentos;i++){
		fprintf(fp,"\n");
		fprintf(fp,"%i\n",(*(orcamento+i-1)).id);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).identificador);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).nome_fornecedor);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).descricao);
		fprintf(fp,"%.2f\n",(*(orcamento+i-1)).montante_total);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).estado);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).resultado);
		
		fprintf(fp,"%i\n",(*(orcamento+i-1)).dia);
		fprintf(fp,"%i\n",(*(orcamento+i-1)).mes);
		fprintf(fp,"%i\n",(*(orcamento+i-1)).ano);
		fprintf(fp,"%i\n",(*(orcamento+i-1)).hora);
		fprintf(fp,"%i\n",(*(orcamento+i-1)).min);

		fprintf(fp,"%s\n",(*(orcamento+i-1)).justificacao);
		fprintf(fp,"%s\n",(*(orcamento+i-1)).user);
	}
		
	free(orcamento);
	fclose(fp);
}

//exporta a lista de items
void exportarListaItems(DLLIST *lista,int nItems,char ident[t_identificador]){
	char name[25+t_identificador]={"../files/List_"};
	strcat(name,ident);
	strcat(name,".txt");
	
	FILE *fp = fopen(name,"w");
	
	if(fp == NULL){
		printf("\n\nErro ao abrir o ficheiro\n\n");
		exit(1);	//aborta o programa
	}
	
	ITEMS *items = (ITEMS*) calloc(nItems,sizeof(ITEMS));
									
	convertListToArray(lista,items);
	
	int i=0;
	fprintf(fp,"%i\n",nItems);
	for(i=nItems;i!=0;i--){
		fprintf(fp,"\n");
		fputs((*(items+i-1)).nome,fp);fprintf(fp,"\n");
		fputs((*(items+i-1)).descricao,fp);fprintf(fp,"\n");
		
	//	fprintf(fp,"%s\n",(*(items+i-1)).nome);
	//	fprintf(fp,"%s\n",(*(items+i-1)).descricao);
		fprintf(fp,"%.2f\n",(*(items+i-1)).preco);
		fprintf(fp,"%i\n",(*(items+i-1)).ano);
	}
	
	free(items);
	fclose(fp);
}

//importa a lista de items
void importarListaItems(DLLIST *lista, int *nItems,char ident[t_identificador]){
	char identificador[t_identificador];
	int i=0;
	
	char name[20+t_identificador]={"../files/List_"};
	strcat(name,ident);
	strcat(name,".txt");
	
	FILE *fp = fopen(name,"r");
	if(fp == NULL){
		printf("\n\nErro ao abrir o ficheiro %s\n\n",name);
		exit(1);	//aborta o programa
	}
	ITEMS item;
	char trash;
	
	fscanf(fp,"%i\n",nItems);
	
	for(i=0;i<*nItems;i++){
		fscanf(fp,"\n",&trash);
		fgets(item.nome,T_nome,fp);
		fscanf(fp,"\n",&trash);
		fgets(item.descricao,T_descricao,fp);
		fscanf(fp,"\n",&trash);
		
		fscanf(fp,"%f",&item.preco);
		fscanf(fp,"\n",&trash);
		
		fscanf(fp,"%i",&item.ano);
		fscanf(fp,"\n",&trash);
		insertend(lista,item);
	}
}

//serve para comparar os identificadores dos orçamentos
void compara_Nome(ORCAMENTO orcamento1,ORCAMENTO *orcamento2){
	if(strcmp(orcamento1.identificador,(*orcamento2).identificador)==0){
		return OK;

	}
}

//serve para inserir os orçamentos
void InserirOrcamento(SLLIST *fila,int *nOrcamentos){
	int nItems=0;
	int opcao=0;
	float preco=0;
	
	DLLIST *items = NULL;
	
	items = create();
	
	
	ORCAMENTO orcamento;
	
	system("cls");
	printf("Inserir Orçamento");
	orcamento.id=*nOrcamentos;
	sequencia("\n\nIntroduza o identificador do orçamento: ",orcamento.identificador,T_identificador);
	
	int resultado=search(fila,compara_Nome,&orcamento);
	if(resultado==0){
		printf("\nEsse identificador já existe");
		sequencia("\nIntroduza o identificador do orçamento: ",orcamento.identificador,T_identificador);
	}
		
	sequencia("\nNome do fornecedor do orçamento: ",orcamento.nome_fornecedor,T_nome);
	sequencia("\nDescrição do orçamento: ",orcamento.descricao,T_descricao);
	printf("\n\nLista de items (MAX.20)\n");
	do{
		ITEMS item;
		sequencia("\nNome: ",item.nome,T_nome);
		sequencia("\nDescrição: ",item.descricao,T_descricao);
		item.preco=real("\nPreço: ");
		item.ano=inteiro("\nAno: ");
		nItems++;
		preco+=item.preco;
		insertend(items,item);
		opcao=inteiro("Deseja adicionar mais items? (0-Sim, 1-Não)");
	}while(opcao!=1);
	orcamento.montante_total=preco;
	strcpy(orcamento.estado,"para analisar");
	strcpy(orcamento.resultado,"sem resultado");
	strcpy(orcamento.justificacao,"sem justificacao");
	strcpy(orcamento.user,"sem user");
	
	//////////////////////////////
	//Data e hora				//
	//////////////////////////////
	/*struct tm *p;
	time_t seconds;
	time(&seconds);
	p = localtime(&seconds);
	char dia[10];
	strcpy(dia,p->tm_mday);*/
	///////////////////////////////////////
	//Data e hora do sistema		     //
	//***********************************//
	//Dia: data_hora_atual.tm_mday       //
	//Mes: data_hora_atual.tm_mon+1      //
	//Ano: data_hora_atual.tm_year+1900  //
	//***********************************//
	//Hora: data_hora_atual.tm_hour      //
	//Minutos: data_hora_atual.tm_min 	 //
	//Segundos: data_hora_atual.tm_sec	 //
	///////////////////////////////////////
	struct tm *data_hora_atual;     	  
	time_t segundos;   
	time(&segundos);    
	data_hora_atual = localtime(&segundos); 
	 
	char data[DATA_SIZE];
	///////////////////////////////////////

	orcamento.dia=data_hora_atual->tm_mday;
	orcamento.mes=data_hora_atual->tm_mon+1;
	orcamento.ano=data_hora_atual->tm_year+1900;
	orcamento.hora=data_hora_atual->tm_hour;
	orcamento.min=data_hora_atual->tm_min;
	

	exportarListaItems(items,nItems,orcamento.identificador);
	
	sinsertend(fila,orcamento);
	*nOrcamentos+=1;
	
	exportar_lista(fila,"por_analisar",*nOrcamentos);
	
}

//listar o orçamento (para aprovação)
void listar(ORCAMENTO orcamento){
	int nItems;
	
	DLLIST *items = NULL;
	items=create();
	//importar lista de itens
	
	importarListaItems(items,&nItems,orcamento.identificador);
	
	printf("\nIdentificador: %s",orcamento.identificador);
	printf("\nFornecedor: %s",orcamento.nome_fornecedor);
	printf("\nDescrição: %s",orcamento.descricao);
	printf("\nLista de itens");
	//Listar itens
	
	view(items,listarItems2);
	
	printf("\nTotal: %.2f",orcamento.montante_total);
	printf("\n\nEstado: %s\n",orcamento.estado);
}


//qd importamos um ficheiro o scanf lê um \n e esta função serve para o remover
void tratarDados(ORCAMENTO *orcamento){

	int qnt=strlen((*orcamento).identificador)-1;
	if((*orcamento).identificador[qnt]=='\n'){
		(*orcamento).identificador[qnt]='\0';
	}
	
	qnt=strlen((*orcamento).nome_fornecedor)-1;
	if((*orcamento).nome_fornecedor[qnt]=='\n'){
		(*orcamento).nome_fornecedor[qnt]='\0';
	}
	
	qnt=strlen((*orcamento).descricao)-1;
	if((*orcamento).descricao[qnt]=='\n'){
		(*orcamento).descricao[qnt]='\0';
	}
	
	qnt=strlen((*orcamento).estado)-1;
	if((*orcamento).estado[qnt]=='\n'){
		(*orcamento).estado[qnt]='\0';
	}
	
	qnt=strlen((*orcamento).resultado)-1;
	if((*orcamento).resultado[qnt]=='\n'){
		(*orcamento).resultado[qnt]='\0';
	}
	
	qnt=strlen((*orcamento).justificacao)-1;
	if((*orcamento).justificacao[qnt]=='\n'){
		(*orcamento).justificacao[qnt]='\0';
	}

	qnt=strlen((*orcamento).user)-1;
	if((*orcamento).user[qnt]=='\n'){
		(*orcamento).user[qnt]='\0';
	}

}

//importar orçamentos dos ficheiros
void importar_orcamentos(SLLIST *fila,int *nOrcamentos,char nome[]){
	char name[25+t_identificador]={"../files/orcamentos_"};
	strcat(name,nome);
	strcat(name,".txt");
	
	FILE *fp = fopen(name,"r");
	
	if(fp == NULL){
		printf("\n\nO ficheiro não existe\n\n");
	}else{
		
		ORCAMENTO orcamento;
										
		char trash;
		int i=0;
		fscanf(fp,"%i",nOrcamentos);
		for(i=*nOrcamentos;i!=0;i--){
			fscanf(fp,"\n",&trash);
			fscanf(fp,"%i",&orcamento.id);
			fscanf(fp,"\n",&trash);
			
			fgets(orcamento.identificador,T_identificador,fp);
		
			
			fgets(orcamento.nome_fornecedor,T_nome,fp);
		
			
			fgets(orcamento.descricao,T_descricao,fp);
	
			
			fscanf(fp,"%f",&orcamento.montante_total);
			fscanf(fp,"\n",&trash);
			
			fgets(orcamento.estado,T_estado,fp);

			
			fgets(orcamento.resultado,20,fp);
	
			
			fscanf(fp,"%i",&orcamento.dia);
			fscanf(fp,"\n",&trash);
			fscanf(fp,"%i",&orcamento.mes);
			fscanf(fp,"\n",&trash);
			fscanf(fp,"%i",&orcamento.ano);
			fscanf(fp,"\n",&trash);
			fscanf(fp,"%i",&orcamento.hora);
			fscanf(fp,"\n",&trash);
			fscanf(fp,"%i",&orcamento.min);
			fscanf(fp,"\n",&trash);
					
			
			fgets(orcamento.justificacao,T_justificacao,fp);

			fgets(orcamento.user,T_user,fp);
		
			
			tratarDados(&orcamento);
			sinsertend(fila,orcamento);			
		}	
	}
	
	fclose(fp);

}


//lista os orçamentos que estão por analisar 
void listar_por_analisar(SLLIST *fila){

    ORCAMENTO por_analisar;
    int i=0;
    int size=ssize(fila);
    if(size==0){
    	printf("\nNão existem orçamentos\n");
	}else{
		printf("\nIdentificador do orçamento: \n");
    for(i=1;i<=size;i++)
    {
        sget(fila,i,&por_analisar);
        printf("%i => %s\n",i,por_analisar.identificador);
    }
	} 
}

//listar os orçamentos analisados
void listar_analisado(SLLIST *fila, int type){
    ORCAMENTO por_analisar;
    int i=0;
    int size=ssize(fila);
    printf("Identificador do orçamento: \n");
    for(i=1;i<=size;i++)
    {
        sget(fila,i,&por_analisar);
         if(type==1){
            if(strcmp(por_analisar.resultado,"Aprovado")==0 || (strcmp(por_analisar.resultado,"aprovado"))==0){
                printf(" %i => %s\n",i,por_analisar.identificador);
            }
        }
        else if(type==2){
            printf(" %i => %s\n",i,por_analisar.identificador);
        }
    }
}

//listar os orçamentos pelo valor introduzido
void listar_orc_montante_total(SLLIST *fila){
	float total=real("\nIntroduza o valor para listar os orcamentos com um valor superior: ");

    ORCAMENTO orcamento;
    int i=0;
    int size=ssize(fila);
    for(i=1;i<=size;i++)
    {
        sget(fila,i,&orcamento);
        if(orcamento.montante_total>total){
        	printf("\nIdentificador: %s\n",orcamento.identificador);
   	 	}
    }
}

//menu decisor - funçao aprovar
void funcaoaprovar(SLLIST *fila, SLLIST *analisados, int user,int *nOrcamentos_por_analisar,int *nOrcamentos_analisados){
	if(ssize(fila)==0){
		printf("\nNão existem orcamentos por aprovar\n\n");
		system("pause");
	}else{
		
		
  		ORCAMENTO orcamento3;
	    ORCAMENTO orcamento4;
	    peekbegin(fila,&orcamento3);
	    listar(orcamento3);
	    sequencia("Resultado: ", orcamento3.resultado,T_resultado);
	    sequencia("Justificação: ", orcamento3.justificacao,T_justificacao);
	    strcpy(orcamento3.user,utilizador[user].nome);
	    strcpy(orcamento3.estado,"analisado");
	   if(deletebegin(fila,&orcamento4)!=0){
			printf("Erro ao eliminar orçamento");
		}
		*nOrcamentos_por_analisar-=1;
		if(sinsertend(analisados,orcamento3)!=0){
			printf("Erro ao inserir orçamento nos aprovados");
		}
		*nOrcamentos_analisados+=1;
		utilizador[user].nOrcamentos_analisados++;
		
	    
	   
	  	exportar_lista(fila,"por_analisar",*nOrcamentos_por_analisar);
	  
		exportar_lista(analisados,"analisado",*nOrcamentos_analisados);
	
	}
}

//função para pesquisar através do nome do fornecedor
void pesquisa(SLLIST *fila, SLLIST *analisados){
	char nome1[T_nome1];
	sequencia("\nNome do Fornecedor: ",nome1,T_nome1);

    ORCAMENTO orcamento;
    int i=0;
    int size=ssize(fila);
    if(size!=0){
    	for(i=1;i<=size;i++)
	    {
	        sget(fila,i,&orcamento);
	        if(strcmp(orcamento.nome_fornecedor,nome1)==0){
	        	printf(" Identificador do orçamento: %s\n",orcamento.identificador);
	   	 	}
	    }
	}
	 size=ssize(analisados);
    if(size!=0){
    	for(i=1;i<=size;i++)
	    {
	        sget(analisados,i,&orcamento);
	        if(strcmp(orcamento.nome_fornecedor,nome1)==0){
	        	printf(" Identificador do orçamento: %s\n",orcamento.identificador);
	   	 	}
	    }
	}
    
}


int comparaMin(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.min>(*orcamento2).min){
		return 1;
	}
	else
	return 0;
}
int comparaHora(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.hora>(*orcamento2).hora){
		return 1;
	}
	else
	return 0;
}
int comparaDia(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.dia>(*orcamento2).dia){
		return 1;
	}
	else
	return 0;
}
int comparaMes(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.mes>(*orcamento2).mes){
		return 1;
	}
	else
	return 0;
}
int comparaAno(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.ano>(*orcamento2).ano){
		return 1;
	}
	else
	return 0;
}
int comparaDecisao(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(strcmp(orcamento1.resultado,"aprovado")==1 || strcmp(orcamento1.resultado,"Aprovado")==1){
		return 1;
	}
	else
	return 0;
}
int comparaMontante(ORCAMENTO orcamento1 ,ORCAMENTO *orcamento2){
	if(orcamento1.montante_total>(*orcamento2).montante_total){
		return 1;
	}
	else
	return 0;
}

int comparaInt(int valor1,int valor2){
	if(valor1<valor2){
		return 1;
	}
	else
	return 0;
}

//lista os orçamentos ordenados por data e decisão de um dado decisor
void Lista_Resultado_ordenado(SLLIST *fila,int users){
	char nome[T_nome];
	sequencia("Introduza o nome do decisor: ",nome,T_nome);
	ORCAMENTO orcamento;
	SLLIST *temp;
	temp = screate();
	int i=0;
	int size=ssize(fila);
	for(i=0;i<=users;i++){
		if(strcmp(utilizador[i].nome,nome)==0){
			if(utilizador[i].tipo==2){
				for(i=1;i<=size;i++){
					sget(fila,i,&orcamento);
					if(strcmp(orcamento.user,nome)==0){
						sinsertend(temp,orcamento);
					}	
				}
				
				bubbleSortList(temp,comparaMin,1);
				bubbleSortList(temp,comparaHora,1);
				bubbleSortList(temp,comparaDia,1);
				bubbleSortList(temp,comparaMes,1);
				bubbleSortList(temp,comparaAno,1);
				bubbleSortList(temp,comparaDecisao,1);
				listar_por_analisar(temp);
				break;
			}
		}
	}

}

//exporta e cria o ficheiro com os orçamentos analisados - ordenados por montante / caso este nao exista, ele cria, se já existe, escreve por cima
void exportar_orcamentos_analisados(SLLIST *fila,int nOrcamentos){
    char name[25]={"../files/relatorio.txt"};

    FILE *fp = fopen(name,"w");

    if(fp == NULL){
        printf("\n\nErro ao abrir o ficheiro\n\n");
        exit(1);    //aborta o programa
    }

    ORCAMENTO *orcamento = (ORCAMENTO*) calloc(nOrcamentos,sizeof(ORCAMENTO));

    bubbleSortList(fila,comparaMontante,1);

    sconvertListToArray(fila,orcamento);

    int i=0;
    fprintf(fp,"Relatório de orçamentos analisados\n");
    fprintf(fp,"\nIdentificador => Valor\n");
    for(i=1;i<=nOrcamentos;i++){

        fprintf(fp,"%s => %.2f\n",(*(orcamento+i-1)).identificador,(*(orcamento+i-1)).montante_total);

    }

    free(orcamento);
    fclose(fp);
}

int Menu_admin(){
int op=0;
		system("cls");
					printf(" **************Menu****************\n");
					printf("\n");			    
					printf(" | 1 - Registar utilizador        |\n");
					printf(" | 2 - Inserir orçamento          |\n");
					printf(" | 3 - Alterar orçamento          |\n");
					printf(" | 4 - Apagar orçamento           |\n");
					printf(" | 5 - Pesquisar/Listar orçamento |\n");
					printf(" | 99 - Sair                      |\n");
					op=inteiro("\n Introduza a opção: ");
					return op;
	}

	void Menu_admin_pesquisa(){
		system("cls");
		printf(" ***************************************Menu********************************************\n");
		printf("\n");
		printf(" | 1 - Listar os orçamentos por analisar                                               |\n");
		printf(" | 2 - Listar os orçamentos analisados                                                 |\n");
		printf(" | 3 - Listar todos os orçamentos analisados e aprovados                               |\n");
		printf(" | 4 - Listar todos os orçamentos com montante acima de um dado valor                  |\n");
		printf(" | 5 - Listar todos os orçamentos de um determinado decisor                            |\n");
		printf(" | 6 - Pesquisar orçamentos por nome de fornecedor                                     |\n");
		printf(" | 7 - Orçamentos analisados, ordenados por montante                                   |\n");
		printf(" | 8 - Gerar o ranking de utilizadores por número de orçamentos analisados e decididos |\n");
		printf(" | 9 - Voltar ao menu anterior                                                         |\n");
	}
	
	int Menu_decisor(int orcamentos){
		
		int op;
		system("cls");
		printf(" **********Menu*************\n");
		printf("\n");
		printf("Existem %i orçamentos para analisar\n",orcamentos);
		printf(" | 1 - Analisar orçamento |\n");
		printf(" | 2 - Sair               |\n");
		op=inteiro("\nIntroduza a opção: ");
		return op;
	}
void main(){
	setlocale(LC_ALL,"Portuguese");
	int users=0;
	int op=0;
	int op2=0;
	FILE * file;
	
	int nItems=0;
	int nOrcamentos_por_analisar=0;
	int nOrcamentos_analisados=0;

	//Fila dos orçamentos inseridos		
	SLLIST *fila=NULL;
	fila=screate();
	if(fila==NULL){
		printf("erro ao criar fila de orcamentos");
	}
	
	//Fila dos orçamentos analisados
	SLLIST *analisados;
	analisados=screate();
	if(analisados==NULL){
		printf("erro ao criar fila de orcamentos");
	}
	
	//lista criada para os items
	DLLIST *items = NULL;
	items = create();
    if(items == NULL){
    	printf("\nErro ao criar a lista\n");
	}
	
	
	if (!(file = fopen("users.bin","rb"))) 
    {
    	users=1;
   		criarUser(&users);	//registo
   		main();
    }else
	{
   		fclose(file);
        importar(&users);	//importar utilizadores
        
		importar_orcamentos(fila,&nOrcamentos_por_analisar,"por_analisar");	//importar por analisar 
        importar_orcamentos(analisados,&nOrcamentos_analisados,"analisado");	//importar por analisar 
        
        
        
		int user=login(&users); //login
		while(user==0){
			printf("\n\nTente novamente.\n\n");
			system("pause");
			user=login(&users); //login
		}
		
		if(user!=0)
		{
			if(utilizador[user].tipo==1)
			{	
				
				do{
					op=Menu_admin();
					switch(op){
						
						case 1:
						{
							criarUser(&users);
							break;
						} 
						case 2:
							{
								InserirOrcamento(fila,&nOrcamentos_por_analisar);
								break;
							}
						case 3:{
							//funçao alterar orçamento
							break;
						}
						case 4:{
							//apagar orçamento
							break;
						}
						case 5:{
							
							do{
							Menu_admin_pesquisa();
							op2 = inteiro("\nIntroduza a opção: ");
							
								switch(op2){
									case 1:{
										listar_por_analisar(fila); //listar orçamentos por analisar
										break;
									}
									case 2:{
										listar_analisado(analisados,2); //listar orçamentos analisados
										break;
									}
									case 3:{
										listar_analisado(analisados,1); //listar orçamentos analisados e aprovados
										break;
									}
									case 4:{
										listar_orc_montante_total(fila); //listar todos os orçamentos com montante acima de um dado valor
										break;
									}
									case 5:{
										Lista_Resultado_ordenado(analisados,users);
										//aprovado/não aprovado
										break;
									}
									case 6:{
										pesquisa(fila,analisados);
									 //pesquisar orçamentos por nome de fornecedor
										break;
									}
									case 7:{
										exportar_orcamentos_analisados(analisados,nOrcamentos_analisados);	//escrever num ficheiro
										printf("Ficheiro exportado com sucesso\n");
									break;
									}
									case 8:{
										//gerar o ranking
									break;
									}
								}
								system("pause");
							}while(op2!=9);
							break;
						}
					}
					linha();
					system("pause");
				}while(op!=99);
			}
			else{
				int op=0;
				do{
				
					op = Menu_decisor(nOrcamentos_por_analisar); //menu decisor
					switch(op){
						case 1:{
							funcaoaprovar(fila,analisados,user,&nOrcamentos_por_analisar,&nOrcamentos_analisados);
							break;
						}
						case 2:{
							exit(0); 
							break;
						}
					}
				}while(op!=0);
			}
			
			exportar(&users);
		}
	
	}
}

