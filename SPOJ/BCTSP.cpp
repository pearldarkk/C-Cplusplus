#include <algorithm>
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
#define fill(a, x) memset(a, x, sizeof a)
#define sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define For(i, a, b) for (int i = a; i < b; ++i)
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define iFor(i, a, b) for (int i = a; i >= b; --i)
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int n, a[16][16];
bool travelled[16]{false};
int r = INF;

bool check() {
    FOR(i, 1, n)
        if (!travelled[i])
            return 0;
    return 1;
}

void Try(int u, int cnt) {
    if (cnt < r) 
        if (check()) 
            r = min(r, cnt + a[1][u]);
        else {
            FOR(i, 1, n)
                if (!travelled[i] && u != i) {
                    travelled[i] = 1;
                    Try(i, cnt + a[u][i]);
                    travelled[i] = 0;
                }
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> a[i][j];

    travelled[1] = 1;
    Try(1, 0);
    cout << r << endl;
    
    return 0;
}