#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável pelas string

int cadastrar() //Função responsável por cadastrar os usuários
{
	
	setlocale(LC_ALL, "Portuguese"); //Definição da linguagem
	
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[60];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF: "); //Coletando informação do usuário
	scanf("%s",cpf); //% refere-se a string e a letra é o comando dado a ela. "s" procurar, "r" ler, "a" atualizar
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e já escreve nele
	fprintf(file,cpf); //Para salvar o CPF digitado
	fclose(file); //Fechar arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,",");
	fclose(file); //Fechar arquivo
	
	printf("Digite o nome: "); //Coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,nome); //Para salvar o nome digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	printf("Digite o sobrenome: "); //Coletando informação do usuário
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,sobrenome); //Para salvar o sobrenome digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	printf("Digite o cargo: "); //Coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,cargo); //Para salvar o cargo digitado
	fclose(file); //Para fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo ao invés de criar um novo
	fprintf(file,",");
	fclose(file); //Para fechar o arquivo
	
	system("pause"); //Responsável por congelar a tela
	
}

int consultar() //Função responsável por consultar os usuários já cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Definição da linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" para ler arquivos
	
	if(file == NULL) //Instrução caso o arquivo não seja localizado
	{
		printf("\n\nCPF não cadastrado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nCPF localizado com sucesso: \n\n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}
	
	fclose(file); //Para fechar o arquivo
	
	system("pause"); //Responsável por congelar a tela
	
}

int deletar() //Função responsável por deletar os usuários já cadastrados.
{
	
	setlocale(LC_ALL, "Portuguese"); //Definição da linguagem
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", &cpf);
	
	remove(cpf);
			
	FILE *file;
	file = fopen(cpf,"r"); //"r" para ler o arquivo
	
	if(file == NULL);
	{
		printf("\n\nCPF não cadastrado! \n\n");
		system("pause"); //Comando para congelar a tela
	}
	
}

int main() //Função principal que dá vida a tela inicial
{
	
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls"); //Comando para limpar a tela
		setlocale(LC_ALL, "Portuguese");
	
		printf("\t<<< CARTÓRIO DA EBAC >>>\n\n\n"); //Cabeçalho do menu
		printf("\tESCOLHA A OPÇÃO DESEJADA PARA INICIAR:\n\n\n");
		printf("\t1 - CADASTRAR ALUNO\n");
		printf("\t2 - CONSULTAR ALUNO\n");
		printf("\t3 - DELETAR ALUNO\n\n\n");
		printf("Opção:"); //Fim do menu
	
		scanf("%d" , &opcao); //Necessário para armazenar a escolha do usuário
	
		system("cls"); //Para limpar a tela
	
		switch(opcao) //Início da seleção do menu
		{
			case 1: //Chamada da função de cadastrar
			cadastrar();
			break; //Pausa na função
			
			case 2: //Chamada da função de consultar
			consultar();
			break; //Pausa na função
			
			case 3: //Chamada da função de deletar
			deletar();
			break; //Pausa na função
			
			default: //Mensagem de erro quando o usuário escolher uma opção inválida
			printf("\tEscolha uma opção válida\n\n");
			system ("pause");
			break; //Pausa na função
		}
	
	}
}


