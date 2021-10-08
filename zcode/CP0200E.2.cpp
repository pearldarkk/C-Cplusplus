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

// Lucas sequence https://en.wikipedia.org/wiki/Lucas_sequence
ll fib(int n) {
    ll a, b, p, q;
    a = q = 1;
    b = p = 0;
    while (n) {
        if (n & 1) {
            ll aq = a * q % MOD;
            a = b * q + aq + a * p;
            a %= MOD;
            b = b * p + aq;
            b %= MOD;
            --n;
        } else {
            ll qq = q * q % MOD;
            q = 2 * p * q + qq;
            q %= MOD;
            p = p * p + qq;
            p %= MOD;
            n >>= 1;
        }
    }
    return b;
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << fib(n) << endl;
    }
    
    return 0;
}