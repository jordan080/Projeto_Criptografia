//standard libraries
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//other libraries 
#include "libraries.h"

//void request_menu(char* escolha) 
int request_menu() 
{ 
    int escolha;
	system("clear"); //stdlib
	printf(" ___________________________________\n");
	printf("|          Criptografia RSA         |\n");
	printf("|Lista de opções:                   |\n");
	printf("|(1) Gerar chave pública            |\n");	
	printf("|(2) Encriptar                      |\n");
	printf("|(3) Desencriptar                   |\n");
    printf("|(4) Sair                           |\n");
	printf("|___________________________________|\n");
	printf("Opção: ");
	scanf("%d", &escolha);
    return escolha;
}
void request_p_q_e(int* p, int* q, int* e)
{
    printf("Digite um número primo p: ");
    scanf("%d", p);

	while( !ehPrimo(*p) )
	{
		printf("O primeiro número não é primo, tente novamente: ");
		scanf("%d", p);
	}
	
	printf("Digite um número primo q: ");
    scanf("%d", q);

	while( !ehPrimo(*q) )
	{
		printf("O segundo número não é primo, tente novamente: ");
		scanf("%d", q);
	}

    printf("Digite um expoente e, relativamente primo a (p-1)(q-1): ");
    scanf("%d", e);

	while( ( mdcEuclides((p - 1) * (q - 1), *e) != 1 ) )
    {
        printf("O expoente e não é primo entre p e q, tente novamente: ");
        scanf("%d", e);
    }


	char c = getchar();

	while((mdcEuclides((*p - 1) * (*q - 1), *e) != 1))
	{
		printf("O expoente não primo entre p e q, tente novamente: ");
		scanf("%d", e);
	}
}
void encriptar()
{

}
void desencriptar()
{

}

int select_menu(int escolha, int* p, int* q, int* e)
{
    printf("%d\n", escolha);
    int flag;
	switch(escolha) {
		case 1:	
			request_p_q_e(p, q, e);
            flag = 1;
        	break;
		case 2:
			//encriptar();
            flag = 2;
			break;
        case 3:
        	//desencriptar();
            flag = 3;
            break;
		default: 
			flag = 0;
			break;
	}
	return flag;
}

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

