#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cabecalho (void) { 
       printf("************************\n");
       printf("*     BEM VINDO(A)     *\n");
       printf("************************\n");
       return;
    }

int main() {

        cabecalho();

        char nome[5][50], email[5][50], matricula[5][50], tell[5][50];
        int choice;
        int temp;
        int i;
        
        FILE *arq;
       
        do {

                printf("***********************\n");   
                printf("*  1 - Cadastrar      *\n");
                printf("*  2 - Colaboradores  *\n");
                printf("***********************\n");
                printf("--> ");
                scanf("%d", &choice);
                
                
                        switch (choice) {
                                case 1:

                                printf("\nQuantos cadastros serao feitos?\n");
                                printf("--> ");
                                scanf("%d", &temp);

                                for(i = 1; i <= temp; i++) { 

                                        printf("\nCadastro: %d\n", i); 
                                        printf("\nNome: ");
                                        fflush(stdin);
                                        gets(nome[i]);
                                                
                                        printf("E-mail: ");
                                        fflush(stdin);
                                        gets(email[i]);
                                                
                                        printf("Matricula: ");
                                        fflush(stdin);
                                        gets(matricula[i]);
                                                
                                        printf("Telefone: ");
                                        fflush(stdin);
                                        gets(tell[i]);
                                }


                                arq = fopen("celpe_colaboradores.JSON", "r");
                                

                                if(arq == NULL) {
                                       
                                        printf("\nArquivo Criado com sucesso!\n");        
                                
                                }

                                fclose(arq);

                                arq = fopen("celpe_colaboradores.JSON", "a");

                                

                                for(i = 1; i <= temp; i++) {
                                        fprintf(arq,"{\n");
                                        fprintf(arq,"'nome' : '%s', ",nome[i]);
                                        fprintf(arq,"'email' : '%s', ",email[i]);
                                        fprintf(arq,"'matricula' : '%s', ",matricula[i]);
                                        fprintf(arq,"'telefone' : '%s'",tell[i]);
                                        fprintf(arq,"\n}\n");
                                }
                                fclose(arq);

                                break;

                                case 2:
                                printf("Colaboradores cadastros:\n\n");

                                        for(i = 1; i <= temp; i++) {
                                        
                                                printf("\nID:%d\n", i);
                                                printf("Nome: %s\n",nome[i]);
                                                printf("E-mail: %s\n",email[i]);
                                                printf("Matricula: %s\n",matricula[i]);
                                                printf("Telefone: %s\n",tell[i]);
                                        }
                                getchar();
                                break;

                                default:
                                printf("Opcaoo Invalida\n");
                                break;
                                }
                                getchar();

        } while (temp > 0);
                
        system("pause");
                
        return 0;
}       
