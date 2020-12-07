#include <stdio.h>

int ehPrimo (int numero)
{

    if (numero <= 1)
    {
        return 0;
    }
    else
    {
        for (int i = numero - 1; i > 1; i--)
        {
            if( numero % i == 0)
            {
                return 0;
            }
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

int main ()
{
    int numero, primo;

    scanf("%d", &numero);

    primo = 2;

    printf("Numero\t|\tFatores\n");

    while ( numero > 1 )
    {

        if (numero %  primo == 0)
        {
            printf("%2.d\t|\t%2.d\n", numero, primo);

            numero = numero/primo;

        }
        else
        {
            primo = proximoPrimo(primo);
        }
        
    }

    printf("%2.d\t|\n", numero);
    

    return 0;
}