#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas string

int cadastrar() //Fun��o respons�vel por cadastrar os usu�rios
{
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o da linguagem
	
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[60];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //% refere-se a string e a letra � o comando dado a ela. "s" procurar, "r" ler, "a" atualizar
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e j� escreve nele
	fprintf(file,cpf); //Para salvar o CPF digitado
	fclose(file); //Fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,",");
	fclose(file); //Fechar arquivo
	
	printf("Digite o nome: "); //Coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,nome); //Para salvar o nome digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	printf("Digite o sobrenome: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,sobrenome); //Para salvar o sobrenome digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	printf("Digite o cargo: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,cargo); //Para salvar o cargo digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo ao inv�s de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	system("pause"); //Respons�vel por congelar a tela
	
}

int consultar() //Fun��o respons�vel por consultar os usu�rios j� cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" para ler arquivos
	
	if(file == NULL) //Instru��o caso o arquivo n�o seja localizado
	{
		printf("\n\nCPF n�o cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nCPF localizado com sucesso: \n\n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	
	fclose(file); //Para fechar o arquivo
	
	system("pause"); //Respons�vel por congelar a tela
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios j� cadastrados.
{
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o da linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", &cpf);
	
	remove(cpf);
			
	FILE *file;
	file = fopen(cpf,"r"); //"r" para ler o arquivo
	
	if(file == NULL);
	{
		printf("\n\nCPF n�o cadastrado! \n\n");
		system("pause"); //Comando para congelar a tela
	}
	
}

int main() //Fun��o principal que d� vida a tela inicial
{
	
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls"); //Comando para limpar a tela
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t<<< CART�RIO DA EBAC >>>\n\n\n"); //Cabe�alho do menu
		printf("\tESCOLHA A OP��O DESEJADA PARA INICIAR:\n\n\n");
		printf("\t1 - CADASTRAR ALUNO\n");
		printf("\t2 - CONSULTAR ALUNO\n");
		printf("\t3 - DELETAR ALUNO\n\n\n");
		printf("Op��o:"); //Fim do menu
	
		scanf("%d" , &opcao); //Necess�rio para armazenar a escolha do usu�rio
	
		system("cls"); //Para limpar a tela
	
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1: //Chamada da fun��o de cadastrar
			cadastrar();
			break; //Pausa na fun��o
			
			case 2: //Chamada da fun��o de consultar
			consultar();
			break; //Pausa na fun��o
			
			case 3: //Chamada da fun��o de deletar
			deletar();
			break; //Pausa na fun��o
			
			default: //Mensagem de erro quando o usu�rio escolher uma op��o inv�lida
			printf("\tEscolha uma op��o v�lida\n\n");
			system ("pause");
			break; //Pausa na fun��o
		}
	
	}
}


