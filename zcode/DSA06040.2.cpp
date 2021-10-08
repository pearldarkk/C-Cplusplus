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
#include <unordered_set>
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
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n[3];
    vector<vector<ll>> vv;
    cin >> t;
    while (t--) {
        int flag = 0;
        vv.resize(3);
        for (int i = 0; i < 3; ++i) {
            cin >> n[i];
            vv[i].resize(n[i]);
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n[i]; ++j)
                cin >> vv[i][j];

        for (int i = 0, j = 0, k = 0; i < n[0] && j < n[1] && k < n[2];) {
            ll m = max(vv[0][i], max(vv[1][j], vv[2][k]));
            if (vv[0][i] == m && vv[1][j] == m && m == vv[2][k]) {
                cout << m << ' ';
                ++i, ++j, ++k;
                flag = 1;
            } else {
                while (vv[0][i] < m)
                    ++i;
                while (vv[1][j] < m) 
                    ++j;
                while (vv[2][k] < m)
                    ++k;
            }
        }
        if (!flag)
            cout << -1;
        cout << endl;
        vv.clear();
    }

    return 0;
}