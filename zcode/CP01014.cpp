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

int main() {
    //freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    map<int, int> Sn, Sm, Sk, S;
    int n, m, k, x;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++Sn[x];
        }
        for (int i = 0; i < m; ++i) {
            cin >> x;
            if (Sn.find(x) != Sn.end())
                if (Sn[x] > Sm[x])
                    ++Sm[x];
        }
        for (int i = 0; i < k; ++i) {
            cin >> x;
            if (Sm.find(x) != Sm.end())
                if (Sm[x] > Sk[x])
                    ++Sk[x];
        }
        if (Sk.size() == 0)
            cout << "NO";
        else
            for (auto it = Sk.begin(); it != Sk.end(); ++it)
                for (int i = 0; i < it->se; ++i)
                    cout << it->fi << ' ';
        cout << endl;

        Sn.clear();
        Sm.clear();
        Sk.clear();
    }

    return 0;
}