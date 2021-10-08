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

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    map<int, int> m;
    string s;
    while (t--) {
        cin >> n >> s;
        for (char &c : s) 
            switch (c) {
                case '2':
                case '3':
                case '5':
                case '7':
                    ++m[c];
                    break;
                case '4':
                    ++m['2'];
                    ++m['2'];
                    ++m['3'];
                    break;
                case '6':
                    ++m['5'];
                    ++m['3'];
                    break;
                case '8':
                    ++m['7'];
                    ++m['2'];
                    ++m['2'];
                    ++m['2'];
                    break;
                case '9':
                    ++m['7'];
                    ++m['3'];
                    ++m['3'];
                    ++m['2'];
                    break;
                default:
                    break;
            }
        for (int i = '9'; i >= '2'; --i)
            while (m[i]) {
                cout << char(i);
                --m[i];
            }
        cout << endl;
    }
    
    return 0;
}