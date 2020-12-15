//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "menu.h"
#include "gerar_chave.h"
#include "encriptar.h"
#include "desencriptar.h"

int escolha;

void request_menu() 
{ 
	system("clear");
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
}
int select_menu()
{
    int flag;
	switch(escolha) {
		case 1:	
			gerar_chave();
            flag = 1;
        	break;
		case 2:
			encriptar();
            flag = 1;
			break;
        case 3:
        	desencriptar();
            flag = 1;
            break;
		default: 
			flag = 0;
			break;
	}
	return flag;
}