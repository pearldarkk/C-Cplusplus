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

vs grayGen(int n) {
    if (n == 0)
        return {"0"};
    if (n == 1)
        return {"0", "1"};
    vs temp = grayGen(n - 1);
    vs r;
    for (int i = 0; i < temp.size(); ++i)
        r.pb("0" + temp[i]);
    for (int i = temp.size() - 1; i >= 0; --i)
        r.pb("1" + temp[i]);
    return r;
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vs v;
        v = grayGen(n);
        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        cout << endl;
    }
    return 0;
}