#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, b[15][15];
int cnt = 0;

bool safe(int r, int c)
{
    int i, j;

    for (i = 0; i < c; ++i)
        if (b[r][i])
            return false;

    for (i = r, j = c; i >= 0 && j >= 0; --i, --j)
        if (b[i][j])
            return false;

    for (i = r, j = c; i < n && j >= 0; ++i, --j)
        if (b[i][j])
            return false;

    return true;
}

bool queen(int c)
{
    if (c == n)
    {
        ++cnt;
        return true;
    }

    bool res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (safe(i, c))
        {
            b[i][c] = 1;

            res = queen(c + 1) || res;

            b[i][c] = 0;
        }
    }

    return res;
}

void sol()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = 0;

    if (queen(0) == false)
        return;

    return;
}

int main()
{
    cin >> n;
    sol();
    cout << cnt << endl;

    return 0;
}
