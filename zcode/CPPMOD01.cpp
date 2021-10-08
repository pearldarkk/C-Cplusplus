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
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), x)
#define sort(v) sort(v.begin(), v.end())
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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

ll exp(ll b, ll e, ll m) {
	int r = 1;
	b %= m;
	while (e) {
		if (e & 1)
			r = (r * b) % m;
		b = (b * b) % m;
		e >>= 1;
	}
	return r % m;
}

int main() {
	int t;
	cin >> t;
	ll x, y, p;
	while (t--) {
		cin >> x >> y >> p;
		cout << exp(x, y, p) << endl;
	}
	return 0;
}