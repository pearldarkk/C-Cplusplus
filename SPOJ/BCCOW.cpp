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

#define EL printf("\n")
#define fill(a, x) memset(a, x, sizeof a)
#define sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
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

int c, n, f[20][5001], w[20];

int dp() {
    FOR(i, 0, n)
        FOR(j, 0, c)
            if (i == 0 || j == 0) f[i][j] = 0;
            else f[i][j] = max(f[i - 1][j], j >= w[i - 1] ? w[i - 1] + f[i-1][j - w[i - 1]] : 0);
    
    return f[n][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n;
    For(i, 0, n)
        cin >> w[i];
    cout << dp() << endl;

    return 0;
}