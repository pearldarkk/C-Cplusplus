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

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    map<int, int> m;
    int n, c, x;
    cin >> t;
    while (t--) {
        cin >> n;
        c = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++m[x];
        }
        for (map<int, int>::iterator it = m.begin(); it != prev(m.end()); ++it)
            for (map<int, int>::iterator jt = next(it, 1); jt != m.end();
                 ++jt) {
                ll x = it->fi, y = jt->fi;
                x *= x, y *= y;
                ll z = sqrt(x + y);
                if (z * z != y + x)
                    continue;
                if (m[z] == 0)
                    continue;
                if (z == x && it->fi == 1)
                    continue;
                if (z == y && jt->fi == 1)
                    continue;
                c = 1;
            }
        if (c)
            pY;
        else
            pN;
        m.clear();
    }
    return 0;
}