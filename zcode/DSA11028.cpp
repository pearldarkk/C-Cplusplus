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

vvi adj;
vi h;

void dfs(int c, int p) { //dfs find height
    for (auto u : adj[c])
        if (u != p) {
            dfs(u, c);
            h[c] = max(h[c], h[u]);
        }
    ++h[c];
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int N, u, v;
        cin >> N;
        adj.resize(N + 1);
        h.resize(N + 1);
        while (--N) {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 0);
        cout << *max_element(h.begin()+1, h.end()) - *min_element(h.begin()+1, h.end()) << endl;
        h.resize(0);
        adj.resize(0);
    }
    return 0;
}