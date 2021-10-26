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

    int n;
    scanf("%d", &n);
    int cnt, prev = 0, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (i == 0)
            continue;
        if (x <= prev) 
            cnt += prev - x + 1;
        prev = prev + 1 > x ? prev + 1 : x;
    }
    printf("%d", cnt);
    
    return 0;
}