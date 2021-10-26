#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    bool a[200001];
    memset(a, 0, sizeof a);
    int x;
    for (int i = 0; i < n-1; ++i) {
        scanf("%d", &x);
        a[x] = 1;
    }
    for (int i = 1; i < n+1; ++i)
        if (a[i] == 0)
            printf("%d", i);
    
    return 0;
}