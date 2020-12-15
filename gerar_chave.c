//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "gerar_chave.h"
#include "aritmetica.h"
#include "encriptar.h"

void intro_gerar_chave()
{
	system("clear");

	printf(" ___________________________________\n");
	printf("|                                   |\n");
	printf("|          Chave Pública            |\n");
	printf("|                                   |\n");	
	printf("|___________________________________|\n\n");
}
void gerar_chave()
{
	intro_gerar_chave();

	long p, q, e;

	printf("Digite um número primo p: ");
    scanf("%ld", &p);


	while( !ehPrimo(p) )
	{
		printf("O primeiro número não é primo, tente novamente: ");
		scanf("%ld", &p);
	}
	
	printf("Digite um número primo q: ");
    scanf("%ld", &q);

	while( !ehPrimo(q) )
	{
		printf("O segundo número não é primo, tente novamente: ");
		scanf("%ld", &q);
	}

    printf("Digite um expoente e, relativamente primo a (p-1)(q-1): ");
    scanf("%ld", &e);

	while( mdc( (p - 1)*(q - 1), e) != 1 )
    {
        printf("O expoente e não é primo entre p e q, tente novamente: ");
        scanf("%ld", &e);
    }

	long n = (p) * (q);

    FILE *fptr;

    fptr = fopen("chave_publica.txt", "w");

    if (fptr == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    
    fprintf(fptr, "%ld\n", n);
    fprintf(fptr, "%ld\n", e);

	fclose(fptr);

	printf("\nA chave pública gerada é: %ld\n", n);
	printf("Digite (1), para voltar ao menu: ");

	int continuar;
    scanf("%d", &continuar);

	getchar();
}