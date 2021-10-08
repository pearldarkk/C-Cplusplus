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
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), x)
#define sort(v) sort(v.begin(), v.end())
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;

int n, m, u;
vvi e;
vb visited;

void dfs(int node) {
    cout << node << ' ';
    visited[node] = 1;
    for (int i : e[node])
        if (!visited[i])
            dfs(i);
}

void in() {
    cin >> n >> m >> u;
    e.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].pb(y);
        e[y].pb(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        in();
        dfs(u);
        e.clear();
        visited.clear();
    }
    return 0;
}
