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
vb visited;
vvi e;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for(int i: e[v])
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
    }
}

int in() {
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
        bfs(u);
        EL;
        e.clear();
        visited.clear();
    }

    return 0;
}
