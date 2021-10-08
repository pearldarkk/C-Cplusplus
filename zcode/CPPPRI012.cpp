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

vi prime;

void sieve(int n) {
	bitset<32001> m;
	prime.push_back(2);
	for (int i = 3; i * i <= n; i += 2)
		if (!m[i])
			for (int j = i * i; j <= n; j += i)
				m[j] = 1;
	for (int i = 3; i <= n; i += 2)
		prime.push_back(i);
}

int main() {
	sieve(32000);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (auto p : prime) {
			if (p > n)
				break;
			while (n % p == 0) {
				n /= p;
				--k;
				if (k == 0) {
					cout << p << endl;
					break;
				}
			}
		}
		if (k > 0)
			cout << -1 << endl;
	}
	return 0;
}