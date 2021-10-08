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

void egyptFract(ll n, ll d) {
    if (!n || !d)
        return;
    if (d%n == 0){
        cout << "1/" << d/n;
        return;
    }
    if (n % d == 0){
        cout << n/d;
        return;
    }
    if (n > d) {
        cout << n/d << " + ";
        egyptFract(n % d, d);
        return;
    }
    int N = d/n + 1;
    cout << "1/" << N << " + ";
    egyptFract(n*N-d, d*N);
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    ll d, n;
    while (t--) {
        cin >> d >> n;
        egyptFract(d, n);
        cout << endl;
    }
    
    return 0;
}