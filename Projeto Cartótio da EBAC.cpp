#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //bibliotec de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o "ela entende os acentos"
#include <string.h> // biblioteca que armazena as strings

int registro()
	{
		setlocale(LC_ALL, "Portuguese");
		char arquivo[40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		
		printf("Digite o Cpf a ser Cadastrado: ");
		scanf("%s" , cpf);
		
		strcpy(arquivo, cpf);          			// copia uma string na outra, as duas viram a mesma informa��o colocada
		
		FILE *file;       			  			// criando o arquivo // FILE em maiusculo � uma fun��o que existe no sistema que acessa arquivos, ele vai criar o arquivo *file em minusculo(o asterisco faz parte do comando de nome��o)
		file = fopen(arquivo, "w"); 		    //criando o arquivo  //(o arquivo file se comportar� da seguinte maneira, ser� priemiramente aberto com o comando "fopen"(comando que abre arquivos) o arquivo aberto ser� nomeado com o char arquivo que � o cpf da pessoa| "w" indica que � um arquivo novo n�o existente ainda, que ser� registrado agora no sistema
		fprintf(file,cpf);         				// frpintf adiciona dados no arquivo (ele vao salvar no arquivo o valor da variavel cpf)
		fclose(file);                                // fecha o arquivo finalizando o processo
		
		file = fopen(arquivo, "a"); 			// abrir o file do char "arquivo" (o "a" representa atualizar um arquivo j� existente)
		fprintf(file, ",");      				 // aqui estamos colancando dentro do arquivo uma virgula para separar as informa��es
		fclose(file);	
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s" , nome);
		
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s" , sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		
		printf("Digite o Cargo a ser cadastrado: ");
		scanf("%s" ,cargo);
		
		file =fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
	}
int consulta()
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[100];    // char � uma vari�vel n esquecer
		
		printf("digite o cpf a ser consultado: \n");
		scanf("%s" ,cpf);
		
		FILE *file;
		file = fopen(cpf, "r");     // r � s� para ler a informa��o // alinha diz (abra o arquivo e leia a variavel cpf)
		
		if(file== NULL){
			
			printf("N�o foi possivel localizar o arquivo \n"); // se ele n�o ler nada na variavel cpf essa mensagem ir� retornar
		}
		
		while(fgets(conteudo, 200, file) !=NULL)          //fgets comando que busca os arquivos // enquanto tiver conteudo ele vai armazenar informa��es, quando ele terminar de buscar as infos de file e armazenar ou seja ele ser igual a "NULL"(pois n�o existem mais infos para buscar)
		{
			printf("\n Essas s�o as informa��es do usu�rio:"); // ele ir� apresentar esses dois printfs
			printf("\n %s \n", conteudo);                           // nos indicando os dados buscados anteriormente no While
		} 
		 system("pause");
		 fclose(file);
		
	}
int deletar()	
	
	{
	
	char cpf[40];
	
	setlocale(LC_ALL,"portuguese");
	
	
	printf("Digite o CPF a ser deletado: ");
	
	scanf("%s",cpf);
	
	
	FILE *file;
	
	  file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura
	
	if (file == NULL) 
	
	  {
	
	    printf("O usu�rio n�o existe!\n");
	
	    system("pause");
	
	  } 
	
	else 
	
	  {
	
	    fclose(file); // Fecha o arquivo, pois ele existe
	
	    remove(cpf); // Agora voc� pode remover o arquivo
	
	    printf("Usu�rio deletado!\n");
	
	    system("pause");
	
	  }
	
	}
int main ()
{
	int opcao=0;   // variavel pra opcao do menu
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese");//__________________ fazer a biblioteca de aloca��o de texto saber que estamos no brasil
    
		printf("### Cart�rio da EBAC ###\n\n");//__________Inicio do Menu
    	printf("Escolha a op��o desejada do menu\n\n");
    	printf("\t1 - Registrar Nomes \n");	//____________ o \t da um espa�amento no texto
    	printf("\t2 - Consultar Nomes \n");   
    	printf("\t3 - Deletar Nomes \n\n");//_____________Fim do Menu
   	    printf("Escolha uma op��o:");
    	scanf("%d",  &opcao);
    
    	system("cls"); //________________________________ o sistema limpa a tela
    	
    	switch(opcao)
		{
    		case 1:
    			registro();
    			break;
    		case 2:
    			consulta();
				break;
			case 3:
				deletar();
    			break;
			default:
    			printf("Essa Escolha n�o � V�lida\n");
				system("pause");
				break;
		}
     }
}

