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

struct node {
    int d;
    node *l, *r;
    node(int d) {
        this->d = d;
        l = r = NULL;
    }
};

int pi, n;
vi p;
unordered_map<int, int> m;

node *build(int l, int h) {
    if (l > h)
        return NULL;

    int cur = p[pi++];
    node *t = new node(cur);
    if (l == h)
        return t;

    int ii = m[cur];
    t->l = build(l, ii - 1);
    t->r = build(ii + 1, h);
    return t;
}

void postOrd(node *n) {
    if (!n)
        return;
    postOrd(n->l);
    postOrd(n->r);
    cout << n->d << ' ';
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, x;
    cin >> t;
    while (t--) {
        cin >> n;
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> x;
            m[x] = i;
        }
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        pi = 0;
        postOrd(build(0, n - 1));
        cout << endl;
        m.clear();
    }
    return 0;
}