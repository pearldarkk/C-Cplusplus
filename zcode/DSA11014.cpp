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

int s;

node *find(node *n, int k) {
    if (!n)
        return NULL;
    if (n->d == k)
        return n;
    node *tmp = find(n->l, k);
    if (!tmp)
        tmp = find(n->r, k);
    return tmp;
}

void ins(node *n, int u, int v, char p) {
    node *tmp = find(n, u);
    if (p == 'R')
        tmp->r = new node(v);
    else
        tmp->l = new node(v);
}

void rsum(node *n, bool r) {
    if (!n)
        return;
    if (!n->l && !n->r && r)
        s += n->d;
    rsum(n->l, 0);
    rsum(n->r, 1);
}

int main() {
    // freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        node *R = NULL;
        int n, u, v;
        char p;
        cin >> n;
        while (n--) {
            cin >> u >> v >> p;
            if (!R)
                R = new node(u);
            ins(R, u, v, p);
        }
        s = 0;
        rsum(R, 0);
        cout << s << endl;
    }

    return 0;
}