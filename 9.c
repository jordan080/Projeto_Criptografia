#include <stdio.h>

int EncCong(int a, int m, int x)
{
  for (int x = 0; x < a; x++)
  {
    if (((a * x) - 1) % m == 0)
    {
      return x;
    }
  }
}

int mdcEuclides(int numero_1, int numero_2)
{
    if(numero_1%numero_2 == 0)
    {
        return numero_2;
    }
    else
    {
        return mdcEuclides(numero_2, numero_1%numero_2);
    }
}

int main()
{
  int equas[3][2];

  /*
  equas[i][0] = b
  equas[i][1] = m
  */

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      scanf("%d", &equas[i][j]);

  int m_0 = 1;
  int array_m[3];
  int array_s[3];

  /*Encontrando o Mzão */
  for(int i = 0; i < 3; i++)
  {
    m_0 = m_0 * equas[i][1];
  }

  /*Encontrando os Mzinhos */
  for (int i = 0; i < 3; i++)
  {
    int aux = m_0 / equas[i][1];

    if (mdcEuclides(m_0, aux) == aux)
    {
      array_m[i] = aux;
    }
  }

  /*Encontrando as soluções das congruências*/
  for (int i = 0; i < 3; i++)
  {
      array_s[i] = EncCong(array_m[i], equas[i][1], 1);
  }

  int res = 0;

  for (int i = 0; i < 3; i++)
  {
    res = res + (array_m[i] * array_s[i] * equas[i][0]);
  }

  if (res > m_0)
  {
    printf("Resultado: %d\n", res % m_0);
  }
  else
  {
    printf("Resultado: %d\n", res);
  }

  return 0;
}
