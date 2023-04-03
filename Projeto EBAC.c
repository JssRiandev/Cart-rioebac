#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include<string.h> // biblioteca respons�vel pelas strings

int registro() // Fun��o respons�vel por cadastrar o usu�rio no sistema
{
	// In�cio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das vari�veis/strings
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF a ser cadastrado "); // Respons�vel por coletar o cpf do usu�rio
	scanf("%s", cpf);  //"%s" � utilizado para salvar uma string. Salvando o cpf digitado na vari�vel
	
	strcpy(arquivo, cpf); //"strcpy" respons�vel por copiar. O valor de arquivo sempre ser� igual ao cpf
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); //"w" significa escrever/criar arquivo;
	fprintf(file, "CPF:"); //Imprimindo tudo o que est� entre �spas no arquivo
	fprintf(file, cpf); //Imprimindo e guardando o cpf digitado anteriormente no arquivo
	fclose(file); //significa fechar o arquivo;

	printf("Digite o nome a ser cadastrado: "); //Respons�vel por coletar o nome do usu�rio
	scanf("%s",nome); //Respons�vel por salvar o nome digitado na vari�vel.
	
	file = fopen(arquivo,"a"); //Abrindo e atualizando o arquivo
	fprintf(file, ", Nome:"); //imprimindo tudo que est� entre �spas no arquivo
	fprintf(file,nome); //Imprimindo o valor da vari�vel no arquivo;
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usu�rio
	scanf("%s",sobrenome); //Salvando o sobrenome em uma vari�vel
	
	file = fopen(arquivo, "a"); //Abrindo e atualizando o arquivo
	fprintf(file, ", Sobrenome:"); //Imprimindo tudo que est� entre �spas no arquivo
	fprintf(file,sobrenome); //imprimindo o valor da vari�vel no arquivo
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usu�rio
	scanf("%s", cargo); //Salvando o sobrenome do usu�rio em uma vari�vel
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizando
	fprintf(file, ", Cargo:"); //Imprimindo tudo que est� entre �spas no arquivo
	fprintf(file, cargo); //Imprimindo o valor da vari�vel no arquivo 
	fclose(file); //Fechando o arquivo
	
	system("pause");
	
}

int consulta()
{
	//In�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/strings
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF a ser consultado: "); //Coletando o cpf do usu�rio para fazer a consulta
	scanf("%s", cpf); //Salvando o cpf digitado em uma vari�vel
	
	FILE *file; // Abrindo o arquivo
	file = fopen(cpf,"r"); // "r" significa ler o arquivo. Lendo a vari�vel do cpf para ver se ela est� no arquivo
	
	if(file == NULL) //Condi��o para caso o cpf n�o esteja cadastrado
	{
		printf( "CPF n�o localizado, usu�rio n�o cadastrado\n\n"); //Mensagem que ser� mostrada na tela caso o cpf n�o seja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"fgets" significa buscar dentro do arquivo. Buscando se o cpf digitado est� no arquivo e salvando tudo que est� no arquivo na vari�vel conteudo.
	{
		printf("\nEssas s�o as informa��es do usu�rio - "); //Mostrando mensagem entre �spas para o usu�rio
		printf("%s", conteudo); //Mostrando todas as informa��es do arquivo para o usu�rio
		printf("\n\n");
		
	}
	system("pause");
	
	fclose(file);// fechando o arquivo

}

int deletar()
{
	char cpf[40]; //Criando as vari�veis
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Respons�vel por coletar o cpf do usu�rio
	scanf("%s,", cpf); //Salvando o cpf do usu�rio em uma vari�vel
	
	FILE *file; //Abrindo o arquivo
	file = fopen(cpf,"r"); //Abrindo o arquivo e lendo se a vari�vel se encontra nele
	fclose(file); //Fechando o arquivo
	
	if(file == NULL) //Condi��o para caso o cpf n�o esteja no sistema
	{
		printf("O usu�rio n�o se encontra no sistema\n"); //Mensagem entre �spas sendo mostrada para o usu�rio
		system("pause");
	}
	
	else // Condi��o para caso o cpf esteja no sistema
	{	
		remove(cpf); //Comando para remover o cpf do sistema
		printf("\nO usu�rio foi deletado do sistema com sucesso\n"); //Mostrando a mensagem entre �spas para o usu�rio
		system("pause");
	}
		        	
}

int main() //� a fun��o principal do programa. Tudo que est� dentro dela ser� executado primeiro.
{
	int opcao=0; //Definindo vari�veis;
	int x=1; //Vari�vel do la�o 
	
	for(x=1;x=1;) //La�o para sempre voltar ao menu inicial 
  {
  	system("cls"); //Limpando a tela ao escolher op��o
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Cart�rio de alunos: EBAC\n\n"); //In�cio do Menu;
	printf("Voc� deseja:\n\n"); //Comunicando as op��es do usu�rio;
	printf("\t1-Registrar nomes\n"); //Primeira op��o do usu�rio;
	printf("\t2-Consultar nomes\n"); //Segunda op��o do usu�rio;
	printf("\t3-Deletar nomes\n\n\n"); //Terceira op��o do usu�rio;
	printf("Sua op��o  "); //Local para o usu�rio digitar a op��o
	
	scanf("%d",&opcao); //Aguardando a decis�o do usu�rio;
	
	system("cls"); //Limpando a tela ap�s a decis�o ser feita;
	
	switch(opcao) //Identificando aa deci��o do usu�rio
	{
		case 1: //Caso o usu�rio escolha a op��o 1, o programa ir� ler/executar a fun��o registro 
		registro();
		break;
		
		case 2: //Caso o usu�rio escolha a op��o 2, o programa ir� ler/executar a fun��o consulta
		consulta();
		break; 
		
		case 3: //Caso o usu�rio escolha a op��o 3, o programa ir� ler/executar a fun��o deletar
		deletar();
		break;
		
		default: //Caso o usu�rio n�o escolha nenhuma op��o, a mensagem abaixo ir� aparecer para ele;
		printf("Voc� escolheu uma op��o inexistente\n");
		system("pause"); //Continua mostrando a op��o ao usu�rio at� ele clicar em uma tecla e voltar ao menu inicial;
		break;
		
	} //Op��o do usu�rio j� identificada e mostrada na tela
  }
}
