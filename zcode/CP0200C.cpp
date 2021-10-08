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

int n;
vi v, M, m;

void MSubArr() {
    M.resize(n);
    M[0] = v[0];
    for (int i = 1; i < n; ++i)
        M[i] = max(M[i - 1], v[i]);
}

void mSubArr() {
    m.resize(n);
    m[n - 1] = v[n - 1];
    for (int i = n - 2; i > 0; --i)
        m[i] = min(m[i + 1], v[i]);
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, cnt;
    vi pos;
    cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n;
        v.resize(n);
        for (auto &x : v)
            cin >> x;
        MSubArr(), mSubArr();
        for (int i = 0; i < n - 1; ++i)
            if (M[i] <= m[i + 1]) {
                ++cnt;
                pos.pb(i + 1);
            }
        cout << cnt << endl;
        for (auto x : pos)
            cout << x << ' ';
        cout << endl;
        pos.clear();
        M.clear();
        m.clear();
    }
    
    return 0;
}