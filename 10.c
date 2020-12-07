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
  int n;
  scanf("%d\n", &n);

  int equas[n][2];

  /*
  equas[i][0] = b
  equas[i][1] = m
  */

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      scanf("%d", &equas[i][j]);
    }
  }

  int m_0 = 1;
  int array_m[n];
  int array_s[n];

  /*Encontrando o Mzão */
  for(int i = 0; i < n; i++)
  {
    m_0 = m_0 * equas[i][1];
  }

  /*Encontrando os Mzinhos */
  for (int i = 0; i < n; i++)
  {
    int aux = m_0 / equas[i][1];

    if (mdcEuclides(m_0, aux) == aux)
    {
      array_m[i] = aux;
    }
  }

  /*Encontrando as soluções das congruências*/
  for (int i = 0; i < n; i++)
  {
      array_s[i] = EncCong(array_m[i], equas[i][1], 1);
  }

  int res = 0;

  for (int i = 0; i < n; i++)
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
