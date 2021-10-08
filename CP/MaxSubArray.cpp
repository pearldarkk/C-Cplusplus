#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int lmax, rmax;

int maxCrossSum(vi &v, int l, int r)
{
    int lsum = INT_MIN;
    int sum = 0;
    int m = (l + r) / 2;
    for (int i = m; i >= l; --i)
    {
        sum += v[i];
        if (sum > lsum)
        {
            lsum = sum;
            lmax = i;
        }
    }

    int rsum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= r; ++i)
    {
        sum += v[i];
        if (sum > rsum)
        {
            rsum = sum;
            rmax = i;
        }
    }

    return lsum + rsum;
}

int maxsArray(vi &v, int l, int r)
{
    if (l == r)
        return v[l];

    int m = (l + r) / 2;
    int lsum = maxsArray(v, l, m);
    int rsum = maxsArray(v, m + 1, r);
    int crssSum = maxCrossSum(v, l, r);

    return max(lsum, max(rsum, crssSum));
}

int main()
{
    vi v = {823, -28, -349, -932, 48, 23, -4893280, 240, -93, 209, 42, 24, -29, -3, 45, 43, -6, 34, -65, 35, 3, 63, -66, 2, 6, -763, 7, -36, 6, 5, -25, 32, 3, 6, -36, 63};

    cout << maxsArray(v, 0, v.size() - 1) << " " << lmax << " " << rmax << endl;

    return 0;
}
