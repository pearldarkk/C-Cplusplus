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

int n, r = INF, p[11];
string s[11];
bool used[11]{0}, pos['Z' + 1];

void Update() {
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        fill(pos, 0);
        for (int j = 0; j < s[p[i]].size(); ++j)
            ++pos[s[p[i]][j]];
        for (int j = 0; j < s[p[i + 1]].size(); ++j)
            if (pos[s[p[i + 1]][j]])
                ++cnt;
    }
    if (cnt < r) r = cnt;
}

void Try(int x) {
    for (int i = 1; i <= n; ++i)
        if (!used[i]) {
            p[x] = i;
            used[i] = 1;
            if (x == n)
                Update();
            else
                Try(x + 1);
            used[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    Try(1);
    cout << r << endl;
    return 0;
}