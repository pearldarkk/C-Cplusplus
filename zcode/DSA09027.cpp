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
#include <stack>
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

int U, V, E, cur;
vvi adj;
vi c;
vb m;
queue<int> q;

void dfs(int u) {
    m[u] = 1;
    c[u] = cur;
    for (auto v : adj[u])
        if (!m[v])
            dfs(v);
}

int main() {
    // /freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, u, v, q;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        adj.resize(V + 1);
        while (E--) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        m.resize(V + 1);
        c.resize(V + 1, -1);
        cur = 0;
        for (int u = 1; u <= V; ++u)
            if (!m[u]) {
                ++cur;
                dfs(u);
            }
        cin >> q;
        while (q--) {
            cin >> u >> v;
            if (c[u] != c[v])
                pN;
            else
                pY;
        }
        adj.resize(0);
        m.resize(0);
        c.resize(0);
    }

    return 0;
}