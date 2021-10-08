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
#include <stack>
#include <string>
#include <unordered_map>
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

ll cal(ll x, ll y, char c) {
    if (c == '*') return x * y;
    if (c == '/') return x / y;
    if (c == '+') return x + y;
    if (c == '-') return x - y;
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

ll cal(string &s) {
    stack<ll> val;
    reverse(s.begin(), s.end());
    int x, y;
    for (size_t i = 0; i != s.size(); ++i)
        if (prec(s[i])) {
            x = val.top();
            val.pop();
            y = val.top();
            val.pop();
            val.push(cal(x, y, s[i]));
        } else
            val.push(s[i] - 48);

    return val.top();
}

int main() {
    // freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << cal(s) << endl;
    }

    return 0;
}