#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //bibliotec de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocação de texto por região "ela entende os acentos"
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
		
		strcpy(arquivo, cpf);          			// copia uma string na outra, as duas viram a mesma informação colocada
		
		FILE *file;       			  			// criando o arquivo // FILE em maiusculo é uma função que existe no sistema que acessa arquivos, ele vai criar o arquivo *file em minusculo(o asterisco faz parte do comando de nomeção)
		file = fopen(arquivo, "w"); 		    //criando o arquivo  //(o arquivo file se comportará da seguinte maneira, será priemiramente aberto com o comando "fopen"(comando que abre arquivos) o arquivo aberto será nomeado com o char arquivo que é o cpf da pessoa| "w" indica que é um arquivo novo não existente ainda, que será registrado agora no sistema
		fprintf(file,cpf);         				// frpintf adiciona dados no arquivo (ele vao salvar no arquivo o valor da variavel cpf)
		fclose(file);                                // fecha o arquivo finalizando o processo
		
		file = fopen(arquivo, "a"); 			// abrir o file do char "arquivo" (o "a" representa atualizar um arquivo já existente)
		fprintf(file, ",");      				 // aqui estamos colancando dentro do arquivo uma virgula para separar as informações
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
		char conteudo[100];    // char é uma variável n esquecer
		
		printf("digite o cpf a ser consultado: \n");
		scanf("%s" ,cpf);
		
		FILE *file;
		file = fopen(cpf, "r");     // r é só para ler a informação // alinha diz (abra o arquivo e leia a variavel cpf)
		
		if(file== NULL){
			
			printf("Não foi possivel localizar o arquivo \n"); // se ele não ler nada na variavel cpf essa mensagem irá retornar
		}
		
		while(fgets(conteudo, 200, file) !=NULL)          //fgets comando que busca os arquivos // enquanto tiver conteudo ele vai armazenar informações, quando ele terminar de buscar as infos de file e armazenar ou seja ele ser igual a "NULL"(pois não existem mais infos para buscar)
		{
			printf("\n Essas são as informações do usuário:"); // ele irá apresentar esses dois printfs
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
	
	    printf("O usuário não existe!\n");
	
	    system("pause");
	
	  } 
	
	else 
	
	  {
	
	    fclose(file); // Fecha o arquivo, pois ele existe
	
	    remove(cpf); // Agora você pode remover o arquivo
	
	    printf("Usuário deletado!\n");
	
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
		setlocale(LC_ALL, "Portuguese");//__________________ fazer a biblioteca de alocação de texto saber que estamos no brasil
    
		printf("### Cartório da EBAC ###\n\n");//__________Inicio do Menu
    	printf("Escolha a opção desejada do menu\n\n");
    	printf("\t1 - Registrar Nomes \n");	//____________ o \t da um espaçamento no texto
    	printf("\t2 - Consultar Nomes \n");   
    	printf("\t3 - Deletar Nomes \n\n");//_____________Fim do Menu
   	    printf("Escolha uma opção:");
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
    			printf("Essa Escolha não é Válida\n");
				system("pause");
				break;
		}
     }
}

