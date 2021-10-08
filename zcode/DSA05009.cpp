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
#define pn printf("NO\n")
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), x)
#define Sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define InF 1e9
#define LInF 1e18
#define ld long double
#define ll long long
#define ull unsigned long long
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

vi v;
int s, cnt, n;

int l[105];

void subs() {
    l[0] = 1, l[s] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = s; j >= v[i]; --j)
            if (l[j] == 0 && l[j - v[i]] == 1)
                l[j] = 1;
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        s = 0;
        cin >> n;
        v.resize(n);
        for (auto &x : v) {
            cin >> x;
            s += x;
        }
        bool r = 0;
        if (s % 2 == 0) {
            memset(l, 0, sizeof l);
            subs();
            r = l[s/2];
        }
        if (r != 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}