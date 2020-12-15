//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "desencriptar.h"

void intro_desencriptar()
{
	system("clear");
	printf(" ___________________________________\n");
	printf("|                                   |\n");
	printf("|          Desencriptar             |\n");
	printf("|                                   |\n");	
	printf("|___________________________________|\n\n");
}
long* ler_texto_criptografado(long* texto_criptografado, FILE* f, long* i)
{
    long auxiliar;
    long* proximo_valor = NULL;

    while ( ( fscanf(f, "%ld ", &auxiliar) ) != EOF )
    {
        ++*i;

        proximo_valor = (long*) realloc (texto_criptografado, (*i) * sizeof(long));

        if (proximo_valor != NULL) 
        {
            texto_criptografado=proximo_valor;
            texto_criptografado[(*i)-1]=auxiliar;
        }
        else 
        {
            free(texto_criptografado);
            puts("Error (re)allocating memory");
            exit(1);
        }
    }

    return texto_criptografado;
}

void desencriptar()
{
    intro_desencriptar();

    long p, q, e;

	printf("Digite o número primo p: ");
    scanf("%ld", &p);
	
	printf("Digite o número primo q: ");
    scanf("%ld", &q);

    printf("Digite o valor e: ");
    scanf("%ld", &e);

    printf("\nCertifique-se que o Texto Criptografado foi corretamente escrito no arquivo:\ntexto_criptografado.txt\n");
    printf("\nDigite (1) para continuar: ");
	int continuar;
    scanf("%d", &continuar);

    FILE *f;

    f = fopen("texto_criptografado.txt", "r");

    if (f == NULL)
    {
        printf("Erro!\n");
        exit(1);
    }

    long i = 0;
    long* texto_criptografado = NULL;

    texto_criptografado = ler_texto_criptografado(texto_criptografado, f, &i);
    //Define o indicador para a posição inicial
    fseek ( f, 0 , SEEK_SET);

    free(texto_criptografado);
    fclose(f);

}