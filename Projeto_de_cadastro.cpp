#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das strings.


//FUN��O DE CADASTRO
int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	//cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char funcao[40];
	//final da cria��o de var�veis
	
	printf("\t==========> CADASTRO DE ALUNO <==========\n\n");
	printf("Digite o CPF: "); //coleta do CPF a ser cadastrado
	scanf("%s", cpf); //armazenando o dado coletado na string de CPF
	
	strcpy(arquivo, cpf); //respons�vel por criar os valores das strings
	FILE *file; //para criar o arquivo
	file = fopen(arquivo, "w"); //criando o arquivo e escrevendo nele com "w"
	fprintf(file,cpf); //para salvar a informa��o dentro do arquivo
	fclose(file); //fechando o arquivo
	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando com "a"
	fprintf(file,", ");
	fclose(file); //fechando o arquivo atualizado
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s",sobrenome);
	file = fopen(arquivo, "a");
	fprintf (file,sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite a fun��o: ");
	scanf("%s",funcao);
	file = fopen(arquivo, "a");
	fprintf(file,funcao);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ". ");
	fclose(file);
		
	system ("pause"); //congelar a tela
}

//FUN��O DE CONSULTAS
int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	//criando vari�veis
	char cpf[40];
	char conteudo[200];
	char *token; //vari�vel para dividir as strings em linhas.
		
	printf("\t==========> CONSULTA DE ALUNO <==========\n\n");
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf, "r"); //abrindo e lendo o arquivo com "r"
		
	if(file == NULL) //fun��o respons�vel por exibir a tela de erro caso o usu�rio digite um CPF inexistente
	{
		printf("\nCPF n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\t==========> RESULTADO DA BUSCA <==========\n\n");
		
		token = strtok(conteudo, ","); //vari�vel para dividir o resultado da consulta em linhas.
		printf("CPF: %s\n", token); //informa��o para aparecer antes dos dados do CPF.
		
		token = strtok(NULL, ",");
		printf("NOME: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("SOBRENOME: %s\n", token);
		
		token = strtok(NULL, ".");
		printf("FUN��O: %s", token);
		
		printf("\n\n");		
	}
	system ("pause"); //congelando a tela
	fclose(file); //fechando o arquivo que tinha os resultados da busca
}

//FUN��O PARA DELETAR
int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	//criando vari�vel
	char cpf[40];
	
	printf("\t==========> DELETAR ALUNO <==========\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nCPF n�o localizado!\n\n");
		system ("pause");
		return 0;
	}
	
	if(remove(cpf) == 0){
		printf("\nCPF deletado com sucesso!\n\n");
	}else {
		printf("\nN�o foi poss�vel remover o CPF!\n\n");
	}
	
	system ("pause");
		
}

//FUN��O DA TELA INICIAL

int main()
{
	int opcao=0; //definindo vari�vel para inteiro.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem.
	
		//tela inicial
		printf("\t==========> CART�RIO DA EBAC <==========\n\n");
		printf("\tDIGITE A OP��O DESEJADA:\n\n");
		printf("\t1 - CADASTRAR ALUNO\n\t2 - CONSULTAR ALUNO\n\t3 - DELETAR ALUNO\n\n");
		printf("\tOP��O:\n");
		//fim da tela inicial
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio (nesse caso inteiro ["%d"]
	
		system("cls"); //fun��o para limpar a tela.
	
		//inicio da sele��o.
		switch(opcao)
		{
			case 1:
			registro(); //chamada da fun��o de cadastro
			break;
			
			case 2:
			consulta(); //chamada da fun��o de consulta
			break;
			
			case 3:
			deletar(); //chamada da fun��o de deletar
			break;
			
			default:					
			printf("\tOp��o inv�lida. Insira uma op��o v�lida.\n\n");
			system("pause");
			break;
		}//fim da sele��o.		
	}	
}
