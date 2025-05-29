#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o "ela entende os acentos"
#include <string.h> // biblioteca que armazena as strings

int registro()
{
    setlocale(LC_ALL, "Portuguese");
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // copia uma string na outra, as duas viram a mesma informa��o colocada

    FILE *file; // criando o arquivo // FILE em mai�sculo � uma fun��o que existe no sistema que acessa arquivos
    file = fopen(arquivo, "w"); // criando o arquivo  // "w" indica que � um arquivo novo n�o existente ainda
    fprintf(file, cpf); // fprintf adiciona dados no arquivo
    fclose(file); // fecha o arquivo finalizando o processo

    file = fopen(arquivo, "a"); // abrir o arquivo para atualizar
    fprintf(file, ","); // adicionando uma v�rgula para separar as informa��es
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: \n");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); // r � s� para leitura

    if (file == NULL)
    {
        printf("N�o foi poss�vel localizar o arquivo \n");
    }
    else
    {
        while (fgets(conteudo, 100, file) != NULL) // busca os arquivos
        {
            printf("\nEssas s�o as informa��es do usu�rio:");
            printf("\n%s\n", conteudo); // apresenta os dados buscados
        }
        fclose(file);
    }
    system("pause");
}

int deletar()
{
    char cpf[40];
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

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
        remove(cpf); // Agora pode remover o arquivo
        printf("Usu�rio deletado!\n");
        system("pause");
    }
}

int main()
{
    int opcao = 0;
    int laco = 1;
    char senhadigitada[10]="a";
    
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de Administrador!\n\n Digite a sua senha: ");
    scanf("%s",senhadigitada);
    
    if (strcmp(senhadigitada, "admin") == 0)
    {
	


    	for (laco = 1; laco == 1;)
    	{
       		system("cls");
       		setlocale(LC_ALL, "Portuguese");

       		printf("### Cart�rio da EBAC ###\n\n");
       		printf("Escolha a op��o desejada do menu\n\n");
       		printf("\t1 - Registrar Nomes \n");
        	printf("\t2 - Consultar Nomes \n");
       		printf("\t3 - Deletar Nomes \n\n");
        	printf("\t4 - Sair do Sistema \n\n");
        	printf("Escolha uma op��o: ");
       	 	
				scanf("%d", &opcao);

       		 	system("cls");

       			 switch (opcao)
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
        			
					case 4:
             		printf("\n Obrigado por utilizar o sistema!\n");
             		return 0; 
             		break;
        			
					default:
            		printf("Essa escolha n�o � v�lida\n");
            		system("pause");
            		break;
        		}
       	}	
    }
    
    else
         printf("Senha incorreta");
}

