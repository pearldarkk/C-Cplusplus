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

bool sortOp(const ii &a, const ii &b) {
    return a.se < b.se;
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vii a;
    int t, n, cnt, busyTil;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (auto &&[b, e] : a)
            cin >> b;
        for (auto &&[b, e] : a)
            cin >> e;
        cnt = 0;
        sort(a.begin(), a.end(), sortOp);
        busyTil = a[0].fi;
        for (int i = 0; i < n; ++i)
            if (a[i].fi >= busyTil) {
                busyTil = a[i].se;
                ++cnt;
            }
        cout << cnt << endl;
    }
    
    return 0;
}