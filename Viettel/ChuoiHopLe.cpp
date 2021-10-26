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

long m[35] = {0};
string s;

bool check() {
    int min, max;
    min = INF, max = 0;
    for (auto &c : s) 
        ++m[c - 'a'];
    
    for (int i = 0; i < 26; ++i)
        if (m[i] != 0) {
            min = min < m[i - 'a'] ? min : m[i - 'a'];
            max = max > m[i - 'a'] ? max : m[i - 'a'];
        }
    if (min == max)
        return true;
    for (int i = 0; i < 26; ++i)
        if (m[i] < max) {
            s.erase(s.find(i + 'a'), 1);
            break;
        }
    memset(m, 0, sizeof m);
    min = INF, max = 0;
    for (auto &c : s)
        ++m[c - 'a'];

    for (int i = 0; i < 26; ++i)
        if (m[i] != 0) {
            min = min < m[i - 'a'] ? min : m[i - 'a'];
            max = max > m[i - 'a'] ? max : m[i - 'a'];
        }
    if (min == max)
        return true;
    return false;
}

int main() {
    freopen("text.inp", "r", stdin);
    // freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    if (check())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}