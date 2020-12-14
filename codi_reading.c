#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 10;
    int count = 0;
    char *tex = malloc(len * sizeof(char));
    char c;

    while ((c = getchar()) != '\n' )
    {
        if (count >= len)
        {
            tex = realloc(tex, (len += 10) * sizeof(char)); 
        }

        tex[count++] = c;
    }
}