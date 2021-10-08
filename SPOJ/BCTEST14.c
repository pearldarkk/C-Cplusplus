#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,v;
    scanf("%d%d%d",&a,&b,&v);
    if (v==a) printf("1");
    else if ((v-a) % (a-b) ==0) printf("%d",(v-b)/(a-b));
        else printf("%d",(v-b)/(a-b)+1);
    return 0;
}
