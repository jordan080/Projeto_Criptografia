#include <stdio.h>
#include <time.h>

int main()
{
    int a,c;
    scanf("%d%d",&a,&c);
    for (int i = 0; i < c ; i++)
    {
        if (((a*i)%c)==1)
        {
            printf("%d * %d = %d (mod %d) = %d\n",a,i,(a*i),c,((a*i)%c));
        }
    }
    return 0;
}