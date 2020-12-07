#include<stdio.h>

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

int proximoPrimo(int pri1)
{
  int pri2 = pri1 + 2;

  while(!ehPrimo(pri2))
    pri2 += 2;
  
  return pri2;
}

int mmc (int numero_1, int numero_2 )
{
    int primo = 2;
    int fatoresPrimos = 1;

    printf("mmc(%d,%d) = ", numero_1, numero_2);

    while ( numero_1 > 1 || numero_2 > 1 )
    {
        //É preciso uma única condição, porque se ambos forem múltiplos do mesmo fator, devemos contabilizá-lo apenas uma vez.
        if ( numero_1 % primo == 0 || numero_2 % primo == 0)
        {
            printf("%d", primo);

            fatoresPrimos *= primo;
                        
            //Qual número devo dividir pelo primo ?
            //É bom deixar nessa ordem, para garantir quando são os 2 números são múltiplos do primo.
            if (numero_1 % primo == 0 && numero_2 % primo == 0)
            {
                numero_1 = numero_1/primo;
                numero_2 = numero_2/primo;
            }
            else if (numero_2 % primo == 0)
            {
                numero_2 = numero_2/primo;
            }
            else if (numero_1 % primo == 0)
            {
                numero_1 = numero_1/primo;
            }

            //Condição para imprimir . entre os fatores, menos na última iteração do while.
            if( !(numero_1 == 1 && numero_2 == 1) )
            {
                printf(" . ");
            }

        }
        else
        {
            primo = proximoPrimo(primo);
        }
        
    }

    return fatoresPrimos;
}

int mdc (int numero_1, int numero_2 )
{
    int menorNumero;
    int primo = 2;
    int fatoresPrimos = 1;

    printf("mdc(%d,%d) = ", numero_1, numero_2);

    if(numero_1 < numero_2)
    {
        menorNumero = numero_1;
    }
    else
    {
        menorNumero = numero_2;
    }
    

    while ( primo <= menorNumero )
    {
        //Garante que ambos números sejam divisiveis pelo mesmo primo.
        if ( numero_1 % primo == 0 && numero_2 % primo == 0)
        {
            printf("%d ", primo);

            fatoresPrimos *= primo;
                        
            numero_1 = numero_1/primo;
            numero_2 = numero_2/primo;

        }
        else
        {
            primo = proximoPrimo(primo);
        }
        
    }

    return fatoresPrimos;
}

int main ()
{
    int numero_1, numero_2;

    scanf("%d%d", &numero_1, &numero_2);

    printf(" = %d\n", mmc(numero_1, numero_2) );
    printf(" = %d\n", mdc(numero_1, numero_2) );

    return 0;

}