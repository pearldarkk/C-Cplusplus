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
#include <unordered_map>
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
unordered_map<int, int> p;

int find(int u) {
    if (p[u] == u)
        return u;
    return find(p[u]);
}

inline void Union(int u, int v) { p[find(u)] = find(v); }

bool cycle() {
    for (int v = 1; v <= V; ++v)
        p[v] = v;
    for (int u = 1; u <= V; ++u)
        for (auto v : adj[u]) {
            if (find(u) == find(v))
                return 1;
            else
                Union(find(u), find(v));
        }
    return false;
}

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, u, v;
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
        if (cycle())
            pY;
        else
            pN;
        adj.resize(0);
        m.resize(0);
        p.clear();
    }

    return 0;
}