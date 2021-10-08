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
#define i64 long long
#define i64_t unsigned long long
typedef pair<i64, i64> ii;
typedef vector<bool> vb;
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

int n;

void gen(vi v) {
    for (i64 &x : v)
        if (x % n == 0) {
            cout << x << endl;
            return;
        }
    vi tmp;
    for (i64 &x : v) {
        tmp.pb(x * 10);
        tmp.pb(x * 10 + 9);
    }
    gen(tmp);
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
        cin >> n;
        gen({9});
    }
    return 0;
}
