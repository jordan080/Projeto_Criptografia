#include <stdio.h> // #############  DATA  13/12/2020  #############

int strLength(char str[]) // retorna o tamanho da string, contando com o '\n'
{
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len++;
}

void print_an_array(int array[], int len)
{
    printf("{");
    for(int i = 0; i < len; i++) 
        i == len - 1 ? printf("%d}\n", array[i]) : printf("%d, ", array[i]);
}

void print_an_string(char str[]) // tive problemas com o puts(), para variar...
{
    for(int i = 0; str[i] != '\0'; i++) 
        printf("%c", str[i]);
    printf("\n");
}

void to_upper_if_need(char str[], int len)
{
    for(int i = 0; i < len; i++)
        str[i] = str[i] > 'Z' ? str[i] - 32 : str[i];
}


void codification(int array[], char str[], int len) // Considerar deletar a str, para dar mais confiança e segurança ao codigo.
{
    for(int i = 0; i < len; i++)
        array[i] = str[i] != ' ' ? str[i] - 'A' + 2 : 28;
}

void decoding(int array[], char str[], int len, char digit_list[])
{
    for(int i = 0; i < len; i++)
        str[i] = digit_list[array[i] - 2];
    
    str[len] = '\0';
}

void main()
{
    char digit_list[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '\0'};
    char text[225]; // Falta tamanho dinamico
    int len;

    printf("Digite algo: ");
    fgets(text, sizeof(text), stdin);

    printf("Voce digitou: "); print_an_string(text);

    len = strLength(text);

    printf("TAMANHO DA STRING: %d\n", len);

    to_upper_if_need(text, len);
    
    printf("String transformada em maiusculo: ");

    print_an_string(text);

    int code[len - 1];
    
    codification(code, text, len - 1);

    printf("TEXTO CODIFICADO PARA:\n");

    print_an_array(code, len - 1);
    
    char newText[len];

    printf("\nDecodificando o array de inteiros:\n");
    decoding(code, newText, len - 1, digit_list);

    print_an_string(newText);

    printf("\n#############  FIM  #############\n");
}