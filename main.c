#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

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
        while((mdcEuclides(p, e) != 1) && (mdcEuclides(q, e) != 1))
        {
            printf("O expoente não primo entre p e q, tente novamente: ");
            scanf("%d", &e);
        }

        int n = p * q;

        int z = (p - 1) * (q - 1);

        char* tex;
        int m = 30;

        tex = (char*)malloc(m * sizeof(char));

        printf("Digite aqui a mensagem que deseja encriptar:");
        
        for (int i = 0; i < m; i++)
        {
            if (tex[i] == NULL)
            {
              m = m + 30;
              tex = (char*)malloc(m * sizeof(char));  
            }

            scanf("%c", &tex[i]);
        }

        int alfa_num[26];

        for(int j = 0; j < 26; j++)
        {
            alfa_num[j] = j + 2;
        }

        
    }

}