#ifndef _ESTRUTURA_H
#define _ESTRUTURA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estrutura.h"

#define BUFFER 100

struct lista;
struct list;
struct chained_list;

#ifndef _PRINCIPAL
#define _PRINCIPAL
struct lista *principal;

#endif // principal

#ifndef _FWRITER
#define _FWRITER
void write_file(FILE *FP, char *content);
#endif


#ifndef _CHAINED_LIST
#define _CHAINED_LIST
struct list *linked_list;
#endif

#ifndef _DEBUG_AT
#define _DEBUG_AT
void debug(void);
#endif

#ifndef _CLEAR_BUFFER
#define _CLEAR_BUFFER
void clear_buffer(void);
#endif


#ifndef _INSERT_AT
#define _INSERT_AT
void insert_at( char name[], char email[], int tell, int mat, char setor[]) ;
#endif

#ifndef _INICIA_DADOS
#define _INICIA_DADOS
struct lista *inicia_dados(char *nome, char *email, int tell, int matricula, char *setor);
#endif // _INICIA_DADOS

#ifndef _INSERE_DADOS
#define _INSERE_DADOS
struct lista *insere_dados(char *nome, char *email, int tell, int matricula, char *setor);
#endif

#ifndef _EXIBE_DADOS
#define _EXIBE_DADOS
void exibe_dados(struct lista *dados);
#endif // _EXIBE_DADOS

#ifdef _BUSCA_DADOS
#define _BUSCA_DADOS
void busca_dados(struct lista *dados, char *key);
#endif // _BUSCA_DADOS

#ifndef _DELETA_DADOS
#define _DELETA_DADOS
struct lista *deleta_dados(struct lista *dados);
#endif // _DELETA_DADOS

#ifndef _CHECA_VAZIO
#define _CHECA_VAZIO
int checa_vazio(struct lista *dados);
#endif //checa

#ifndef _INSERE
#define _INSERE
void insere(void);
#endif // _INSERE

#ifndef _BUSCA
#define _BUSCA
void busca(void);
#endif // _BUSCA

#ifndef _EXIBE
#define _EXIBE
void exibe(void);
#endif // _EXIBE

#ifndef _DELETA
#define _DELETA
void deleta(void);
#endif // _DELETA

#endif // _ESTRUTURA_H

