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

vi v;
int n;

int minSwap() {
    int r = 0;
    vi tmp = v;
    map<int, int> m;
    sort(tmp.begin(), tmp.end(), greater<int>());
    for (int i = 0; i < n; ++i)
        m[v[i]] = i;
    for (int i = 0; i < n; ++i)
        if (v[i] != tmp[i]) {
            ++r;
            int init = v[i];
            swap(v[i], v[m[tmp[i]]]);
            m[init] = m[tmp[i]];
            m[tmp[i]] = i;
        }
    return r;
}

int main() {
    // freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    string s;
    cin >> n;
    int out = 1, cnt = 0, in = 0;
    for (int p = 0; p < 2 * n; ++p) {
        cin >> s;
        if (s == "in") {
            cin >> x;
            v.push_back(x);
            ++in;
        } else if (s == "out")
            if (in < n) {
                if (v.back() != out) {
                    ++cnt;
                    int i;
                    for (i = 0; i < v.size(); ++i)
                        if (out == v[i])
                            break;
                    swap(v[i], v.back());
                }
                v.pop_back();
                ++out;
            } else
                cnt += minSwap();
    }
    cout << cnt;
    return 0;
}