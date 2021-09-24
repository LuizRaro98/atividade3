//https://github.com/LuizRaro98/atividade3/blob/main/alocdinamica.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {

	char nome[30];
	int ano;
	float gasto;


} PESSOA;

void preencher (PESSOA *pPessoa)
{

            printf("Nome: ");
            scanf("%30[^\n]%*c", pPessoa->nome);
            printf("Ano de nascimento: ");
            scanf("%d%*c", &pPessoa->ano);
            printf("Gastos realizados: ");
        	scanf("%f%*c", &pPessoa->gasto);


}


int main (void)



{
            char nomecomp [30];
            int contador = 0;
            int montante = 10;
            PESSOA aux;
			PESSOA *pPessoa=NULL;
            pPessoa = (PESSOA *) calloc(montante, montante * sizeof(PESSOA));
            setlocale(LC_ALL, "Portuguese");
            printf("-------------------CADASTRO DE CLIENTES------------------\n");
	        printf("----------------------------------------------------------\n");
            int opcao = 0;
            while(opcao != 7){
             if (contador == montante)
            {
                montante = montante + 10;
            	pPessoa = (PESSOA *) realloc(pPessoa, montante * sizeof(PESSOA));
			}
	        printf("\n[ 1 ] Cadastrar novo cliente");
            printf("\n[ 2 ] Remover cliente");
            printf("\n[ 3 ] Atualizar gastos do cliente");
            printf("\n[ 4 ] Virar o mês (Zerar compras)");
            printf("\n[ 5 ] Listar clientes (por melhor comprador)");
            printf("\n[ 6 ] Ver gastos de cliente");
            printf("\n[ 7 ] Sair\n");
            printf("\nOpção desejada: ");
            scanf("%d%*c", &opcao);
            system ("cls");

                switch(opcao)
    {
        case 1:


			preencher(&pPessoa[contador]);

			contador++; system("cls"); break;

        case 2:


           printf("Nome do cliente que deseja remover: ");
            	scanf("%30[^\n]%*c", &nomecomp);
            for (int i = 0; i < contador; i++){
            	int retorno;
            	char nome [30];
            	strcpy (nome, pPessoa[i].nome);
            	retorno = strcmp (nomecomp, nome);
            	if (retorno == 0) {
            	   for (i; i < contador-1; i++)
            		{
            			pPessoa[i] = pPessoa[i+1];
					}
				}

			}
            contador--;
             system("cls"); break;

        case 3:





        		printf("Nome do cliente a ser atualizado montante: ");
        		scanf("%30[^\n]%*c", &nomecomp);
        		int retorno;
        		for (int i = 0; i < contador; i++){
            	char nome [30];
            	strcpy (nome, pPessoa[i].nome);
            	retorno = strcmp (nomecomp, nome);
        		if (retorno == 0) {
            		{
            		    printf("Montante total a ser atualizado (OBS: não será somado com o que já tem.): ");

            			scanf("%f%*c", &pPessoa[i].gasto);
					}
				}
			}
            system ("cls");

            break;

        case 4:

        	 for (int i = 0; i < contador; i++){

            	  pPessoa[i].gasto = 0;
				}


        case 5:

             for (int i = 0; i < contador; i++){
            	  for (int j = i + 1; j < contador; j++) {

                     if(pPessoa[i].gasto < pPessoa[j].gasto) {

                     	aux = pPessoa[i]; pPessoa[i] = pPessoa[j];   pPessoa[j] = aux;
					 }

				}  }
				 for (int i = 0; i < contador; i++)

           printf("(%d) Nome: %s - Montante: %.2f\n", i+1, pPessoa[i].nome, pPessoa[i].gasto);
            break;

        case 6:

           printf("Nome do cliente: ");
            	scanf("%30[^\n]%*c", &nomecomp);
            for (int i = 0; i < contador; i++){
            	int retorno;
            	char nome [30];
            	strcpy (nome, pPessoa[i].nome);
            	retorno = strcmp (nomecomp, nome);
            	if (retorno == 0) {

            		{
            			printf("Nome: %s - Montante: %.2f\n", pPessoa[i].nome, pPessoa[i].gasto);
					}
				}

			}

            break;
        case 7:
            printf("\nVolte sempre!\n");
            break;
    }}


            	return 0;
	}

