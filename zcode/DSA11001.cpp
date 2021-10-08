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
    char d;
    struct node *l, *r;
    node(int d) {
        this->d = d;
        l = r = NULL;
    }
};

string s;

bool optor(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

node *postfix2tree() {
    stack<node *> S;
    node *t, *x, *y;
    for (char c : s) {
        if (!optor(c)) {
            t = new node(c);
            S.push(t);
        }
        else {
            t = new node(c);
            x = S.top();
            S.pop();
            y = S.top();
            S.pop();
            t->r = x;
            t->l = y;
            S.push(t);
        }
    }
    t = S.top();
    S.pop();
    return t;
}

void inOrd(node *n) {
    if (n) {
        inOrd(n->l);
        cout << n->d;
        inOrd(n->r);
    }
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        node *ex = postfix2tree();
        inOrd(ex);
        cout << endl;
    }
    return 0;
}