/*  Pollard Rho's Prime Factorization is for big numbers.
    Start with random x and c. Take y equal to x and f(x) = x2 + c.
    While a divisor isn’t obtained
        Update x to f(x) (modulo n) [Tortoise Move]
        Update y to f(f(y)) (modulo n) [Hare Move]
        Calculate GCD of |x-y| and n
        If GCD is not unity
            If GCD is n, repeat from step 2 with another set of x, y and c
            Else GCD is our answer
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modPow(ll base, int exp, ll mod)
{
    ll r = 1;

    while (exp)
    {
        if (exp & 1)
            r = (r * base) % mod;

        r = (r * r) % mod;
        exp = exp >> 1;
    }

    return r;
}

ll pFact(ll num)
{
    ll r = 1;
    srand(time(NULL));

    if (num == 1)
        return num;

    if (num % 2 == 0)
        return 2;

    ll x, y, c;
    x = rand() % (num - 2) + 2;
    y = x;
    c = rand() % (num - 1) + 1;

    while (r == 1)
    {
        x = (modPow(x, 2, num) + c + num) % num;

        y = (modPow(y, 2, num) + c + num) % num;

        r = __gcd(abs(x - y), num);

        if (r == num)
            return pFact(num);
    }

    return r;
}

int main()
{
    ll n;
    cin >> n;

    cout << pFact(n);
    cout << endl;

    return 0;
}