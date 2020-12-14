//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//other libraries 
#include "matematica_discreta.h"

int ordemCrescente (int* numero_1, int* numero_2)
{
    int auxiliar;
    int flag = 0;

    if (*numero_1 > *numero_2)
    {
        auxiliar = *numero_1;
        *numero_1 = *numero_2;
        *numero_2 = auxiliar;
        flag = 1;
    }

    return flag;
}
int ehPrimo(int numero)
{
    if(numero == 2) return 1;

    if(numero % 2 == 0) return 0;

    int quadrado = sqrt(numero);

    for(int i = 3; i <= quadrado; i += 2)
    {
        if(numero % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int contaRestos(int numero_1, int numero_2, int i)
{
    if(numero_1%numero_2 == 0)
    {
        return i;
    }

    return contaRestos(numero_2, numero_1%numero_2, i+1);
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

