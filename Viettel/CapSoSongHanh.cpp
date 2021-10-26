#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
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

struct VHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for (auto &x : V)
            hash ^= x + (hash >> 3) + (x << 2);
        return hash;
    }
};

unordered_map<vector<int>, int, VHasher> m;
vi v[(int)1e6 + 1];

void precompute() {
    for (int i = 2; i <= 1e6; ++i)
        if (v[i].empty())
            for (int j = i; j <= 1e6; j += i)
                v[j].push_back(i);
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
    while (n--) {
        int a, b;
        cin >> a >> b;
        ll r = 0;
        for (int i = a; i <= b; ++i)
            r += m[v[i]]++;
        cout << r << "\n";
        m.clear();

    }
    return 0;
}