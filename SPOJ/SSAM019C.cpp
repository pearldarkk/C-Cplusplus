#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,
    k,
    a[1000];

int count()
{
    int i = k;
    for (; a[i] == n - k + i; --i)
        ;

    if (i == 0)
        return k;
    bool used[1000]{0};
    for (int j = 1; j <= n; ++j)
        used[a[j]] = 1;

    int r = 0;
    if (!used[++a[i]])
        ++r;
    for (int j = i + 1; j <= k; ++j)
    {
        a[j] = a[j - 1] + 1;
        if (!used[a[j]])
            ++r;
    }

    return r;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i)
            cin >> a[i];
        cout << count() << endl;
    }

    return 0;
}
