#include <stdio.h>
#include <math.h>
#define pi atan(1)*4

int main()
{
    int r;
    scanf("%d",&r);
    printf("%.6f\n",r*r*pi);
    printf("%.6f",(float)r*r*2);
    return 0;
}
