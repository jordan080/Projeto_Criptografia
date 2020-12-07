#include <stdio.h>
#include <time.h>
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

int main()
{
  int primo = 2;

  int contagemInicial = time(0);

  while ( time(0) - contagemInicial != 60 )
  {
     if (ehPrimo(primo))
     {
       printf("Número primo: %d\n", primo );
     }
     primo = primo + 2;
  }
}
