#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EL printf("\n")
#define pY printf("YES\n")
#define pN printf("NO\n")
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), x)
#define Sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define ld long double
#define ll long long
#define ull unsigned long long
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
ull fib(int n) {
    ull f[2][2] = {{1, 1}, {1, 0}}, r[2][2] = {{1, 0}, {0, 1}},
        tmp[2][2] = {{0, 0}, {0, 0}};
    int i, j, k;
    if (n == -1)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    while (n) {
        if (n & 1) {
            memset(tmp, 0, sizeof tmp);
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    for (k = 0; k < 2; k++)
                        tmp[i][j] += (r[i][k] * f[k][j]) % MOD;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    r[i][j] = tmp[i][j] % MOD;
        }
        memset(tmp, 0, sizeof tmp);
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                for (k = 0; k < 2; k++)
                    tmp[i][j] += (f[i][k] * f[k][j]) % MOD;
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                f[i][j] = tmp[i][j] % MOD;
        n = n >> 1;
    }
    return r[0][0];
}


int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << fib(n - 1) << endl;
    }
    return 0;
}