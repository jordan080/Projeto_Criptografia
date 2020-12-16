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
long ordemCrescente(long* numero_1, long* numero_2)
{
    long auxiliar;
    long flag = 0;

    if (*numero_1 > *numero_2)
    {
        auxiliar = *numero_1;
        *numero_1 = *numero_2;
        *numero_2 = auxiliar;
        flag = 1;
    }

    return flag;
}
long contaRestos(long numero_1, long numero_2, long i)
{
    if(numero_1%numero_2 == 0)
        return i;
    return contaRestos(numero_2, numero_1%numero_2, i+1);
}
long mdc_euclides(long numero_1, long numero_2, long resto[], long i)
{
    if(numero_1%numero_2 == 0)
        return numero_2;
    resto[i] = numero_1/numero_2;
    return mdc_euclides(numero_2, numero_1%numero_2, resto, i - 1);
}
void calcula_s_t(long resto[], long j, long i)
{
    if ( i > j)
        return;
    if ( i == 0)
        resto[i] = resto[i]*1;
    else if ( i == 1)
        resto[i] = resto[i]*resto[i-1]+1;
    else
        resto[i] = resto[i]*resto[i-1]+resto[i-2];

    calcula_s_t(resto, j, i + 1);
}
long verifica_intervalo(long s, long numero_2)
{
    if(s > 0 && s < numero_2)
        return s;
    else
        return ((numero_2 + (s%numero_2)) % numero_2);
}
long fast_modular_exponentiation(long texto_puro, long e, long n)
{
	long result = 1;
	if (1 & e)
		result = texto_puro;
	while (1) {
		if (!e) break;
		e >>= 1;
		texto_puro = (texto_puro * texto_puro) % n;
		if (e & 1)
			result = (result * texto_puro) % n;
	}
	return result;
}
void criptografa(long array[], long tamanho, long e, long n)
{
    for(int i = 0; i < tamanho; i++)
    {
       array[i] = fast_modular_exponentiation(array[i], e, n);
    }
}
long inverso(long numero_1, long numero_2)
{

    long i, d, total_restos, s, t, trocou_ordem;

    //Condição para MDC de números diferentes de 0
    if( numero_1 && numero_2 )
    {

        trocou_ordem = ordemCrescente(&numero_1, &numero_2);
        total_restos = contaRestos(numero_1, numero_2, 0);
        
        long resto[total_restos];
        i = total_restos - 1;
        d = mdc_euclides(numero_1, numero_2, resto, i);

        if( total_restos > 1 )
            calcula_s_t(resto, i, 0);
        if( total_restos == 1 )
        {
            s = 1;
            t = 0;
        }
        else if ( total_restos % 2 == 0 )
        {
            s = resto[i-1] * (-1);
            t = resto[i];
        }
        else
        {
            s = resto[i-1];
            t = resto[i] * (-1);
        }

        //Troca para a ordem original
        if (trocou_ordem)
        {
            long auxiliar;
            auxiliar = numero_1;
            numero_1 = numero_2;
            numero_2 = auxiliar;

            auxiliar = s;
            s = t;
            t = auxiliar;
        }

        //Verifica se o inverso está no intevalo entre 0 e numero_2.
        s = verifica_intervalo(s, numero_2);
        return s;
    }
    else
    {
        //Quando numero_1 ou numero_2 são iguais a zero, s = 1.
        return 1;        
    }
}