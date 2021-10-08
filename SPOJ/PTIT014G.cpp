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

#define For(i, a, b) for (int i = a; i < b; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define iFor(i, a, b) for (int i = a; i >= b; --i)
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
typedef vector<ll> vll;
typedef tuple<ll, ll> tll;
typedef tuple<ll, ll, ll> tlll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[10][10];
    int p[10];
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i, 1, n)
        FOR(j, 1, n)
        cin >> a[i][j];

        FOR(i, 1, n)
        p[i] = i;
        ll best = LINF;
        do {
            ll v = 0;
            FOR(i, 1, n)
            v += a[i][p[i]];
            if (v < best) best = v;
        } while (next_permutation(p + 1, p + n + 1));
        cout << best << endl;
    }

    return 0;
}
