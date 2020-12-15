//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//other libraries 
#include "aritmetica.h"

long ehPrimo(long numero)
{
    if(numero == 2) return 1;
    if(numero % 2 == 0 || numero == 1) return 0;
    long quadrado = sqrt(numero);
    for(long i = 3; i <= quadrado; i += 2)
    {
        if(numero % i == 0)
            return 0;
    }
    return 1;
}
long mdcEuclides(long numero_1, long numero_2)
{
    if(numero_1%numero_2 == 0)
        return numero_2;
    return mdcEuclides(numero_2, numero_1%numero_2);  
}
long mdc(long numero_1, long numero_2)
{
    if (numero_1 > numero_2)
    {
        long auxiliar = numero_1;
        numero_1 = numero_2;
        numero_2 = auxiliar;
    }
    return mdcEuclides(numero_1, numero_2);
}