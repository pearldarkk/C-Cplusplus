#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const ll m = 1000000007;
ll modExp(ll base, ll exp, ll m) {
    ll r = 1;
    base = base % m;

    while (exp) {
        if (exp & 1)
            r = (r * base) % m;
        exp >>= 1;
        base = (base * base) % m;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << modExp(n, k, m) << endl;
    }

    return 0;
}
