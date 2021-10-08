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

vi p;
int a, b;

void sieve(int n) {
    bitset<32000> m;
    m[0] = m[1] = 1;
    for (int i = 3; i < n; i += 2)
        if (!m[i])
            for (int j = i * i; j < n; j += i)
                m[j] = 1;
    p.pb(2);
    for (int i = 3; i < n; i += 2)
        if (!m[i])
            p.pb(i);
}

bool prime(int n) {
    if (n < 2)
        return 0;
    for (int i = 0; p[i] * p[i] <= n; ++i)
        if (n % p[i] == 0)
            return 0;
    return 1;
}

int sum(int n) {
    int r = 0;
    while (n) {
        r += n % 10;
        n /= 10;
    }
    return r;
}

bool dig(int n) {
    while (n) {
        int x = n % 10;
        if (x != 2 && x != 5 && x != 7 && x != 3)
            return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    // freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve(32000);
    int t;
    cin >> t;
    int a, b, cnt;
    while (t--) {
        cnt = 0;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        for (int i = a; i <= b; ++i)
            if (dig(i) && prime(sum(i)) && prime(i))
                ++cnt;
        cout << cnt << endl;
    }

    return 0;
}