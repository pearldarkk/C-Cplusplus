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
#define fill(v, x) memset(v, x, sizeof v)
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

    int n, r = 1;
    cin >> n;
    vi v(n), f(n);
    for (int &it : v)
        cin >> it;

    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = i - 1; j >= 0; --j)
            if (v[i] > v[j])
                f[i] = max(f[i], f[j] + 1);
        r = max(r, f[i]);
    }
    cout << r << endl;

    return 0;
}