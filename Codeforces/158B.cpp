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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, i1 = 0, i2 = 0, i3 = 0, i4 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        switch (x) {
            case 1:
                ++i1;
                break;
            case 2:
                ++i2;
                break;
            case 3:
                ++i3;
                break;
            case 4:
                ++i4;
                break;
            default:
                break;
        }
    }

    x = i4;
    x += i3; i1 = max(0, i1 - i3);
    x += (i2 / 2); i2 %= 2;
    if (i2) ++x, i1 = max(0, i1 - 2);
    if (i1) x += (i1 + 3) / 4;
    cout << x << endl;
    return 0;
}