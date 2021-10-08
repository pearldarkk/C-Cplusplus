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

int n, m, cnt;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char a[101][101];

void bfs(int u, int v) {
    queue<ii> q;
    q.push({u, v});

    while (!q.empty()) {
        ii node = q.front();
        q.pop();
        int x = node.fi, y = node.se;
        a[x][y] = '.';

        for (int i = 0; i < 8; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx <= 0 || xx > n || yy <= 0 || yy > m)
                continue;
            if (a[xx][yy] == 'W')
                q.push({xx, yy});
        }
    }
}

void Process() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] + 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 'W') {
                ++cnt;
                bfs(i, j);
            }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Process();
    cout << cnt << endl;

    return 0;
}

