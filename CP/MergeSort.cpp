#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

void merge(int *a, int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int tmp[r - l + 1];
    while (i <= m && j <= r)
        tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];

    for (int i = l; i <= r; ++i)
        a[i] = tmp[i - l];
}

void sort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i != n; ++i)
        cin >> a[i];

    sort(a, 0, n - 1);

    for (int i = 0; i != n; ++i)
        cout << a[i] << " ";
    Pn;

    return 0;
}
