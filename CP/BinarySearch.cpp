#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int bsearch(vi &v, int l, int r, int k)
{
    if (r < l)
        return r + 1;
    int m = l + (r - l) / 2;
    if (v[m] == k)
        return m;
    if (v[m] > k)
        return bsearch(v, l, m - 1, k);
    return bsearch(v, m + 1, r, k);
}

int main()
{
    int n, x, k;
    cin >> n >> k;
    vi v;
    for (int i = 0; i != n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << bsearch(v, 0, n - 1, k);

    return 0;
}