#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;


long fmin(int x) {
    int dig = 1;
    int s = 0;
    while (x) {
        if (x % 10 == 6) 
            s += dig;
        x /= 10;
        dig *= 10;
    }
    return s;
}

long fmax(int x) {
    int dig = 1;
    int s = 0;
    while (x) {
        if (x % 10 == 5) 
            s += dig;
        x /= 10;
        dig *= 10;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    int sum = a + b;
    cout << sum - fmin(a) - fmin(b) << ' ' << sum + fmax(a) + fmax(b) << endl;

    return 0;
}
