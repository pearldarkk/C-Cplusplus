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

int c[1005], v[1005], n, m;

int knapsack() {
    int k[n][m + 1];
    memset(k, 0, sizeof k);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] <= j)
                k[i][j] = max(k[i - 1][j - v[i]] + c[i], k[i - 1][j]);
            else
                k[i][j] = k[i - 1][j];
        }
    }

    return k[n-1][m];
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
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        cout << knapsack() << endl;
    }
    return 0;
}