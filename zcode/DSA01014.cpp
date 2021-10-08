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
#include <numeric>
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

long k, s, n, r;
vi v;

void gen(int pos) {
    for (int i = v[pos - 1] + 1; i <= n - k + pos + 1; ++i) {
        v[pos] = i;
        if (pos == k - 1) {
            long sum = 0;
            for (int &x : v)
                sum += x;
            if (sum == s)
                ++r;
        } else
            gen(pos + 1);
    }
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0)
            break;
        r = 0;
        v.resize(k);
        gen(0);
        cout << r << endl;
        v.clear();
    }
    return 0;
}