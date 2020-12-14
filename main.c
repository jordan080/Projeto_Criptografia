#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

//função pra testar
void print_an_string(char str[]) // tive problemas com o puts(), para variar...
{
    for(int i = 0; str[i] != '\0'; i++) 
        printf("%c", str[i]);
    printf("\n");
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

int main()
{
    int escolha;
    printf("Escolha entre uma das três opções abaixo:\n1-Gerar uma chave pública\n2-Encriptar\n3-Descriptar\nOpção: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        int p, q, e;
        printf("Digite dois números primos (preferencialmente grandes) e um expoente primo aos outros dois:\n");
        scanf("%d%d%d", &p, &q, &e);

        char c = getchar();

        while(ehPrimo(p) == 0)
        {
            printf("O primeiro número não é primo, tente novamente: ");
            scanf("%d", &p);
        }
        while(ehPrimo(q) == 0)
        {
            printf("O segundo número não é primo, tente novamente: ");
            scanf("%d", &q);
        }
        while((mdcEuclides((p - 1) * (q - 1), e) != 1))
        {
            printf("O expoente não primo entre p e q, tente novamente: ");
            scanf("%d", &e);
        }

        int n = p * q;

        FILE *fptr;

        fptr = fopen("saida.txt", "w");

        if (fptr == NULL)
        {
            printf("Erro!");
            exit(1);
        }
        fprintf(fptr, "%s", "Suas chaves são:\n");
        fprintf(fptr, "%d ", n);
        fprintf(fptr, "%d\n", e);
    }
}