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

int n, c[1001][1001], m[1001];

int solve() {
    FOR(i, 1, n)
        m[i] = 1;
    int r = 0;
    int d = 1, u = 1;
    m[1] = 0;

    while (d != n) {
        ll minc = INF;
        ll iv;

        FOR(v, 1, n) 
            if (m[v] && c[u][v])
                if (c[u][v] < minc) {
                    minc = c[u][v];
                    iv = v;
                }
        r += c[u][iv];
        m[iv] = false;
        u = iv;
        ++d;
    }
    r += c[u][1];
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> c[i][j];
    cout << solve() << endl;

    return 0;
}