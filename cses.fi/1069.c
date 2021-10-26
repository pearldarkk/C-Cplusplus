#include <math.h>
#include <stdio.h>
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
    char x, prev = 0;
    int cnt, max = 1;
    while (scanf("%c", &x) != EOF) {
        if (x == prev)
            ++cnt;
        else {
            max = max > cnt ? max : cnt;
            cnt = 1;
        }
        prev = x;
    }
    printf("%d", max);
    return 0;
}