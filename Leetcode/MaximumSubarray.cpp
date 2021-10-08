#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int maxsArrSum(vi &v)
{
    return div(v, 0, v.size() - 1);
}

int div(vi &v, int l, int r)
{
    if (l == r)
        return v[l];
    int m = (l + r) / 2;
    int lsum = div(v, l, m);
    int rsum = div(v, m + 1, r);
    int crssSum = crss(v, l, r);

    return max(lsum, max(rsum, crssSum));
}

int crss(vi &v, int l, int r)
{
    int m = (l + r) / 2;
    int lsum = INT_MIN;
    int sum = 0;
    for (int i = m; i >= l; --i)
    {
        sum += v[i];
        if (sum > lsum)
            lsum = sum;
    }

    sum = 0;
    int rsum = INT_MIN;
    for (int i = m + 1; i <= r; ++i)
    {
        sum += v[i];
        if (sum > rsum)
            rsum = sum;
    }

    return lsum + rsum;
}

int main()
{
    int n, x;
    cin >> n;
    vi v;
    for (int i = 0; i != n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << maxsArrSum(v);

    return 0;
}
