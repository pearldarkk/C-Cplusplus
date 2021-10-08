#include <stdio.h>

int main()
{
    int n;
    long long int s;

    do {
        scanf("%d",&n);
        s=1;
        for (int i=2;i<=n;++i)
            s*=i;
        if (n) printf("%lld\n",s);
    } while (n);

    return 0;
}
