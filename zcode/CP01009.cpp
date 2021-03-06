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

bool cusSort(const ii &a, const ii &b) {
    if (a.fi == b.fi)
        return a.se < b.se;
    return a.fi > b.fi;
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    vi vn;
    vector<ii> v;
    map<int, int> m, pos;
    cin >> t;
    while (t--) {
        cin >> n;
        vn.resize(n);
        for (auto it = vn.begin(); it != vn.end(); ++it) {
            cin >> *it;
            ++m[*it]; //frequences
            auto itp = pos.find(*it);
            if (itp == pos.end())
                pos[*it] = it - vn.begin(); //first pos of frequence
        }
        for (auto it = m.begin(); it != m.end(); ++it)          
            v.pb({it->se, pos[it->fi]});
        sort(v.begin(), v.end(), cusSort);
        for (auto &it : v) 
            for (int i = it.fi; i > 0; --i)
                cout << vn[it.se] << ' ';
        cout << endl;
        pos.clear();
        m.clear();
        v.clear();
    }

    return 0;
}