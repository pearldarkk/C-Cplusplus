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


int main() {
	int t;
	cin >> t;
	int n;
	vi v;
	while (t--) {
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v);
		v.pb(0);
		int j = 1;
		for (auto i : v) 
			if (j == i)
				++j;
			else if (j < i) {
				cout << j;
				break;
			}
		for (int i  )
	}
	return 0;
}