#include <stdio.h> //biblioteca da comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca que cuida das strings


	int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	char arquivo[40]; //inicio da cria��o das variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
 	char cargo[40]; //final da cria��o das variaveis/strings
	
		printf("Digite o seu CPF: "); //obtendo a informa��o do usu�rio
		scanf("%s",cpf); //%s refere-se as strings
	
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e entra dentro dele para escrever por meio do "w"
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file, ","); //adiciona virgulas "," no arquivo
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrado: "); //obtendo informa��o do usu�rio
		scanf("%s",nome); // refere-se as strings
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file,nome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file, ","); //adiciona virgulas "," dentro do arquivo 
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: "); //obtendo informa��o do usu�rio
		scanf("%s",sobrenome); // refere as strings
	
		file = fopen(arquivo, "a"); //abre o arquivo e atualiza ele "a" com novas informa��es
		fprintf(file,sobrenome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo e atualiza ele "a" com novas informa��es
		fprintf(file, ","); //salva o arquivo com virgulas ","
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //obtendo informa��o do usu�rio
		scanf("%s",cargo); //refere as strings/conjuntos de variaveis
	
		file = fopen(arquivo,"a"); //atualiza o arquivo "a"
		fprintf(file,cargo); // salva o valor da variavel no arquivo
		fclose(file); // fecha o arquivo
	
		system("pause"); //pausa o programa para tempo de resposta do usu�rio
}

	int consulta() //fun��o respons�vel por consultar os usu�rios
{
		setlocale(LC_ALL, "Portuguese"); //define a linguagem
	
	char cpf[40]; //inicio da cria��o de variaveis/strings
	char conteudo[200]; //final da cria��o de variaveis/strings
	
		printf("Digite o CPF a ser consultado: "); //obtendo informa��o do usu�rio
		scanf("%s",cpf); //refere-se as strings
	
		FILE *file; //criando arquivo
		file = fopen(cpf, "r"); //abrindo e lendo o arquivo
	
	if(file == NULL) // definindo algo que n�o exista no arquivo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); // informando ao usu�rio
	}
	
	while(fgets(conteudo, 200,file) != NULL) //usando fun��o while para que procure o arquivo consultado
	{
		printf("\n Essas s�o as informa��es do usu�rio:"); //informando ao usu�rio
		printf("%s",conteudo); //refere as strings
		printf("\n\n"); //apenas espa�os
	}
	
		system("pause"); //pausa o sistema para tempo de resposta do usu�rio
}

	int deletar() //fun��o responsavel por deletar os usu�rios
{
		char cpf[40]; //cria��o das variaveis
		char conteudo [200];
		
		printf("Digite o CPF a ser deletado: "); //obtendo informa��o do usu�rio
		scanf("%s",cpf); //refere as strings "%s"
		
		remove(cpf); //deletar o usu�rio desejado
		
		FILE *file; //cria��o do arquivo
		file = fopen(cpf,"r"); //abre o arquivo e l� ele "r" (read) significa 
		
		if (file == NULL) //definindo nulo se dentro do arquivo n�o encontrar nada 
		{
			printf("O usu�rio n�o se encontra no sistema! \n");	//mensagem ao usu�rio
		}
		
		system("pause");
}	


int main()
{
	int opcao=0; //definindo variavel
	int laco=1; //definindo variavel
	
	for(laco=1;laco=1;) //numero de repeti��es
	{
	
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Selecione a op��o desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o:"); // final do menu
	
		scanf("%d", &opcao); //armazena a op��o
	
		system("cls"); //limpa a tela
	
	switch(opcao) //inicio da sele��o
	{
		case 1: //abre a fun��o
		registro(); //chamada de fun��es
		break; //fecha a fun��o
		
		case 2: //abre a fun��o
		consulta(); //chamada de fun��es
		break; //fecha a fun��o
		
		case 3: //abre a fun��o
		deletar(); //chamada de fun��es
		break; //fecha a fun��o
		
		case 4:
		printf("Obrigado por utilizar o sistema!");
		return 0;
		break;	
		
		default: //encerra a fun��o
		printf("A op��o escolhida n�o existe!\n"); //informa��o ao usu�rio por mensagem=
		system("pause"); // pausa para tempo de resposta
		break; //fecha a fun��o
	}   //final da sele��o
	
	}
	
}
