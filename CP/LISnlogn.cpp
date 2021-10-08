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
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

vi v;

int Lis() {
    int x = v.size();
    if (x == 0) return 0;

    vi ee(x, 0);
    int len = 1;

    for (int i = 1; i < x; ++i) {
        auto b = ee.begin(), e = ee.begin() + len;
        auto it = lower_bound(b, e, v[i]);

        if (it == ee.begin() + len)
            ee[len++] = v[i];
        else *it = v[i];
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    cout << Lis() << endl;

    return 0;
}
