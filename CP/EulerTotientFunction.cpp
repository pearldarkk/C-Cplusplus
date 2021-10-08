/*The number of positive integers, not greater than x, and relatively prime with x, equals to Euler’s totient function φ (x). 
*/
#include <bits/stdc++.h>
using namespace std;

int phi(int x)
{
    int r = x;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            r -= r / i;
        while (x % i == 0)
            x /= i;
    }

    if (x > 1)
        r -= r / x;
    return r;
}

int main()
{
    int n;
    cin >> n;
    cout << phi(n) << endl;

    return 0;
}