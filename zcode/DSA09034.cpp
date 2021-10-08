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
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int r, c, cnt;
const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
char g[101][101];
bool m[101][101];

void dfs(int u, int v) {
    m[u][v] = 1;
    for (int i = 0; i < 8; ++i) {
        int x = u + dx[i], y = v + dy[i];
        if (x <= 0 || x > r || y <= 0 || y > c)
            continue;
        if (!m[x][y] && g[x][y] == 'W')
            dfs(x, y);
    }
}

void in() {

}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Fill(m, 0);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        cin >> g[i] + 1;

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (!m[i][j] && g[i][j] == 'W') {
                ++cnt;
                dfs(i, j);
            }
    cout << cnt << endl;
    return 0;
}
