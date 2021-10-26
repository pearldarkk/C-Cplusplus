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

bool m[10];
string a[505];

void precompute() {
    a[0] = '0';
    string tmp;
    bool greater;
    for (int k = 1; k < 500; ++k) {
        memset(m, 0, 10);
        tmp = a[k - 1];
        for (auto &c : tmp)
            if (!m[c - '0'])
                m[c - '0'] = 1;
        greater = 0;
        for (int j = tmp[0] - '0' + 1; j < 10; ++j)
            if (!m[j]) {
                tmp[0] = char(j + '0');
                greater = 1;
                break;
            }
        if (greater == 0)
            for (int j = 1; j < 10; ++j)
                if (!m[j]) {
                    tmp = char(j + '0') + tmp;
                    break;
                }
        int len = greater == 1 ? tmp.length() : tmp.length() + 1;
        for (int i = 1; i < len; ++i)
            for (int j = 0; j < 10; ++j)
                if (!m[j]) {
                    tmp[i] = char(j + '0');
                    break;
                }
        a[k] = tmp;
    }
}

int main() {
    // freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute();
    int n;
    cin >> n;
    cout << a[n];

    return 0;
}