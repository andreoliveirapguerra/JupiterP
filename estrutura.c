#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estrutura.h"

// #ifndef _PRINCIPAL_NULL
// #define _PRINCIPAL_NULL
// void principal_null(void)
// {
//         principal->email = NULL;
// }
// #endif


#ifndef _ESTRUTURA_C
#define _ESTRUTURA_C

#ifndef _STRUCT_LISTA
#define _STRUCT_LISTA
struct lista{
	char *(nome);
	char *email;
	int tell;
	int matricula;
	char *setor;
	struct lista *next, *prev;
};
#endif // LISTA

#ifndef _STRUCT_CHAINED
#define _STRUCT_CHAINED
struct chained_list {
        char *name;
        char *email;
        int tell;
        int matricula;
        char *setor;
        struct chained_list *prev, *next;
};
#endif

#ifndef _LIST
#define _LIST
struct list {
        struct lista *first, *last;
};

#endif


// #ifdef _INSERT_AT
// void insert_at(char name[], char email[], int tell, int mat, char setor[]) {

//         struct chained_list *new ;
//         new = malloc (sizeof (struct chained_list));
 
//         if (!new) {
//                 if (!new) {
//                         printf("there was an error while attempting to alloc mem\n");
//                         printf("memory full\n");
//                         exit(-1);
//                 }
//         }
//         new->next = NULL;
//         new->name = name;
//         new->email = email;
//         new->matricula = mat;
//         new->setor = setor;


//         if (!linked_list->first) {
                
//                 linked_list->first = new;
//                 linked_list->last = new;
//         }
//         else {
//                 new->prev = linked_list->last;
//                 new->next = NULL;
//         }

// }
// #endif


#ifdef _INICIA_DADOS
// #define _INICIA_DADOS
struct lista *inicia_dados(char *nome, char *email, int tell, int matricula, char *setor) 
{

        struct lista *novo;
        printf("tamanho = %ld\n",strlen(nome));

        novo = (struct lista *)malloc(sizeof(struct lista));
        if (!novo) {

                // novo = (struct lista *) malloc (sizeof (struct lista));

                if (!novo) {
                        fprintf(stderr,"Not enougth memory \n");
                }
        }
        // novo->nome =  malloc(40 * sizeof(char));
        printf("estrutura.c setor = %s\n",setor);
        
        // printf("nome: %s\nemail: %s\ntelefone: %d\nmatricula: %d\nsetor: %s", nome, email, tell, matricula, setor);

        
        
        

        novo->setor = malloc(40*sizeof(char));
        // novo->email = malloc (40 * sizeof(char));

        if (!novo->nome || novo->setor) {

                novo->nome =(char *)malloc(40*sizeof(char ));

                if (!novo->nome) {
                        fprintf(stderr,"Not enought memory for novo->nome\n");
                }
                if (!novo->setor) {
                        fprintf(stderr,"Not enought memory for novo->setor\n");
                }
        }

        // strncpy(novo->nome, nome, strlen(nome)+1);
        novo->email = email;
        novo->tell = tell;
        novo->matricula = matricula;
        novo->setor = setor;
        novo->next = NULL;
        novo->prev = NULL;
        linked_list->first = novo;
        // principal = linked_list->first;
        linked_list->last = novo;

        // return novo;
}
#endif // inicia_dados

#ifdef _FWRITER
void write_file(FILE *fp, char *content)
{
        fp = fopen("object.json", "a");
        if (!fp) exit (-1);
        fprintf(fp,"%s",content);
        fclose(fp);
        if (fp) exit (-1);
}
#endif


#ifdef _INSERE_DADOS
// #define _INSERE_DADOS
struct lista *insere_dados(char *nome, char *email, int tell, int matricula, char *setor) 
{

        struct lista *novo;

        novo = (struct lista *)malloc(sizeof(struct lista));

        if (!novo) {
                novo= (struct lista *)malloc(sizeof(struct lista));

                if (!novo) {
                        fprintf(stderr,"Not enougth memory\n");
                }
        }

        novo->nome = (char *)malloc(strlen(nome)+1);

        if (!novo->nome) {

                novo->nome= (char *)malloc(strlen(nome)+1);

                if (!novo->nome) {
                        fprintf(stderr,"Not enougth memory\n");
                }
        }

        novo->setor = (char *) malloc(40*sizeof(char));

        if (!novo->setor) {
                novo->setor= (char *)malloc(40*sizeof(char));
                if (!novo->setor) {
                        fprintf(stderr,"Not enougth memory\n");
                }
        }

        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->email = email;
        novo->tell = tell;
        novo->matricula = matricula;
        novo->setor = setor;
        novo->next = NULL;

        linked_list->last->next = novo;
        novo->prev = linked_list->last;
        linked_list->last = novo;

        if (linked_list->last == linked_list->first) {
                linked_list->first->next = novo;
                
        }
        

        return novo;
}
#endif

#ifdef _EXIBE_DADOS
// #define _EXIBE_DADOS
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
#endif

#ifdef _CLEAR_BUFFER
void clear_buffer()
{
        for (; getchar() == '\n';);

}
#endif

#ifndef _BUSCA_DADOS
#define _BUSCA_DADOS
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
#endif

#ifdef _DELETA_DADOS
// #define _DELETA_DADOS
struct lista *deleta_dados(struct lista *dados)
{

        struct lista *novo;

        // novo = dados->next;

        // free(dados->nome);
        // free(dados);

        fprintf(stdout, "Informe a matricula do cidadao\n");
        int mat;
        fscanf(stdin,"%d", &mat);

        for (struct lista *temp = dados; temp != NULL; temp= temp->next) {
                if (temp->matricula == mat) {
                        // if (temp)
                }
        }

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\n");
        sleep(1);

        return novo;
}
#endif

#ifdef _CHECA_VAZIO
// #define _CHECA_VAZIO
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
#endif

#ifdef _INSERE
// #define _INSERE
void insere(void) 
{

        
}
#endif

#ifdef _BUSCA
// #define _BUSCA
void busca(void) 
{

        char *key;

        if (!checa_vazio(principal)) {

                key = (char *)malloc(BUFFER);
                if (!key) {
                        key = malloc (sizeof (BUFFER));
                        if (!key) {
                                fprintf(stderr,"Not enougth memory\n");
                        }
                }

                fprintf(stdout, "Digite o nome para buscar:\n--> ");
                scanf("%s", key);

                busca_dados(principal, key);
                getchar();
        }
}
#endif

#ifdef _EXIBE
// #define _EXIBE
void exibe(void) 
{

        if (!checa_vazio(principal))
            exibe_dados(principal);

}
#endif

/*
#ifndef _WRITE_TO_FILE
#define _WRITE_TO_FILE
void write_to_file(struct *list ls, int size, int op_type)
{
        FILE *fp;
        fp = fopen("cadastros.txt", "a");
        if (!fp) {
                printf("Error on opening file\n");
                exit (-1);
        }
        struct lista temp = ls->first;
        for (int i =0; i< size; i++) {
                fwrite(temp, 1, sizeof(struct lista), fp);

        }
        fclose(fp);
}
#endif
 */

#ifdef _DELETA
// #define _DELETA
void deleta(void) 
{

        if (!checa_vazio(principal))
        principal = deleta_dados(principal);
}
#endif


#ifndef _CABECALHO
#define _CABECALHO
void cabecalho(void)
{
  printf("*******************************\n");   
  printf("*          BEM VINDO          *\n");
  printf("*******************************\n");   

  return;
}
#endif

#endif // estrutua.h