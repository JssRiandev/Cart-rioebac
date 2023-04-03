#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include<string.h> // biblioteca responsável pelas strings

int registro() // Função responsável por cadastrar o usuário no sistema
{
	// Início da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variáveis/strings
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF a ser cadastrado "); // Responsável por coletar o cpf do usuário
	scanf("%s", cpf);  //"%s" é utilizado para salvar uma string. Salvando o cpf digitado na variável
	
	strcpy(arquivo, cpf); //"strcpy" responsável por copiar. O valor de arquivo sempre será igual ao cpf
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); //"w" significa escrever/criar arquivo;
	fprintf(file, "CPF:"); //Imprimindo tudo o que está entre áspas no arquivo
	fprintf(file, cpf); //Imprimindo e guardando o cpf digitado anteriormente no arquivo
	fclose(file); //significa fechar o arquivo;

	printf("Digite o nome a ser cadastrado: "); //Responsável por coletar o nome do usuário
	scanf("%s",nome); //Responsável por salvar o nome digitado na variável.
	
	file = fopen(arquivo,"a"); //Abrindo e atualizando o arquivo
	fprintf(file, ", Nome:"); //imprimindo tudo que está entre áspas no arquivo
	fprintf(file,nome); //Imprimindo o valor da variável no arquivo;
	fclose(file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando o sobrenome do usuário
	scanf("%s",sobrenome); //Salvando o sobrenome em uma variável
	
	file = fopen(arquivo, "a"); //Abrindo e atualizando o arquivo
	fprintf(file, ", Sobrenome:"); //Imprimindo tudo que está entre áspas no arquivo
	fprintf(file,sobrenome); //imprimindo o valor da variável no arquivo
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando o cargo do usuário
	scanf("%s", cargo); //Salvando o sobrenome do usuário em uma variável
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizando
	fprintf(file, ", Cargo:"); //Imprimindo tudo que está entre áspas no arquivo
	fprintf(file, cargo); //Imprimindo o valor da variável no arquivo 
	fclose(file); //Fechando o arquivo
	
	system("pause");
	
}

int consulta()
{
	//Início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Final da criação de variáveis/strings
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF a ser consultado: "); //Coletando o cpf do usuário para fazer a consulta
	scanf("%s", cpf); //Salvando o cpf digitado em uma variável
	
	FILE *file; // Abrindo o arquivo
	file = fopen(cpf,"r"); // "r" significa ler o arquivo. Lendo a variável do cpf para ver se ela está no arquivo
	
	if(file == NULL) //Condição para caso o cpf não esteja cadastrado
	{
		printf( "CPF não localizado, usuário não cadastrado\n\n"); //Mensagem que será mostrada na tela caso o cpf não seja cadastrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //"fgets" significa buscar dentro do arquivo. Buscando se o cpf digitado está no arquivo e salvando tudo que está no arquivo na variável conteudo.
	{
		printf("\nEssas são as informações do usuário - "); //Mostrando mensagem entre áspas para o usuário
		printf("%s", conteudo); //Mostrando todas as informações do arquivo para o usuário
		printf("\n\n");
		
	}
	system("pause");
	
	fclose(file);// fechando o arquivo

}

int deletar()
{
	char cpf[40]; //Criando as variáveis
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Digite o CPF do usuário a ser deletado: "); // Responsável por coletar o cpf do usuário
	scanf("%s,", cpf); //Salvando o cpf do usuário em uma variável
	
	FILE *file; //Abrindo o arquivo
	file = fopen(cpf,"r"); //Abrindo o arquivo e lendo se a variável se encontra nele
	fclose(file); //Fechando o arquivo
	
	if(file == NULL) //Condição para caso o cpf não esteja no sistema
	{
		printf("O usuário não se encontra no sistema\n"); //Mensagem entre áspas sendo mostrada para o usuário
		system("pause");
	}
	
	else // Condição para caso o cpf esteja no sistema
	{	
		remove(cpf); //Comando para remover o cpf do sistema
		printf("\nO usuário foi deletado do sistema com sucesso\n"); //Mostrando a mensagem entre áspas para o usuário
		system("pause");
	}
		        	
}

int main() //É a função principal do programa. Tudo que está dentro dela será executado primeiro.
{
	int opcao=0; //Definindo variáveis;
	int x=1; //Variável do laço 
	
	for(x=1;x=1;) //Laço para sempre voltar ao menu inicial 
  {
  	system("cls"); //Limpando a tela ao escolher opção
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
	printf("Cartório de alunos: EBAC\n\n"); //Início do Menu;
	printf("Você deseja:\n\n"); //Comunicando as opções do usuário;
	printf("\t1-Registrar nomes\n"); //Primeira opção do usuário;
	printf("\t2-Consultar nomes\n"); //Segunda opção do usuário;
	printf("\t3-Deletar nomes\n\n\n"); //Terceira opção do usuário;
	printf("Sua opção  "); //Local para o usuário digitar a opção
	
	scanf("%d",&opcao); //Aguardando a decisão do usuário;
	
	system("cls"); //Limpando a tela após a decisão ser feita;
	
	switch(opcao) //Identificando aa decição do usuário
	{
		case 1: //Caso o usuário escolha a opção 1, o programa irá ler/executar a função registro 
		registro();
		break;
		
		case 2: //Caso o usuário escolha a opção 2, o programa irá ler/executar a função consulta
		consulta();
		break; 
		
		case 3: //Caso o usuário escolha a opção 3, o programa irá ler/executar a função deletar
		deletar();
		break;
		
		default: //Caso o usuário não escolha nenhuma opção, a mensagem abaixo irá aparecer para ele;
		printf("Você escolheu uma opção inexistente\n");
		system("pause"); //Continua mostrando a opção ao usuário até ele clicar em uma tecla e voltar ao menu inicial;
		break;
		
	} //Opção do usuário já identificada e mostrada na tela
  }
}
