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

string s;
int l[2005][2005];

int LPS() {
    Fill(l, 0);
    int len = s.size();
    for (int i = 0; i < len; ++i)
        l[i][i] = 1;

    for (int i = len - 1; i >= 0; --i)
        for (int j = i; j < len; ++j)
            if (i == j)
                l[i][j] = 1;
            else if (s[i] == s[j])
                if (i == j - 1)
                    l[i][j] = 2;
                else
                    l[i][j] = l[i + 1][j - 1] + 2;
            else
                l[i][j] = max(l[i + 1][j], l[i][j - 1]);
    return l[0][len - 1];
}

int main() {
    //freopen("text.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << LPS() << endl;
    }

    return 0;
}