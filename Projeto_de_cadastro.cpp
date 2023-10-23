#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de memória.
#include <locale.h> //biblioteca de alocação de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.


//FUNÇÃO DE CADASTRO
int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	//criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char funcao[40];
	//final da criação de varáveis
	
	printf("\t==========> CADASTRO DE ALUNO <==========\n\n");
	printf("\tDigite o CPF: "); //coleta do CPF a ser cadastrado
	scanf("%s", cpf); //armazenando o dado coletado na string de CPF
	
	strcpy(arquivo, cpf); //responsável por criar os valores das strings
	FILE *file; //para criar o arquivo
	file = fopen(arquivo, "w"); //criando o arquivo e escrevendo nele com "w"
	fprintf(file,cpf); //para salvar a informação dentro do arquivo
	fclose(file); //fechando o arquivo
	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando com "a"
	fprintf(file,", ");
	fclose(file); //fechando o arquivo atualizado
	
	printf("\tDigite o nome: ");
	scanf("%s",nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("\tDigite o sobrenome: ");
	scanf("%s",sobrenome);
	file = fopen(arquivo, "a");
	fprintf (file,sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("\tDigite a função: ");
	scanf("%s",funcao);
	file = fopen(arquivo, "a");
	fprintf(file,funcao);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ". ");
	fclose(file);
		
	system ("pause"); //congelar a tela
}

//FUNÇÃO DE CONSULTAS
int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	//criando variáveis
	char cpf[40];
	char conteudo[200];
	char *token; //variável para dividir as strings em linhas.
		
	printf("\t==========> CONSULTA DE ALUNO <==========\n\n");
	printf("\tDigite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf, "r"); //abrindo e lendo o arquivo com "r"
		
	if(file == NULL) //função responsável por exibir a tela de erro caso o usuário digite um CPF inexistente
	{
		printf("\nCPF não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\t==========> RESULTADO DA BUSCA <==========\n\n");
		
		token = strtok(conteudo, ","); //variável para dividir o resultado da consulta em linhas.
		printf("CPF: %s\n", token); //informação para aparecer antes dos dados do CPF.
		
		token = strtok(NULL, ",");
		printf("NOME: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("SOBRENOME: %s\n", token);
		
		token = strtok(NULL, ".");
		printf("FUNÇÃO: %s", token);
		
		printf("\n\n");		
	}
	system ("pause"); //congelando a tela
	fclose(file); //fechando o arquivo que tinha os resultados da busca
}

//FUNÇÃO PARA DELETAR
int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	//criando variável
	char cpf[40];
	
	printf("\t==========> DELETAR ALUNO <==========\n\n");
	printf("\tDigite o CPF a ser deletado: ");
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nCPF não localizado!\n\n");
		system ("pause");
		return 0;
	}
	
	if(remove(cpf) == 0){
		printf("\nCPF deletado com sucesso!\n\n");
	}else {
		printf("\nNão foi possível remover o CPF!\n\n");
	}
	
	system ("pause");
		
}

//FUNÇÃO DA TELA INICIAL

int main()
{
	int opcao=0; //definindo variável para inteiro.
	int laco=1;
	
	//inicio tela de loguin
	char senhadigitada[10]="a";
	int comparacao;

	setlocale(LC_ALL, "portuguese"); //definindo a linguagem.
	printf("\t==========> REGISTRO DE USUÁRIO | LOGIN <==========\n\n");
	printf("\tDIGITE SUA SENHA: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{
			system("cls");
			setlocale(LC_ALL, "portuguese");
	
			//tela inicial
			printf("\t==========> REGISTRO DE USUÁRIO <==========\n\n");
			printf("\tDIGITE A OPÇÃO DESEJADA:\n\n");
			printf("\t1 - CADASTRAR ALUNO\n\t2 - CONSULTAR ALUNO\n\t3 - DELETAR ALUNO\n\t4 - SAIR\n\n");
			printf("\tOPÇÃO:\n");
			//fim da tela inicial
	
			scanf("%d", &opcao); //armazenando a escolha do usuário (nesse caso inteiro ["%d"]
	
			system("cls"); //função para limpar a tela.
	
			//inicio da seleção.
			switch(opcao)
			{
				case 1:
				registro(); //chamada da função de cadastro
				break;
			
				case 2:
				consulta(); //chamada da função de consulta
				break;
			
				case 3:
				deletar(); //chamada da função de deletar
				break;
			
				case 4: //chamada da opção para saída
				printf("\n\n\n\t========== (:  ATÉ LOGO  :) ==========\n\n");
				return 0;
				break;
			
				default:					
				printf("\tOpção inválida. Insira uma opção válida.\n\n");
				system("pause");
				break;
			}//fim da seleção.
		}
	}
	
	else
		system("cls");
		printf("\n\n\tSenha incorreta!\n\n");
	//fim tela de loguin		
		
}
