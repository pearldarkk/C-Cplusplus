//  Let (x, y) be the coordinates of a student’s house on a 2D plane. There are 2N students
//and we want to pair them into N groups. Let di be the distance between the houses
//of 2 students in group i. Form N groups such that cost = sum of
//di is minimized.
//  Output the minimum cost. Constraints: 1 ≤ N ≤ 8 and 0 ≤ x, y ≤ 1000.
//  Sample input:
// N = 2; Coordinates of the 2N = 4 houses are {1, 1}, {8, 6}, {6, 8}, and {1, 3}.
//DP

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

typedef double db;

int n, k;
db d[20][20], mem[1 << 16];

db match(int b) {
    if (mem[b] > -0.5)
        return mem[b];
    if (b == k)
        return mem[b] = 0;

    db ans = 2000000000;
    int p1, p2;
    for (p1 = 0; p1 < 2 * n; ++p1)
        if (!(b & (1 << p1)))
            break;
    for (p2 = p1 + 1; p2 < 2 * n; ++p2)
        if (!(b & (1 << p2)))
            ans = min(ans, d[p1][p2] + match(b | (1 << p1) | (1 << p2)));

    return mem[b] = ans;
}

int main() {
    int i, j, excpt = 1, x[20], y[20];

    while (scanf("%d", &n), n) {
        for (i = 0; i < 2 * n; ++i)
            scanf("%*s %d %d", &x[i], &y[i]);
        for (j = i + 1; j < 2 * n; ++j)
            d[i][j] = d[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

        for (i = 0; i < (1 << 16); ++i)
            mem[i] = -1;
        k = (1 << (2 * n)) - 1;
        printf("Case %d: %.2lf\n", excpt++, match(0));
    }

    return 0;
}
