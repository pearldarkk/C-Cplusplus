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
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
	int t; 
	cin >> t;
	while(t--){
		string str1, str2;
	    string str = ""; 
	    int carry = 0;
		cin >> str1 >> str2;
	    int n1 = str1.length(), n2 = str2.length();
	    if (n1 < n2) {
			swap(str1, str2);
			swap(n1, n2);
		}
	    n2 = n1 - n2;
	    n1--;
	    while(n2>0){
	    	str2 = "0" + str2;
	    	n2--;
		}
		if(str1[0] < str2[0]){
			swap(str1, str2);
		}
		for (int i = n1; i >= 0; --i) {
	        int sum = ((str1[i]-'0') - (str2[i]-'0') - carry);
	        if(sum < 0){
	        	carry = 1;
	        	sum += 10;
			} else carry = 0;
	        str = char(sum%10 + '0') + str;
	    }
	    cout << str << endl;
	}
    return 0;
}