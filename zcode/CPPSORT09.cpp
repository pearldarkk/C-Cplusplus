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

int bsearch(int k, int l, int r, vi &v) {
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m] == k)
			return m;
		if (v[m] < k)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	int n, k, cnt;
	vi v;
	while (t--) {
		cin >> n >> k;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v);
		cnt = 0;
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				if (v[i] + v[j] == k)
					++cnt;
		cout << cnt << endl;
	}
	return 0;
}