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

ull a[10][10];
int n, m;

void solve() {
    ull r[n][n], tmp[n][n];
    memset(r, 0, sizeof r);
    int i, j, k;
    for (i = 0; i < n; ++i)
        r[i][i] = 1;
    while (m) {
        if (m & 1) {
            memset(tmp, 0, sizeof tmp);
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    for (k = 0; k < n; k++)
                        tmp[i][j] += (r[i][k] * a[k][j]) % MOD;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    r[i][j] = tmp[i][j] % MOD;
        }
        memset(tmp, 0, sizeof tmp);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    tmp[i][j] += (a[i][k] * a[k][j]) % MOD;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = tmp[i][j] % MOD;
        m >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << r[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        solve();
    }
    return 0;
}