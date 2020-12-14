//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//other libraries 
#include "gerar_chave.h"
#include "matematica_discreta.h"

//void request_menu(char* escolha) 
int request_menu() 
{ 
    int escolha;
	system("clear"); //stdlib
	printf(" ___________________________________\n");
	printf("|          Criptografia RSA         |\n");
	printf("|Lista de opções:                   |\n");
	printf("|(1) Gerar chave pública            |\n");	
	printf("|(2) Encriptar                      |\n");
	printf("|(3) Desencriptar                   |\n");
    printf("|(4) Sair                           |\n");
	printf("|___________________________________|\n");
	printf("Opção: ");
	scanf("%d", &escolha);
    return escolha;
}
int select_menu(int escolha, long* p, long* q, long* e)
{
    printf("%d\n", escolha);
    int flag;
	switch(escolha) {
		case 1:	
			request_p_q_e(p, q, e);
            flag = 1;
        	break;
		case 2:
			//encriptar();
            flag = 2;
			break;
        case 3:
        	//desencriptar();
            flag = 3;
            break;
		default: 
			flag = 0;
			break;
	}
	return flag;
}
void request_p_q_e(long* p, long* q, long* e)
{
    printf("Digite um número primo p: ");
    scanf("%ld", p);

	while( !ehPrimo(*p) )
	{
		printf("O primeiro número não é primo, tente novamente: ");
		scanf("%ld", p);
	}
	
	printf("Digite um número primo q: ");
    scanf("%ld", q);

	while( !ehPrimo(*q) )
	{
		printf("O segundo número não é primo, tente novamente: ");
		scanf("%ld", q);
	}

    printf("Digite um expoente e, relativamente primo a (p-1)(q-1): ");
    scanf("%ld", e);

	while( ( mdcEuclides((*p - 1) * (*q - 1), *e) != 1 ) )
    {
        printf("O expoente e não é primo entre p e q, tente novamente: ");
        scanf("%ld", e);
    }

	getchar();
}