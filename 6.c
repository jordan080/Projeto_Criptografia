#include <stdio.h>

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

int contaRestos(int numero_1, int numero_2, int i)
{
    if(numero_1%numero_2 == 0)
    {
        return i;
    }

    return contaRestos(numero_2, numero_1%numero_2, i+1);
}

int mdcEuclides(int numero_1, int numero_2, int resto[], int i)
{
    if(numero_1%numero_2 == 0)
    {
        return numero_2;
    }

    resto[i] = numero_1/numero_2;
    
    //printf("resto[%d] - %d\n", i, resto[i]);

    return mdcEuclides(numero_2, numero_1%numero_2, resto, i - 1);
}

void calcula_s_t(int resto[], int j, int i)
{
    if ( i > j)
    {
        return;
    }

    if ( i == 0)
    {
        resto[i] = resto[i]*1;
    }
    else if ( i == 1)
    {
        resto[i] = resto[i]*resto[i-1]+1;
    }
    else
    {
        resto[i] = resto[i]*resto[i-1]+resto[i-2];
    }
    
    //printf("resto[%d] = %d\n", i, resto[i]);
    calcula_s_t(resto, j, i + 1);
}

int main ()
{
    int numero_1, numero_2, i, d, total_restos, s, t, trocou_ordem;

    scanf("%d%d", &numero_1, &numero_2);

    //MDC de números diferentes de 0
    if( numero_1 && numero_2 )
    {
        //Para imprimir na ordem correta, no final.
        int a = numero_1;
        int b = numero_2;

        trocou_ordem = ordemCrescente(&numero_1, &numero_2);

        total_restos = contaRestos(numero_1, numero_2, 0);

        int resto[total_restos];

        i = total_restos - 1;

        d = mdcEuclides(numero_1, numero_2, resto, i);

        if ( total_restos > 1 )
        {
            calcula_s_t(resto, i, 0);
        }

        if ( total_restos == 1 )
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
        if(trocou_ordem)
        {
            int auxiliar;
            auxiliar = numero_1;
            numero_1 = numero_2;
            numero_2 = auxiliar;

            auxiliar = s;
            s = t;
            t = auxiliar;
        }

        printf("s = %d e t = %d\n", s, t);
        printf("%d = %d * %d + %d * %d\n", d, s, numero_1, t, numero_2);
    }
    //MDC quando a ou b são iguais a zero
    else
    {
        d = 1;

        if ( numero_1 == 0 )
        {
            t = 1;
            printf("s pode ser qualquer número inteiro.\nt = %d\n", t);
            printf("%d = %d * %d + %d * %d\n", d, s, numero_1, t, numero_2);
        }
        else
        {
            s = 1;
            printf("s = %d\nt pode ser qualquer número inteiro.\n", s);
            printf("%d = %d * %d + %d * %d\n", d, s, numero_1, t, numero_2);
        }
        
    }
  
    return 0;
}