#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define EL printf("\n")
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define ld long double
#define ll long long
#define ull unsigned long long

int main() {
    // freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ull n;
    scanf("%lld", &n);
    printf("%lld ", n);
    while (n != 1) {
        n = n & 1 ? 3*n + 1 : n >> 1;
        printf("%lld ", n);
    }

    return 0;
}