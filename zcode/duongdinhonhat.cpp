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

int  c[1000][1000];
int n, m;

int min() {
    //c[0][0] = 0;
    for (int i = 1; i <n; ++i)
        c[i][0] += c[i-1][0];
    for (int j = 1; j < m; ++j)
        c[0][j] += c[0][j-1];
    for (int i = 1; i <n; ++i) 
        for (int j = 1; j < m; ++j)
            c[i][j] += min(c[i-1][j-1], min(c[i-1][j], c[i][j-1]));
    return c[n-1][m-1];
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
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];
        cout << min() << endl;
    }

   return 0;
}