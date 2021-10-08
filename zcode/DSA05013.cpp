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
#define i64 long long
#define i64_t unsigned long long
typedef pair<i64, i64> ii;
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

int n, k;
vi v;

i64 dp(int n, int k) {
    v.pb(1);
    i64 s = 0;
    for (int i = 1; i <= k; ++i) {
        s = (s + v.back()) % MOD;
        v.pb(s);
    }

    if (n <= k)
        return v[n];

    for (int i = k + 1; i <= n; ++i)
        v.pb((2 * v.back() % MOD - v[i - k - 1] % MOD + MOD) % MOD);
    return v.back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << dp(n, k) << endl;
        v.clear();
    }

    return 0;
}