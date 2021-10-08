#include <algorithm>
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

#define For(i, a, b) for (int i = a; i < b; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define iFor(i, a, b) for (int i = a; i >= b; --i)
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef tuple<ll, ll> tll;
typedef tuple<ll, ll, ll> tlll;

int w[100], v[100], n, m;

int dp() {
    int k[n + 1][m + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (w[i - 1] <= j)
                k[i][j] = max(v[i - 1] + k[i - 1][j - w[i - 1]], k[i - 1][j]);
            else
                k[i][j] = k[i - 1][j];
        }
    }

    return k[n][m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    cout << dp() << endl;

    return 0;
}
