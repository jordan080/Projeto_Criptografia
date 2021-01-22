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

	printf("Por favor, digite dois números primos p e q.\n");
	printf("Em seguida, digite um expoente relativamente primo a (p-1)(q-1).\n");
	printf("p: ");
    scanf("%ld", &p);


	while( !ehPrimo(p) )
	{
		printf("p não é primo, tente novamente: ");
		scanf("%ld", &p);
	}
	
	printf("q: ");
    scanf("%ld", &q);

	while( !ehPrimo(q) )
	{
		printf("q não é primo, tente novamente: ");
		scanf("%ld", &q);
	}

	printf("e: ");
    scanf("%ld", &e);

	while( mdc( (p - 1)*(q - 1), e) != 1 )
    {
        printf("e não é relativamente primo a (p-1)(q-1), tente novamente.\n");
		printf("e: ");
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
    
    fprintf(fptr, "%ld ", n);
    fprintf(fptr, "%ld\n", e);

	fclose(fptr);

	printf("\nA chave pública gerada é: %ld %ld\n\n", n, e);
	printf("Digite (1), para voltar ao menu: ");

	int continuar;
    scanf("%d", &continuar);

	getchar();
}