#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vi v(n);
        map <int, int> mp;
        for (int i = 0; i != n; ++i)
        {
            cin >> v[i];
            if (mp.find(v[i]) != mp.end())
                cout << mp[v[i]] + 1 << ' ' << i + 1 << endl;
            mp[m - v[i]] = i; 
        }
    }

    return 0;
}
