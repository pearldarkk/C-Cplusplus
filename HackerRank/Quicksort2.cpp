#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(vi& v, int l, int r)
{
    int piv = v[l];
    vi v1;

    for (int i = l + 1; i <= r; ++i)
        if (v[i] <= piv)
            v1.push_back(v[i]);
    v1.push_back(v[l]);

    int x = v1.size() - 1 + l;

    for (int i = l + 1; i <= r; ++i)
        if (v[i] > piv)
            v1.push_back(v[i]);

    for (int i = l; i <= r; ++i)
        v[i] = v1[i - l];

    return x;
}

void qsort(vi& v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);
        qsort(v, l, p - 1);
        qsort(v, p + 1, r);

        for (int i = l; i <= r; ++i)
            cout << v[i] << " ";
        Pn;
    }
}
int main()
{
    int n;
    cin >> n;

    vi v;
    int x;
    for (int i = 0; i != n; ++i)
    {
        cin >> x;
        v.push_back(x);
    }

    qsort(v, 0, n - 1);

    return 0;
}
