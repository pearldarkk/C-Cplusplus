#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

ll merge(int *a, int l, int m, int r)
{
    ll inv = 0;
    int tmp[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (a[j] < a[i]) inv += m + 1 - i;
        tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    
    for (int i = l; i <= r; ++i)
    a[i] = tmp[i - l];

    return inv;
}

ll sort(int *a, int l, int r)
{
    ll inv = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        inv += sort(a, l, m);
        inv += sort(a, m + 1, r);
        inv += merge(a, l, m, r);
    }
    return inv;
}

int main()
{
    int t;
    cin >> t;

    int n, a[200005];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i != n; ++i)
            cin >> a[i];
        cout << sort(a, 0, n - 1) << endl;
    }

    return 0;
}
