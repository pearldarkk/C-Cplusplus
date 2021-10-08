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

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int f0 = 0, f1 = 1, f2;
	for (int i = 2; i <= n; ++i) {
		f2 = (f0 + f1) % MOD;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << fib(n) << endl;
	}
	return 0;
}