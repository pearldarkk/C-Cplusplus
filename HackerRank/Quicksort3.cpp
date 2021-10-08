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
    int piv = v[r];
    int i = l;
    for (int j = l; j <= r; ++j)
        if (v[j] < piv)
            swap(&v[i++], &v[j]);
    swap(&v[i], &v[r]);

    return i;
}

void qsort(vi& v, int l, int r)
{
    if (l < r)
    {
        int p = partition(v, l, r);

        for (auto i = v.begin(); i != v.end(); ++i)
            cout << *i << " ";
        Pn;

        qsort(v, l, p - 1);
        qsort(v, p + 1, r);
    }
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

    qsort(v, 0, n - 1);

    return 0;
}
