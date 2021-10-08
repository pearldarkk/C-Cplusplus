#include <bits/stdc++.h>
using namespace std;

int factor(int x)
{
    for (int p = 2; p <= sqrt(x); ++p)
    if (x % p == 0)
    {
        cout << p << " ";
        while (x % p == 0) x /= p;
    }
    if (x > 1) cout << x;
}
int main()
{
    int n;
    cin >> n;
    factor(n);
    cout << endl;
    return 0;
}