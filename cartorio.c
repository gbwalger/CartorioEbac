#include <stdio.h> //biblioteca da comunicação do usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca que cuida das strings


	int registro() //função responsavel por cadastrar os usuários no sistema
{
	char arquivo[40]; //inicio da criação das variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
 	char cargo[40]; //final da criação das variaveis/strings
	
		printf("Digite o seu CPF: "); //obtendo a informação do usuário
		scanf("%s",cpf); //%s refere-se as strings
	
		strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e entra dentro dele para escrever por meio do "w"
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file, ","); //adiciona virgulas "," no arquivo
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrado: "); //obtendo informação do usuário
		scanf("%s",nome); // refere-se as strings
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file,nome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //entra e atualiza o arquivo "a"
		fprintf(file, ","); //adiciona virgulas "," dentro do arquivo 
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: "); //obtendo informação do usuário
		scanf("%s",sobrenome); // refere as strings
	
		file = fopen(arquivo, "a"); //abre o arquivo e atualiza ele "a" com novas informações
		fprintf(file,sobrenome); //salva o valor da variavel
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //abre o arquivo e atualiza ele "a" com novas informações
		fprintf(file, ","); //salva o arquivo com virgulas ","
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //obtendo informação do usuário
		scanf("%s",cargo); //refere as strings/conjuntos de variaveis
	
		file = fopen(arquivo,"a"); //atualiza o arquivo "a"
		fprintf(file,cargo); // salva o valor da variavel no arquivo
		fclose(file); // fecha o arquivo
	
		system("pause"); //pausa o programa para tempo de resposta do usuário
}

	int consulta() //função responsável por consultar os usuários
{
		setlocale(LC_ALL, "Portuguese"); //define a linguagem
	
	char cpf[40]; //inicio da criação de variaveis/strings
	char conteudo[200]; //final da criação de variaveis/strings
	
		printf("Digite o CPF a ser consultado: "); //obtendo informação do usuário
		scanf("%s",cpf); //refere-se as strings
	
		FILE *file; //criando arquivo
		file = fopen(cpf, "r"); //abrindo e lendo o arquivo
	
	if(file == NULL) // definindo algo que não exista no arquivo
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); // informando ao usuário
	}
	
	while(fgets(conteudo, 200,file) != NULL) //usando função while para que procure o arquivo consultado
	{
		printf("\n Essas são as informações do usuário:"); //informando ao usuário
		printf("%s",conteudo); //refere as strings
		printf("\n\n"); //apenas espaços
	}
	
		system("pause"); //pausa o sistema para tempo de resposta do usuário
}

	int deletar() //função responsavel por deletar os usuários
{
		char cpf[40]; //criação das variaveis
		char conteudo [200];
		
		printf("Digite o CPF a ser deletado: "); //obtendo informação do usuário
		scanf("%s",cpf); //refere as strings "%s"
		
		remove(cpf); //deletar o usuário desejado
		
		FILE *file; //criação do arquivo
		file = fopen(cpf,"r"); //abre o arquivo e lê ele "r" (read) significa 
		
		if (file == NULL) //definindo nulo se dentro do arquivo não encontrar nada 
		{
			printf("O usuário não se encontra no sistema! \n");	//mensagem ao usuário
		}
		
		system("pause");
}	


int main()
{
	int opcao=0; //definindo variavel
	int laco=1; //definindo variavel
	
	for(laco=1;laco=1;) //numero de repetições
	{
	
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:"); // final do menu
	
		scanf("%d", &opcao); //armazena a opção
	
		system("cls"); //limpa a tela
	
	switch(opcao) //inicio da seleção
	{
		case 1: //abre a função
		registro(); //chamada de funções
		break; //fecha a função
		
		case 2: //abre a função
		consulta(); //chamada de funções
		break; //fecha a função
		
		case 3: //abre a função
		deletar(); //chamada de funções
		break; //fecha a função
		
		case 4:
		printf("Obrigado por utilizar o sistema!");
		return 0;
		break;	
		
		default: //encerra a função
		printf("A opção escolhida não existe!\n"); //informação ao usuário por mensagem=
		system("pause"); // pausa para tempo de resposta
		break; //fecha a função
	}   //final da seleção
	
	}
	
}
