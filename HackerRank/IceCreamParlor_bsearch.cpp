#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

bool bsearch(vii& v, int l, int r, int k, int i)
{
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (v[m].first == k && v[m].second != i)
        {
            cout <<  min(i + 1, v[m].second + 1) << ' ' << max(i + 1, v[m].second + 1) << endl;
            return 1;
        }
        else
            if (v[m].first > k)
                r = m;
            else
                l = m;
    }
    return false;
}

int main()
{
    int t, m, n;
    cin >> t;
    vii v;

    while (t--)
    {
        cin >> m >> n;
        int a[n];
        for (int i = 0; i != n; ++i)
        {
            cin >> a[i];
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i != n; ++i)
            if (bsearch(v, 0, n - 1, m - a[i], i))
                break;
        
        v.clear();
    }

    return 0;
}
