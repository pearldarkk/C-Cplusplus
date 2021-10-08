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

int bsearch(vi &v, int l, int r, int k) {
    int m; 
    while (l <= r) {
        m = l + (r - l) / 2;
        if (v[m] == k)
            return m;
        if (v[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k;
    vi v;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        v.resize(n);
        int d = 0; 
        for (int &i : v) 
            cin >> i;
        d = bsearch(v, 0, n - 1, k);
        if (d == -1)
            cout << d << endl;
        else {
            int d1 = d, d2 = d;
            while (v[d1 - 1] == v[d] && d1 >= 0)
                --d1;
            while (v[d2 + 1] == v[d] && d2 < n)
                ++d2;
            cout << d2 - d1 + 1 << endl;
        }
    }

    return 0;
}