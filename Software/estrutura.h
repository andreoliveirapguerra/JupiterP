#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef _ESTRUTURA_H
#define _ESTRUTURA_H
#define BUFFER 100

struct lista{
	char *nome;
	char *email;
	int tell;
	int matricula;
	char *setor;
	struct lista *next;
};

struct lista *principal = NULL;

struct lista *inicia_dados(char *nome, char *email, int tell, int matricula, char *setor);
struct lista *insere_dados(struct lista *dados, char *nome, char *email, int tell, int matricula, char *setor);
void exibe_dados(struct lista *dados);
void busca_dados(struct lista *dados, char *key);
struct lista *deleta_dados(struct lista *dados);
int checa_vazio(struct lista *dados);

void insere(void);
void busca(void);
void exibe(void);
void deleta(void);


#endif