#include<stdio.h>

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
int mdcEuclides(int numero_1, int numero_2)
{

    if(numero_1%numero_2 == 0)
    {
        printf("%d = %d . %d\n", numero_1, numero_2, numero_1/numero_2);
        return numero_2;
    }
    else
    {
        printf("%d = %d . %d + %d\n", numero_1, numero_2, numero_1/numero_2, numero_1%numero_2);
    }

    return mdcEuclides(numero_2, numero_1%numero_2);
}

int main ()
{
    int numero_1, numero_2;

    scanf("%d%d", &numero_1, &numero_2);

    /* Armazena os números para imprimir no printf final */
    int a = numero_1;
    int b = numero_2;

    ordemDecrescente(&numero_1, &numero_2);

    printf("mdc(%d,%d) = %d\n", a, b, mdcEuclides(numero_1, numero_2));

    return 0;
}