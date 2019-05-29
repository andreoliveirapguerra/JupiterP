#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estrutura.c"




int main(void) {

        cabecalho();
        sleep(1);
        
        char choice;

        do {
                system("cls"); 
                fprintf(stdout, "\n----Cadastro----\n\n");
                fprintf(stdout, "Escolha uma opcao: \n");
                fprintf(stdout, "1 - Insere Dados\n");
                fprintf(stdout, "2 - Exibe Dados\n");
                fprintf(stdout, "3 - Busca Dados\n");
                fprintf(stdout, "4 - Deleta Dados\n");
                fprintf(stdout, "5 - Sair\n");
                printf("--->");
                scanf("%c", &choice);

                switch(choice) {
                        case '1':
                                insere();
                                break;

                        case '2':
                                exibe();
                                break;

                        case '3':
                                busca();
                                break;

                        case '4':
                                deleta();
                                break;

                        case '5':
                                exit(0);
                                break;

                        default:
                                fprintf(stderr,"Digite uma opcao valida!\\n");
                                sleep(1);
                                break;
                }

                getchar(); /* E para impedir sujeira na entrada da escolha. Nao lembro de nada melhor tambem.   */
        }
        while (choice > 0); /* Loop Principal. */

        return 0;
}