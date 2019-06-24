#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "estrutura.h"

// #include <curl/curl.h>
// #include "curl-7.65.0/include/curl/curl.h"

// #define FROM     "<htop@gmail.com>"
// #define TO       "<aopg@cesar.school>"
// #define CC       "<dfo@cesar.school>"

// #define MULTI_PERFORM_HANG_TIMEOUT 60 * 1000

// static const char *payload_text[] = {
//   "Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n",
//   "To: " TO "\r\n",
//   "From: " FROM " (Example User)\r\n",
//   "Cc: " CC " (Another example User)\r\n",
//   "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
//   "rfcpedant.example.org>\r\n",
//   "Subject: SMTP multi example message\r\n",
//   "\r\n", /* empty line to divide headers from body, see RFC5322 */
//   "The body of the message starts here.\r\n",
//   "\r\n",
//   "It could be a lot of lines, could be MIME encoded, whatever.\r\n",
//   "Check RFC5322.\r\n",
//   NULL
// };

int main(void) {


        // sleep(1);
        
        char choice;

        do {
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
                        case '1':{

                                char nome[40], email[40], setor[40];
                                
                                int matricula, tell;

                                fprintf(stdout, "\n\nNome: \n----> ");
                                scanf("%s", nome);
                                fprintf(stdout, "\n");

                                fprintf(stdout, "Email: \n----> ");
                                scanf("%s", email);
                                printf("email confirmL %s\n",email);
                                fprintf(stdout, "\n");
                                
                                fprintf(stdout, "Telefone: \n----> ");
                                scanf("%d", &tell);
                                fprintf(stdout, "%d \n",tell);
                                
                                fprintf(stdout, "Matricula: \n----> ");
                                scanf("%d", &matricula);
                                fprintf(stdout, "\n");


                                fprintf(stdout, "Setor: \n----> ");
                                scanf("%s", setor);
                                printf("main sector %s\n",setor);
                                // fprintf(stdout, "%s\n", setor);
                                

                                if (principal == NULL)
                                        inicia_dados(nome, email, tell, matricula, setor);
                                else
                                        insere_dados(nome, email, tell, matricula, setor);          
                                break;
                        }

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
                                printf("Ending Program\n ");
                                break;

                        default:
                                fprintf(stderr,"Digite uma opcao valida!\\n");
                                // sleep(1);
                                break;
                }

                getchar(); /* E para impedir sujeira na entrada da escolha. Nao lembro de nada melhor tambem.   */

        }
        while (choice != '5'); /* Loop Principal. */

        return 0;
}