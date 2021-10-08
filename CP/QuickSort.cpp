#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

void qsort(vi &v, int l, int r)
{
    int i = l, j = r;
    int piv = v[(l + r) / 2];

    while (i <= j)
    {
        while (v[i] < piv)
            ++i;
        while (v[j] > piv)
            --j;

        if (i <= j)
        {
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }

    if (l < j)
        qsort(v, l, j);
    if (r > i)
        qsort(v, i, r);
}
int main()
{
    int t;
    cin >> t;

    int n;
    vi v;
    for (int i = 0; i != t; ++i)
    {
        cin >> n;
        v.push_back(n);
    }

    qsort(v, 0, t - 1);

    for (int i = 0; i != t; ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
