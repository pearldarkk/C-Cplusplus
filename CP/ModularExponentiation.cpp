/*  Given three numbers base, exp and m, compute (base^exp) % m. ~ Compute modular power
*/

#include <bits/stdc++.h>
using namespace std;

int modExp(int base, int exp, int m)
{
    int r = 1;
    base = base % m;

    while (exp)
    {
        if (exp & 1)
            r = (r * base) % m;
        exp = exp >> 1;
        base = (base * base) % m;
    }

    return r;
}

int main()
{
    int base, exp, m;
    cin >> base >> exp >> m;
    cout << modExp(base, exp, m) << endl;

    return 0;
}