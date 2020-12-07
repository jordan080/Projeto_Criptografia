#include <stdio.h>

int combLinear(int numero_1, int numero_2, int array_inv[], int tam, int mdc)
{
    array_inv[1] = array_inv[1]*array_inv[0] + 1;

    for (int i = 2; i < tam; i++)
    {
        array_inv[i] = (array_inv[i] * array_inv[i - 1]) + array_inv[i - 2];
    }

    if (tam % 2 == 0)
    {
        array_inv[tam - 2] = array_inv[tam - 2] * (-1);
    }
    else
    {
        array_inv[tam - 1] = (array_inv[tam - 1]) * (-1);
    }

    return array_inv[tam - 1];
}

void invArray(int array[], int array_inv[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        array_inv[i] = array[tam - i - 1];
    }

    return;
}

int arrayMdc(int numero_1, int numero_2, int array[], int i)
{
    if(numero_1%numero_2 == 0)
    {
        return i;
    }
    else
    {
        array[i] = numero_1/numero_2;

        return arrayMdc(numero_2, numero_1%numero_2, array, i + 1);
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

void ordemDecrescente (int* numero_1, int* numero_2)
{
    int auxiliar;
    if (*numero_1 < *numero_2)
    {
        auxiliar = *numero_1;
        *numero_1 = *numero_2;
        *numero_2 = auxiliar;
    }
}

int contaRestos(int numero_1, int numero_2, int i)
{
    if(numero_1%numero_2 == 0)
    {
        return i;
    }
    return contaRestos(numero_2, numero_1%numero_2, i+1);
}

int main()
{
  int a, b, m, inv;

  scanf("%d%d%d", &a, &b, &m);

if (a && m)
{
  ordemDecrescente(&a, &m);

  int mdc = mdcEuclides(a, m);

  int restos = contaRestos(a, m, 0);

  int array[restos];

  if (b % mdc != 0)
  {
    printf("Não há solução\n");
    return 0;
  }
  else if (mdc == 1)
  {
    //printf("Gerando combinação linear do tipo s.a + t.m = 1\n");

    int array_inv[restos];

    int tam = arrayMdc(a, m, array, 0);

    invArray(array, array_inv, tam);

    inv = combLinear(a, m, array_inv, tam, mdc);

    printf("%d, %d\n", inv * b, a);

    if (inv * b > a)
    {
      printf("x = %d * %d = %d\n", inv, b, (inv * b) % a);
    }
    else
    {
      printf("x = %d * %d = %d\n", inv, b, inv * b);
    }
  }
  else
  {
    a = a / mdc;
    b = b / mdc;
    m = m / mdc;

    printf("%d %d %d, %d\n", a, b, m, mdc);

    int array_inv[restos];

    int tam = arrayMdc(a, m, array, 0);

    invArray(array, array_inv, tam);

    int inv = combLinear(a, m, array_inv, tam, mdc);

    printf("Soluções:\n");
    printf("%d ", inv);

    for (int i = 0; i < mdc - 1; i++)
    {
      printf("%d ", inv + (a * (i + 1)));
    }
    printf("\n");
  }
}
else
{
  if (a == 0)
  {
    inv = 0;
    printf("O inverso pode ser qualquer número inteiro.\n");
    printf("%d * %d = %d\n", inv, b, inv * b);
  }
  else
  {
    inv = 1;

    printf("\"a\" pode ser qualquer número inteiro.\n");
    printf("%d * %d = %d\n", inv, b, inv * b);
  }
}
  return 0;
}
