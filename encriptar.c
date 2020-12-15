
//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//other libraries 
#include "encriptar.h"

void to_upper_if_need(char str[], int len)
{
    for(int i = 0; i < len; i++)
        str[i] = str[i] > 'Z' ? str[i] - 32 : str[i];
}
char* read_str(char *tex)
{
    int len = 10;
    int count = 0;
    tex = malloc(len * sizeof(char));
    char c;

    while ((c = getchar()) != '\n' )
    {
        if (count >= len)
        {
            tex = realloc(tex, (len += 10) * sizeof(char)); 
        }

        tex[count++] = c;
    }

    return tex;
}
void codification(long array[], char str[], int len) // Considerar deletar a str, para dar mais confiança e segurança ao codigo.
{
    for(int i = 0; i < len; i++)
        array[i] = (str[i] == ' ' ? 28 : str[i] - 'A' + 2);
}
long power(long base, long exp) {
    if (exp == 0)
        return 1;
    else if (exp % 2)
        return base * power(base, exp - 1);
    else {
        long temp = power(base, exp / 2);
        return temp * temp;
    }
}
void encriptar()
{
    system("clear");

	printf(" ___________________________________\n");
	printf("|                                   |\n");
	printf("|            Encriptar              |\n");
	printf("|                                   |\n");	
	printf("|___________________________________|\n");

    getchar();

    printf("Digite a mensagem que se deseja encriptar:\n");

    char* mens = read_str(mens);

    int len = strlen(mens);

    to_upper_if_need(mens, len);

    printf("Digite a chave pública recebida:\n");
    
    long n2, e2;
    
    scanf("%ld%ld", &n2, &e2);

    long code[len - 1];

    codification(code, mens, len - 1);

    for (int i = 0; i < len; i++)
    {
        code[i] = (power(code[i], e2)) % n2;
    }

    FILE *fptr2;

    fptr2 = fopen("mens_encr.txt", "w");

    if (fptr2 == NULL)
    {
        printf("Erro!");
        exit(1);
    }

    fprintf(fptr2, "%s", "Mensagem encriptada:\n");
    for (int i = 0; i < len - 1; i++)
    {
        fprintf(fptr2, "%ld, ", code[i]);
    }
    fprintf(fptr2, "%s", "\n");
    
    fclose(fptr2);
}