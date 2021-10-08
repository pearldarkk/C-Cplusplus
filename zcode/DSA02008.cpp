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

int n, b[15][15], a[15][15], k;
int cnt, sum;
vb r;

bool safe(int r, int c) {
    int i, j;

    for (i = 0; i < c; ++i)
        if (b[r][i])
            return false;

    for (i = r, j = c; i >= 0 && j >= 0; --i, --j)
        if (b[i][j])
            return false;

    for (i = r, j = c; i < n && j >= 0; ++i, --j)
        if (b[i][j])
            return false;

    return true;
}

bool pick(int c) {
    if (c == n)
        if (sum == k) {
            ++cnt;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (b[i][j])
                        r.pb(j);
            return true;
        } else
            return false;

    bool res = 0;
    for (int i = 0; i < n; ++i) {
        if (safe(i, c)) {
            b[i][c] = 1;
            sum += a[i][c];
            res = pick(c + 1) || res;
            b[i][c] = 0;
            sum -= a[i][c];
        }
    }

    return res;
}

void sol() {
    if (pick(0) == false)
        return;

    return;
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    sol();
    cout << cnt << endl;
    for (int i = 0; i < cnt * n; ++i)
        if (i % n == 0) {
            cout << endl;
            continue;
        } else
            cout << r[i] << ' ';

    return 0;
}