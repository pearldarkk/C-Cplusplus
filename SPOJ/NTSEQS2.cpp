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
#define fill(a, x) memset(a, x, sizeof a)
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vi v(n);
    vector<bool> f(s);
    for (int &it : v) cin >> it;

    f[0] = 1, f[s] = 0;
    for (int i = 1; i <= n; ++i)
        for (int t = s; t >= v[i]; --t)
            if (f[t] == 0 && f[t - v[i]] == 1)
                f[t] = 1;
    if (f[s])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}