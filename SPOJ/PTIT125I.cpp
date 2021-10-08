#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack<char> check;
    stack<char> r;
    for (int i = 0; i < n; ++i) {
        while (k > 0 && check.size() && check.top() < s[i]) {
            check.pop();
            --k;
        }
        check.push(s[i]);
    }

    for (int i = 0; i < k; ++i) 
        check.pop();
    while (!check.empty()) {
        r.push(check.top());
        check.pop();
    }
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}
