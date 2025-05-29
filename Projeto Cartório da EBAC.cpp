#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocação de texto por região "ela entende os acentos"
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

    strcpy(arquivo, cpf); // copia uma string na outra, as duas viram a mesma informação colocada

    FILE *file; // criando o arquivo // FILE em maiúsculo é uma função que existe no sistema que acessa arquivos
    file = fopen(arquivo, "w"); // criando o arquivo  // "w" indica que é um arquivo novo não existente ainda
    fprintf(file, cpf); // fprintf adiciona dados no arquivo
    fclose(file); // fecha o arquivo finalizando o processo

    file = fopen(arquivo, "a"); // abrir o arquivo para atualizar
    fprintf(file, ","); // adicionando uma vírgula para separar as informações
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
    file = fopen(cpf, "r"); // r é só para leitura

    if (file == NULL)
    {
        printf("Não foi possível localizar o arquivo \n");
    }
    else
    {
        while (fgets(conteudo, 100, file) != NULL) // busca os arquivos
        {
            printf("\nEssas são as informações do usuário:");
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
        printf("O usuário não existe!\n");
        system("pause");
    }
    else
    {
        fclose(file); // Fecha o arquivo, pois ele existe
        remove(cpf); // Agora pode remover o arquivo
        printf("Usuário deletado!\n");
        system("pause");
    }
}

int main()
{
    int opcao = 0;
    int laco = 1;
    char senhadigitada[10]="a";
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de Administrador!\n\n Digite a sua senha: ");
    scanf("%s",senhadigitada);
    
    if (strcmp(senhadigitada, "admin") == 0)
    {
	


    	for (laco = 1; laco == 1;)
    	{
       		system("cls");
       		setlocale(LC_ALL, "Portuguese");

       		printf("### Cartório da EBAC ###\n\n");
       		printf("Escolha a opção desejada do menu\n\n");
       		printf("\t1 - Registrar Nomes \n");
        	printf("\t2 - Consultar Nomes \n");
       		printf("\t3 - Deletar Nomes \n\n");
        	printf("\t4 - Sair do Sistema \n\n");
        	printf("Escolha uma opção: ");
       	 	
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
            		printf("Essa escolha não é válida\n");
            		system("pause");
            		break;
        		}
       	}	
    }
    
    else
         printf("Senha incorreta");
}

