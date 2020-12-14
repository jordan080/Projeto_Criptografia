#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

//função pra testar
// TIRAR DAQUI E BOTAR NA LIBRARIES.C//
void print_an_array(int array[], int len)
{
    printf("{");
    for(int i = 0; i < len; i++) 
        i == len - 1 ? printf("%d}\n", array[i]) : printf("%d, ", array[i]);
}

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
// TIRAR DAQUI E BOTAR NA LIBRARIES.C//

int main()
{
    int escolha;
    printf("Escolha entre uma das três opções abaixo:\n1-Gerar uma chave pública\n2-Encriptar\n3-Descriptar\nOpção: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        long p, q, e;
        printf("Digite dois números primos (preferencialmente grandes) e um expoente primo aos outros dois:\n");
        scanf("%ld%ld%ld", &p, &q, &e);

        getchar();

        while(ehPrimo(p) == 0)
        {
            printf("O primeiro número não é primo, tente novamente: ");
            scanf("%ld", &p);
        }
        while(ehPrimo(q) == 0)
        {
            printf("O segundo número não é primo, tente novamente: ");
            scanf("%ld", &q);
        }
        while((mdcEuclides((p - 1) * (q - 1), e) != 1))
        {
            printf("O expoente não é primo entre p e q, tente novamente: ");
            scanf("%ld", &e);
        }

        long n = p * q;

        FILE *fptr;

        fptr = fopen("ch.txt", "w");

        if (fptr == NULL)
        {
            printf("Erro!");
            exit(1);
        }
        fprintf(fptr, "%s", "Suas chaves são:\n");
        fprintf(fptr, "%ld ", n);
        fprintf(fptr, "%ld\n", e);
    }
    if (escolha == 2)
    {
        getchar();

        printf("Digite a mensagem que se deseja encriptar:\n");

        char* mens = read_str(mens);

        int len = strlen(mens);

        to_upper_if_need(mens, len);

        printf("Digite a chave pública recebida:\n");
        long n2, e2; scanf("%ld%ld", &n2, &e2);

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
    }
    if (escolha == 3)
    {
        long p2, q2, e2;
        printf("Digite dois números primos (preferencialmente grandes) e um expoente primo aos outros dois:\n");
        scanf("%ld%ld%ld", &p2, &q2, &e2);

        getchar();

        char digit_list[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '\0'};
    }
}