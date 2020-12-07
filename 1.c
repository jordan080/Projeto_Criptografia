#include <stdio.h>
#include <math.h>

int ehPrimo(int num) // Erick dia 30 14:37
{
    if(num == 2) return 1;

    if(num % 2 == 0) return 0;

    int quadrado = sqrt(num);

    for(int i = 3; i <= quadrado; i += 2)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main ()
{
    int numero;

    scanf("%d", &numero);

    if (ehPrimo(numero))
    {
        printf("%d é primo\n", numero);
    }
    else
    {
        printf("%d não é primo\n", numero);
    }

    return 0;
}
