#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estrutura.h"



struct lista *inicia_dados(char *nome, char *email, int tell, int matricula, char *setor) 
{

        struct lista *novo;

        novo = (struct lista *)malloc(sizeof(struct lista));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->email = email;
        novo->tell = tell;
        novo->matricula = matricula;
        novo->setor = setor;
        novo->next = NULL;

        return novo;
}

struct lista *insere_dados(struct lista *dados, char *nome, char *email, int tell, int matricula, char *setor) 
{

        struct lista *novo;

        novo = (struct lista *)malloc(sizeof(struct lista));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->email = email;
        novo->tell = tell;
        novo->matricula = matricula;
        novo->setor = setor;
        novo->next = dados;

        return novo;
}

void exibe_dados(struct lista *dados) 
{

        fprintf(stdout, "Cadastrados:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->next) {
                fprintf(stdout, "Nome: %s\n", dados->nome);
                fprintf(stdout, "Email: %s\n", dados->email);
                fprintf(stdout, "Telefone: %d\n", dados->tell);
                fprintf(stdout, "Matricula: %d\n", dados->matricula);
                fprintf(stdout, "Setor: %s\n", dados->setor);
                fprintf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getchar();
}

void busca_dados(struct lista *dados, char *key) 
{

        int find = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->next) {
                if (strcmp(key, dados->nome) == 0) {

                        fprintf(stdout, "------------------------\n");
                        fprintf(stdout, "Nome: %s\n", dados->nome);
                        fprintf(stdout, "Email: %s\n", dados->email);
                        fprintf(stdout, "Telefone: %d\n", dados->tell);
                        fprintf(stdout, "Matricula: %d\n", dados->matricula);
                        fprintf(stdout, "Setor: %s\n", dados->setor);
                        fprintf(stdout, "------------------------\n");
                        find++;
                }
        }

        if (find == 0)
                fprintf(stdout, "Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                fprintf(stdout, "Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", find);

        sleep(1);
        getchar();
}

struct lista *deleta_dados(struct lista *dados)
{

        struct lista *novo;

        novo = dados->next;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\n");
        sleep(1);

        return novo;
}


int checa_vazio(struct lista *dados) 
{


        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\n");
                sleep(1);
                return 1;
        } else{
                return 0;
        }
}

void insere(void) 
{

        char *nome, *email, *setor, temp[40], temp2[20];
        int matricula, tell;

        nome = malloc(BUFFER * sizeof (char));

        fprintf(stdout, "\n\nNome: \n----> ");
        scanf("%s", nome);
        fprintf(stdout, "\n");

        fprintf(stdout, "Email: \n----> ");
        scanf("%s", temp);
        strcpy(email, temp);
        fprintf(stdout, "\n");
        
        fprintf(stdout, "Telefone: \n----> ");
        scanf("%d", &tell);
        fprintf(stdout, "\n");
        
        fprintf(stdout, "Matricula: \n----> ");
        scanf("%d", &matricula);
        fprintf(stdout, "\n");
        
        fprintf(stdout, "Setor: \n----> ");
        scanf("%s", temp2);
        strcpy(setor, temp2);
        fprintf(stdout, "\n");

        if (principal == NULL)
                principal = inicia_dados(nome, email, tell, matricula, setor);
        else
                principal = insere_dados(principal, nome, email, tell, matricula, setor);            
}

void busca(void) 
{

        char *key;

        if (!checa_vazio(principal)) {

                key = (char *)malloc(BUFFER);

                fprintf(stdout, "Digite o nome para buscar:\n--> ");
                scanf("%s", key);

                busca_dados(principal, key);
                getchar();
        }
}

void exibe(void) 
{

        if (!checa_vazio(principal))
            exibe_dados(principal);

}


void deleta(void) 
{

        if (!checa_vazio(principal))
        principal = deleta_dados(principal);
}


void cabecalho(void)
{
  printf("*******************************\n");   
  printf("*          BEM VINDO          *\n");
  printf("*******************************\n");   

  return;
}
