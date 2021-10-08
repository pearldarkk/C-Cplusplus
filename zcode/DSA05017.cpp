DSA07023 #include<algorithm>
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

int n, a[100];

int dp(int n) {
    int il[n];
    int dl[n];
    for (int i = 0; i < n; ++i) {
        il[i] = a[i];
        dl[i] = a[i];
    }
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j] && il[i] < il[j] + a[i])
                il[i] = il[j] + a[i];

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (a[i] > a[j] && dl[i] < dl[j] + a[i])
                dl[i] = dl[j] + a[i];

    int r = -INF;
    for (int i = 0; i < n; ++i)
        r = max(il[i] + dl[i] - a[i], r);
    return r;
}

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << dp(n) << endl;
    }
    return 0;
}