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
#define sqr(x) ((x) * (x))
#define pb push_back
#define mt make_tuple
#define x first
#define y second
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

typedef pair<double, double> point;
typedef pair<double, int> rec;

set<rec> S;
point p[100000];
int n;

double dist(const point &a, const point &b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        sort(p, p + n);

        int j = 0;
        double ans = 1e9;

        for (int i = 0; i < n; ++i) {
            while (p[i].x - p[j].x > ans) {
                S.erase(S.find({p[j].y, j}));
                ++j;
            }
            set<rec>::iterator it = S.lower_bound({p[i].y - ans, 0});
            set<rec>::iterator ed = S.upper_bound({p[i].y + ans, 0});

            while (it != ed) {
                ans = min(ans, dist(p[i], p[it->y]));
                ++it;
            }
            S.insert({p[i].y, i});
        }

        cout << setprecision(6) << fixed << ans << endl;
    }

    return 0;
}