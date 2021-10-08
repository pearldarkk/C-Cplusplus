#include <stdio.h>
#include <string.h>

int mod(int a, char b[])
{
    int r = 0;
    for (int i = 0; i < strlen(b); ++i)
        r = (r*10 + (b[i] - 48)) % a;

    return r;
}

int gcd(int a, int b)
{
    int r;

    while (b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int gcdLarge(int a, char b[])
{
    int x = mod(a, b);

    return gcd(a, x);
}

int main()
{
    int n;
    scanf("%d",&n);
    
    while (n--)
    {
        int a;
        char b[255];
        scanf("%d%s",&a, b);
        if (a==0) 
        {
            printf("%s\n",b);
            continue;
        }
        printf("%d\n",gcdLarge(a, b));
    }

    return 0;
}