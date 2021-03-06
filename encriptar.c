
//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "encriptar.h"
#include "aritmetica.h"

char digit_list[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '\0'};

//Retorna o tamanho da string, contando com o '\n'
int strLength(char str[]) 
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len++;
}
void to_upper_if_need(char str[], long len)
{
    for(int i = 0; i < len; i++)
        str[i] = str[i] > 'Z' ? str[i] - 32 : str[i];
}
void codification(long array[], char str[], long len)
{
    for(int i = 0; i < len; i++)
        array[i] = str[i] != ' ' ? str[i] - 'A' + 2 : 28;
}
void print_an_array(long array[], long len)
{
    for(int i = 0; i < len; i++) 
        i == len - 1 ? printf("%ld", array[i]) : printf("%ld ", array[i]);
}
void print_array_file(long array[], long len, FILE* f)
{
    for(int i = 0; i < len; i++)
        fprintf(f, "%ld ", array[i]);
}
void intro_encriptar()
{
    system("clear");
	printf(" ___________________________________\n");
	printf("|                                   |\n");
	printf("|            Encriptar              |\n");
	printf("|                                   |\n");	
	printf("|___________________________________|\n\n");
}
void encriptar()
{
    intro_encriptar();

    char text[1000000];
    printf("Digite a mensagem de texto que se deseja encriptar:\n");
    getchar();
    fgets(text, sizeof(text), stdin);

    long len;
    len = strLength(text);
    //Converte caracteres minúsculos para seu equivalente maiúsculo.
    to_upper_if_need(text, len);
    
    long code[len - 1];
    long n, e;

    //Converte o alfabeto em números.
    codification(code, text, len - 1);

    printf("Digite a chave pública recebida:\n");
    printf("n: ");
    scanf("%ld", &n);
    printf("e: ");
    scanf("%ld", &e);

    //Converte texto original em texto criptografado.
    criptografa(code, len - 1, e, n);

    FILE *f;

    f = fopen("mensagem_criptografada.txt", "w");

    if (f == NULL)
    {
        printf("Erro!\n");
        exit(1);
    }
    //Imprime o texto criptografado no terminal.
    printf("Texto criptografado:\n");
    print_an_array(code, len - 1);
    //Imprime o texto criptografado no arquivo.
    print_array_file(code, len - 1, f);

    fclose(f);
    
    printf("\n\nDigite (1), para voltar ao menu: ");
	int continuar;
    scanf("%d", &continuar);
}