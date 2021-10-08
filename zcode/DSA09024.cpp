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

int U, V, E;
vvi adj;
vb  m;
queue<int> q;

void makeAdjacency(int u, int v) {
    adj[u].pb(v);
    //adj[v].pb(u);
}

void bfs(int u) {
    m.resize(V + 1);
    q.push(u);
    m[u] = 1;

    while (!q.empty()) {
        u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto v : adj[u])
            if (!m[v]) {
                m[v] = 1;
                q.push(v);
            }
    }
    m.resize(0);
}
 
int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, u, v;
    cin >> t;
    while (t--) {
        cin >> V >> E >> U;
        adj.resize(V + 1);
        while (E--) {
            cin >> u >> v;
            makeAdjacency(u, v);
        }
        bfs(U);        
        adj.resize(0);
        m.resize(0);
        cout << endl;
    }

    return 0;
}