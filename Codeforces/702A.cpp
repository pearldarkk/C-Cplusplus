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
#define ll long long
#define ull unsigned long long
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int n;
vi v;

int lis() {
    if (n == 0) return 0;

    vi ee(n, 0);
    int len = 1;

    for (int x : v) {
        auto b = ee.begin(), e = ee.begin() + len;
        auto it = lower_bound(b, e, x);
        if (it == ee.begin() + len)
            ee[len++] = x;
        else *it = x;
    }
    return len;
}

int lisubarray() {
    int r = 1, cnt = 1;
    v.pb(0);
    for (int i = 1; i <= n; ++i) 
        if (v[i] > v[i - 1])
            ++cnt;
        else {
            if (r < cnt) 
                r = cnt;
            cnt = 1;
        }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << lisubarray();

    return 0;
}

