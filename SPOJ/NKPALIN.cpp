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
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), 0)
#define sort(v) sort(v.begin(), v.end())
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

string s, ans;
int f[2005][2005];
int len;

void trace(int l, int r) {
    if (l > r) return;
    if (l == r) {
        cout << s[l];
        return;
    }
    if (s[l] == s[r]) {
        cout << s[l];
        trace(l + 1, r - 1);
        cout << s[r];
        return;
    }
    if (f[l][r] == f[l + 1][r]) trace(l + 1, r);
    else trace(l, r - 1);
}

int dp() {
    len = s.size();
    for (int i = len - 1; i >= 0; --i)
        for (int j = i; j < len; ++j)
            if (i == j)
                f[i][j] = 1;
            else if (s[i] == s[j])
                if (i == j - 1)
                    f[i][j] = 2;
                else
                    f[i][j] = f[i + 1][j - 1] + 2;
            else
                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
    return f[0][len - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    dp();
    ans.resize(f[0][len - 1]);
    trace(0, len - 1);
    cout << ans << endl;

    return 0;
}