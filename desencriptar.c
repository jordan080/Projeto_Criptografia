//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "desencriptar.h"
#include "aritmetica.h"

char digit[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '\0'};

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
void decoding(long array[], char str[], long len, char digit_list[])
{
    for(long i = 0; i < len; i++)
        str[i] = digit_list[array[i] - 2];
    
    str[len] = '\0';
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

    printf("\nCertifique-se que o Texto Criptografado foi corretamente escrito no arquivo:\nmensagem_criptografada.txt\n");
    printf("\nDigite (1) para continuar: ");
	int continuar;
    scanf("%d", &continuar);

    FILE *f;

    f = fopen("mensagem_criptografada.txt", "r");

    if (f == NULL)
    {
        printf("Erro1!\n");
        exit(1);
    }

    long i = 0;
    long* texto_criptografado = NULL;

    texto_criptografado = ler_texto_criptografado(texto_criptografado, f, &i);
    //Define o indicador para a posição inicial
    fseek ( f, 0 , SEEK_SET);
    fclose(f);

    long z = (p-1)*(q-1);
    long n = p*q;
    long d = inverso(e, z);

    //Converte texto criptografado em alfabeto de números.
    criptografa(texto_criptografado, i, d, n);
    
    char newText[i];
    decoding(texto_criptografado, newText, i, digit);

    f = fopen("mensagem_desencriptada.txt", "w");

    if (f == NULL)
    {
        printf("Erro2!\n");
        exit(1);
    }

    printf("\nSua mensagem é:\n");
    printf("%s\n", newText);
    fprintf(f, "%s", newText);

    free(texto_criptografado);
    fclose(f);

    printf("\nDigite (1) para continuar: ");
    scanf("%d", &continuar);

}