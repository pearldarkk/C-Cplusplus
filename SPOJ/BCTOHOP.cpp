#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int p[15],
    n,
    k;

void out()
{
    for (int i = 1; i <= k; ++i)
        cout << p[i] << ' ';
    cout << endl;
}

void gen(int i)
{
    for (int j = p[i - 1] + 1; j <= n - k + i; ++j)
    {
        p[i] = j;
        if (i == k)
            out();
        else
            gen(i + 1);
    }
}

int main()
{
    cin >> n >> k;
    gen(1);

    return 0;
}
