#include <stdio.h>//biblioteca de comunicaçao com o usuario
#include <stdlib.h>//biblioteca de alocaçao de espaço em memoria
#include <locale.h>//biblioteca de alocacao de texto por regiao
#include <string.h>//Biblioteca responsavel por cuidar das strins

int registrar()//funçao responsavel por cadastrar Usuarios
{
	//Inicio da criacao de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criacao de variavel/string
	
	printf("Digite o CPF a ser cadastrado\n");//coleta de informacoes do Usuario
	printf("CPF: ");
	scanf("%s", cpf);//(%S) serve para salvar uma string
	
	strcpy(arquivo, cpf);//Responsavel por criar os valores das string
	
	FILE *file;//Cria arquivo 
	file = fopen(arquivo, "w");//Cria o arquivo
	fprintf(file,cpf);//Salva o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado\n");//coleta de informacoes do Usuario
	printf("Nome: ");
	scanf("%s", nome);//(%S) serve para salvar uma string
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobre nome a ser Cadastrado\n");//coleta de informacoes do Usuario
	printf("Sobre Nome: ");
	scanf("%s",sobrenome);//(%S) serve para salvar uma string
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado\n");//coleta de informacoes do Usuario
	printf("Cargo: ");
	scanf("%s",cargo);//(%S) serve para salvar uma string
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar!\n");//coleta de informacoes do Usuario
	printf("CPF: ");
	scanf("%s",cpf);//(%S) serve para salvar uma string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel indentificar o usuario, porfavor tente novamenete\n");
	}
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nInformacoes do ususario!\n");
		printf("%s", conteudo);//(%S) serve para salvar uma string
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	
	printf("Digite o CPF do ususario a ser deletado!\n");//coleta de informacoes do Usuario
	printf("CPF: ");
	scanf("%s",cpf);//(%S) serve para salvar uma string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario nao cadastrado no sistema!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0;//Definindo Variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	
	setlocale(LC_ALL, "Portuguese");//Definindo Linguagem
	
	printf("### cartorio da EBAC ###\n\n");//Inicio do Menu
	printf("escolha opcao desejada no menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consutar nomes\n");
	printf("\t3 - deletar nomes\n\n");//Fim do Menu
	printf("\t4 - sair do sistema\n");
	printf("Opccao: ");
	
	scanf("%d",&opcao);//Armazenando escolha do usuario
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
			registrar();//chamadas de funçoes
		break;
		
		case 2:
			consultar();
		break;
		
		case 3:
			deletar();
		break;
		
		case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
					
		default:
			printf("Opção inválida. Por favor, escolha uma opção entre 1 e 3.\n");
		system("pause");
		break;
	}
}
}	
