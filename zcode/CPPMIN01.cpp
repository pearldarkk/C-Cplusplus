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

string max(int m, int s) {
    string r;
    while (s > 9) {
        r = char(9 + '0') + r;
        s -= 9;
        --m;
        if (m < 1)
            return NULL;
    }
    if (m < 1)
        return NULL;
    if (m >= 1) {
        if (m > 1) {
            r = char(s - 1 + '0') + r;
            s = 1;
            --m;
            for (int i = 0; i < n - s.size(); ++i)
                r = r + '0';
            r = r + 
        }
        if 
    }
    for (int i = 0; i < n - s.size(); ++i)
        r = r + '0';
    r
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, s, cnt;
    cin >> m >> s;
    --m, --s;
    string n;
    while (s > 9) {
        n = char(9 + '0') + n;
        s -= 9;
        --m;
        if (!m)
    }

    return 0;
}

